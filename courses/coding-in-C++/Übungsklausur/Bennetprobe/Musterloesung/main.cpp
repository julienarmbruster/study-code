#include "bib.hpp"

#include <iostream>
#include <memory>

int main() {
    // -----------------------------------------------------------------
    // Zwei generische Verwaltungsobjekte (eine Template-Klasse, zwei Typen).
    // -----------------------------------------------------------------
    Administration<Media> mediaAdmin;
    Administration<Member> memberAdmin;

    // --- Medien anlegen (je Typ mindestens eines) ---------------------
    auto ebook = std::make_unique<EBook>("Clean Code", "Fachbereich", 12.5);
    auto audiobook = std::make_unique<Audiobook>("Der Hobbit", "Standard", 660);

    // Beobachter-Zeiger merken, BEVOR das Eigentum an die Verwaltung geht.
    Media* ebookPtr = ebook.get();
    Media* audiobookPtr = audiobook.get();

    mediaAdmin.add(std::move(ebook));
    mediaAdmin.add(std::move(audiobook));

    // --- Mitglieder anlegen -------------------------------------------
    auto anna = std::make_unique<Member>("Anna Mueller");
    anna->addRight("Standard");
    anna->addRight("Fachbereich");

    auto ben = std::make_unique<Member>("Ben Klein");
    ben->addRight("Standard"); // KEIN "Fachbereich"

    Member* annaPtr = anna.get();
    Member* benPtr = ben.get();

    memberAdmin.add(std::move(anna));
    memberAdmin.add(std::move(ben));

    std::cout << "Medien in Verwaltung:    " << mediaAdmin.count() << '\n';
    std::cout << "Mitglieder in Verwaltung: " << memberAdmin.count() << "\n\n";

    // -----------------------------------------------------------------
    // Ausleihvorgaenge
    // -----------------------------------------------------------------
    // 1) Erfolg: Anna hat "Fachbereich" und nichts ausgeliehen.
    std::cout << "Anna leiht 'Clean Code': "
              << (annaPtr->rentMedia(ebookPtr) ? "OK" : "FEHLGESCHLAGEN") << '\n';

    // 2) Fehlschlag: Anna hat bereits ein Medium ausgeliehen.
    std::cout << "Anna leiht 'Der Hobbit': "
              << (annaPtr->rentMedia(audiobookPtr) ? "OK" : "FEHLGESCHLAGEN")
              << "  (bereits ein Medium ausgeliehen)" << '\n';

    // 3) Fehlschlag: Ben fehlt die Berechtigung "Fachbereich" fuer das E-Book.
    //    (E-Book ist ohnehin nicht mehr verfuegbar -> Demo per Audiobook waere Erfolg,
    //     daher zeigen wir den Berechtigungsfall an einem verfuegbaren Medium.)
    std::cout << "Ben leiht 'Der Hobbit':  "
              << (benPtr->rentMedia(audiobookPtr) ? "OK" : "FEHLGESCHLAGEN") << '\n';
    // Ben darf "Der Hobbit" (Standard) leihen -> Erfolg. Fuer einen Berechtigungs-
    // Fehlschlag muesste ein Fachbereich-Medium verfuegbar sein; das demonstrieren
    // wir, indem Anna 'Clean Code' zurueckgibt und Ben es dann nicht leihen darf:
    annaPtr->returnMedia(ebookPtr);
    std::cout << "Ben leiht 'Clean Code':  "
              << (benPtr->rentMedia(ebookPtr) ? "OK" : "FEHLGESCHLAGEN")
              << "  (keine Berechtigung 'Fachbereich')" << '\n';

    std::cout << "\n--------------------------------------------------\n";

    // -----------------------------------------------------------------
    // Ausgabe aller Medien ueber Basisklassenzeiger (Polymorphie).
    // -----------------------------------------------------------------
    for (const std::unique_ptr<Media>& media : mediaAdmin.getAll()) {
        media->printInfo();
    }

    return 0;
}

/* =====================================================================
   e) Wissensfragen
   =====================================================================

   1. Wie wird sichergestellt, dass die korrekte virtuelle Funktion
      ueberschrieben wird?
      In der Basisklasse wird die Methode mit dem Schluesselwort 'virtual'
      deklariert, in der abgeleiteten Klasse wird sie mit 'override' markiert
      (z. B. EBook::printInfo() const override). 'override' laesst den Compiler
      pruefen, ob in der Basisklasse wirklich eine passende virtuelle Methode
      mit identischer Signatur existiert; ein Tippfehler oder eine abweichende
      const-Qualifizierung fuehrt dann zu einem Compilerfehler statt zu einer
      versehentlich neuen (verdeckenden) Funktion.

   2. Unterschied std::unique_ptr vs. std::shared_ptr?
      - unique_ptr: alleiniges (exklusives) Eigentum, nicht kopierbar, nur
        verschiebbar (move). Kein Overhead durch Referenzzaehlung.
      - shared_ptr: geteiltes Eigentum mit Referenzzaehler; das Objekt wird
        erst zerstoert, wenn der letzte shared_ptr verschwindet (etwas mehr
        Overhead, thread-sichere Zaehlung).
      Fuer den Verwaltungs-Vector waehle ich unique_ptr: Die Verwaltung ist die
      eindeutige Eigentuemerin der Medien. Andere Stellen (z. B. activeCustomer)
      halten nur nicht-besitzende Beobachter-Zeiger, also wird kein geteiltes
      Eigentum benoetigt. unique_ptr ist damit das schlankere, klarere Werkzeug.

   3. Was ist eine abstrakte Klasse?
      Eine Klasse mit mindestens einer rein virtuellen Methode. In C++ wird eine
      rein virtuelle Methode durch '= 0' deklariert:
          virtual void printInfo() const = 0;
      Von einer abstrakten Klasse kann kein Objekt instanziiert werden, weil
      mindestens eine Methode keine Implementierung besitzt - es waere also nicht
      definiert, was bei ihrem Aufruf geschehen soll. Sie dient nur als
      gemeinsame Schnittstelle/Basis (hier: Media).

   4. Warum muss der Destruktor der Basisklasse virtuell sein?
      Wird ein abgeleitetes Objekt ueber einen Basisklassenzeiger geloescht
      (delete basePtr bzw. beim Aufraeumen eines unique_ptr<Media>) und ist der
      Destruktor NICHT virtuell, so wird nur ~Media() aufgerufen, nicht aber
      ~EBook()/~Audiobook(). Folge: undefiniertes Verhalten und ggf.
      Ressourcen-/Speicherlecks, weil die abgeleiteten Teile nicht korrekt
      freigegeben werden. Ein virtueller Destruktor stellt sicher, dass die
      gesamte Zerstoerungskette korrekt durchlaufen wird.

   5. Welchen Vorteil bieten Templates?
      Typunabhaengiger, wiederverwendbarer Code ohne Duplizierung und mit voller
      Typsicherheit (Pruefung zur Compilezeit). Konkretes Beispiel:
      Administration<T> verwaltet mit demselben Code sowohl
      Administration<Media> als auch Administration<Member>; ohne Template
      muesste pro Typ eine eigene Verwaltungsklasse geschrieben werden.

   6. RAII-Prinzip und Smart Pointer?
      RAII (Resource Acquisition Is Initialization): Eine Ressource wird im
      Konstruktor eines Objekts belegt und im Destruktor automatisch wieder
      freigegeben. Die Lebensdauer der Ressource ist damit an die Lebensdauer
      des Objekts (Scope) gekoppelt. Smart Pointer setzen genau das um: Ein
      unique_ptr/shared_ptr besitzt den dynamischen Speicher und ruft beim
      Verlassen des Gueltigkeitsbereichs automatisch delete auf - es ist kein
      manuelles delete noetig, und auch bei Exceptions wird der Speicher
      zuverlaessig freigegeben.
   ===================================================================== */
