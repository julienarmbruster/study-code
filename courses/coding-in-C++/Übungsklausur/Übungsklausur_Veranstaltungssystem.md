# Übungsklausur – Veranstaltungs- und Buchungssystem

Prof. Dr. Christian Braunagel (Übungsklausur zur Vorbereitung)

Bearbeitungszeit: 2h

Typ: Einzelarbeit

> **Hinweis:** Diese Übungsklausur prüft dieselben Kompetenzen wie die Probeklausur *Flottenmanagementsystem* (abstrakte Klasse, Polymorphie, statisches Attribut, STL-Container, Datenkapselung, Vektor-Iteration), modelliert die Logik aber **bewusst anders**: Statt einer 1:1-Zuweisung mit Berechtigungs-Abgleich geht es hier um eine **1:n-Beziehung** (eine Veranstaltung hat viele Teilnehmer), um **Kapazitäts-/Buchungsregeln** und um das **Aggregieren von Werten über Schleifen** (summieren, zählen, suchen). Sie ist außerdem **etwas ausführlicher** (eine zusätzliche Verwaltungs-Klasse). Den konkreten Lernfokus findest du am Ende des Dokuments.

## 1. Problemstellung

Ein Kulturzentrum möchte seine Veranstaltungen und Buchungen digital verwalten. Dafür soll ein objektorientiertes Softwaresystem in C++ entwickelt werden.

Das Zentrum bietet unterschiedliche Veranstaltungstypen an:

- Konzerte
- Workshops

Alle Veranstaltungen besitzen gemeinsame Eigenschaften:

- eine eindeutige Veranstaltungs-ID
- einen Titel
- eine maximale Teilnehmerzahl (Kapazität)
- einen Basispreis pro Ticket
- die Liste der momentan gebuchten Teilnehmer

Ein Konzert speichert zusätzlich den auftretenden Künstler. Bei einem Workshop interessiert insbesondere der Name des Kursleiters sowie die Dauer in Stunden. Neu erstellte Veranstaltungen sollen zu Beginn keine gebuchten Teilnehmer haben.

Der **endgültige Ticketpreis** wird je Veranstaltungstyp **unterschiedlich** berechnet (Polymorphie):

- Konzert: `Basispreis * 1.5` (Aufschlag für Live-Auftritt)
- Workshop: `Basispreis + (Dauer in Stunden * 10.0)` (Materialpauschale pro Stunde)

Zu jedem Objekt eines Veranstaltungstyps lassen sich mit der Funktion `printInfo()` alle Attribute in einer Tabelle mit zwei senkrecht ausgerichteten Spalten auf dem Terminal ausgeben.

Zwei Ausgabebeispiele für ein Objekt vom Typ "Konzert" und "Workshop" sehen wie folgt aus:

```text
Type             Concert
Title            Rock Night 2026
Artist           The Killers
Capacity         3
Booked           2
Free Seats       1
Ticket Price     45.00
Sold Out         No
```

```text
Type             Workshop
Title            Intro to C++
Instructor       Dr. Braunagel
Duration         4 h
Capacity         10
Booked           10
Free Seats       0
Ticket Price     70.00
Sold Out         Yes
```

Auch die Daten der Mitglieder (Besucher) werden über die Software verwaltet. Ein Mitglied hat eine ID, einen Namen und eine Liste seiner Interessensgebiete (z.B. `Musik`, `Technik`, `Kunst`). Die ID soll nur einmalig gesetzt werden können und muss eindeutig über alle Mitglieder hinweg sein. Da sich die Interessensgebiete ändern können, soll ein passender Container aus der Standard-Bibliothek verwendet werden, der geordnet oder durchsucht werden kann. Es sollen Methoden vorhanden sein, um neue Interessensgebiete für ein Mitglied anzulegen oder bestehende zu löschen.

Ein Mitglied kann für mehrere Veranstaltungen gebucht werden, **aber maximal für drei gleichzeitig**. Eine Buchung eines Mitglieds für eine Veranstaltung ist nur möglich, wenn

- die Veranstaltung noch nicht ausgebucht ist (freie Plätze vorhanden sind),
- das Mitglied für diese Veranstaltung noch **nicht** gebucht ist (keine Doppelbuchung) und
- das Mitglied sein Buchungslimit von drei Veranstaltungen noch nicht erreicht hat.

### Die Verwaltungs-Klasse `EventManager`

Zusätzlich soll eine Klasse `EventManager` das gesamte Programm verwalten. Sie hält **alle Veranstaltungen** und **alle Mitglieder** in jeweils einem eigenen Container und bietet Methoden, um die Daten auszuwerten, **ohne dass die main-Funktion selbst über die Container iterieren muss**. Insbesondere soll sie über die Veranstaltungen iterieren, um **Kennzahlen zu berechnen** (z.B. Gesamtzahl gebuchter Plätze, Anzahl ausgebuchter Veranstaltungen, Gesamtumsatz).

**Wichtig:** Methoden der Klasse `EventManager`, die die Container nur **auswerten und nicht verändern** (ausgeben, zählen, summieren, suchen), müssen `const`-Methoden sein. Überlege dir genau, welche Getter-Methoden der Veranstaltungen und Mitglieder dadurch ebenfalls `const` sein müssen, damit der Zugriff auf die Werte **in der Schleife** funktioniert.

### Weitere Requirements:

- Verwenden Sie mindestens eine abstrakte Klasse und ein statisches Attribut.
- Orientieren Sie sich am Prinzip der Datenkapselung und implementieren Sie die nötigen Getter & Setter Methoden.
- Stellen Sie sicher, dass Ihr Code wiederverwendbar und erweiterbar ist.

## 2. Abgabeumfang

Folgende Aufgaben müssen bearbeitet werden:

### a)

Erstellen Sie ein UML-Klassendiagramm, das als Basis für das geplante Softwaresystem dient und die oben beschriebenen Anforderungen erfüllt.

Darzustellen sind:

- Alle Attribute und Methoden
- Sichtbarkeiten
- Datentypen
- Zusätzliche Eigenschaften bei konstanten, statischen, abgeleiteten, eindeutigen, virtuellen, usw. Methoden/Attributen/Parametern
- Parameterrichtungen
- Klassenbeziehungen mit Navigierbarkeit, Multiplizität und Beziehungsnamen (achten Sie hier besonders auf die **1:n-Beziehung** zwischen Veranstaltung und Mitgliedern sowie auf die Beziehung des `EventManager` zu Veranstaltungen und Mitgliedern)

**Hinweis:** Um Zeit bei Ihrem Diagramm zu sparen, genügt es pro Klasse jeweils nur eine Getter- und Setter-Methode darzustellen.

### b)

Implementieren Sie nun das Softwaresystem für die oben beschriebene Veranstaltungsverwaltung in C++. Folgen Sie dabei der Coding Convention für C++ aus der Vorlesung.

**Wichtig:** Orientieren Sie sich an Ihrem zuvor erstellten Klassendiagramm. D.h. der Code sollte alle Spezifikationen Ihres Klassendiagramms erfüllen.

Erweitern Sie den Code auch um alle technischen Details, die typischerweise nicht in Klassendiagrammen abgebildet werden, aber aus der Aufgabenbeschreibung hervorgehen und für die korrekte Umsetzung der Software notwendig sind.

Achten Sie insbesondere auf:

- die **typabhängige** Berechnung des Ticketpreises (rein virtuelle Methode in der Basisklasse, überschrieben in den abgeleiteten Klassen),
- die Buchungslogik (Kapazität, Doppelbuchung, Buchungslimit) – hier müssen Sie u.a. **über die bereits gebuchten Teilnehmer iterieren**, um eine Doppelbuchung zu erkennen.

**Hinweis 1:** Hierbei müssen nun alle relevanten Getter- & Setter-Methoden implementiert werden.

**Hinweis 2:** Sie müssen KEINE Funktions-Header, wie in den Coding Conventions gefordert, dokumentieren.

### c)

Implementieren Sie die Verwaltungs-Klasse `EventManager` mit mindestens den folgenden Methoden. Achten Sie genau auf die `const`-Korrektheit:

1. `void addEvent(...)` und `void addMember(...)` – fügt eine Veranstaltung bzw. ein Mitglied hinzu.
2. `void printAllEvents() const` – iteriert über den Veranstaltungs-Container und gibt **jede Veranstaltung über einen Basisklassenzeiger** mit `printInfo()` aus.
3. `int countSoldOutEvents() const` – iteriert über die Veranstaltungen und zählt, wie viele bereits ausgebucht sind.
4. `int totalBookedSeats() const` – iteriert über alle Veranstaltungen und **summiert** die Anzahl der jeweils gebuchten Teilnehmer.
5. `double totalRevenue() const` – iteriert über alle Veranstaltungen und summiert `gebuchte Teilnehmer * Ticketpreis` (nutzt die polymorphe Preisberechnung).
6. `Event* findEventById(int id) const` – iteriert über die Veranstaltungen und gibt die passende zurück (oder `nullptr`, wenn keine gefunden wurde).

**Hinweis:** Die Methoden 2–6 verändern den Zustand des `EventManager`-Objekts nicht und müssen daher `const` sein. Damit Sie innerhalb dieser `const`-Methoden auf die Werte der Veranstaltungen und Mitglieder zugreifen können (z.B. `is_sold_out()`, `get_booked_count()`, `calculate_ticket_price()`), müssen die entsprechenden Getter/Methoden ebenfalls `const` deklariert sein.

### d)

Erzeugen Sie für jeden Veranstaltungstyp ein Objekt sowie mindestens zwei Mitglieder in Ihrer main-Funktion.

- Legen Sie ein `EventManager`-Objekt an.
- Fügen Sie alle Veranstaltungen und alle Mitglieder dem `EventManager` hinzu (die Container liegen also **innerhalb** der `EventManager`-Klasse, nicht in `main`).
- Buchen Sie mindestens ein Mitglied für mindestens eine Veranstaltung. Lösen Sie dabei bewusst auch einen Fehlerfall aus (z.B. Doppelbuchung oder ausgebuchte Veranstaltung) und zeigen Sie, dass die Buchung korrekt abgelehnt wird.
- Geben Sie anschließend über die `EventManager`-Methoden alle Veranstaltungen (über einen Basisklassenzeiger) aus.
- Geben Sie außerdem die berechneten Kennzahlen aus (Anzahl ausgebuchter Veranstaltungen, Gesamtzahl gebuchter Plätze, Gesamtumsatz) und suchen Sie eine Veranstaltung über ihre ID.

### e)

Das Programm muss erfolgreich/fehlerfrei auf Ihrer Prüfungsmaschine kompilierbar sein.

### f)

Beantworten Sie die folgenden Fragen direkt in Ihrem Code (als Kommentar):

1. Wie können Sie bei polymorphen Klassen sicherstellen, dass die korrekte virtuelle Funktion überschrieben wird?
2. Warum müssen die Getter-Methoden `const` sein, damit Sie sie innerhalb einer `const`-Methode von `EventManager` (z.B. `totalRevenue() const`) bzw. über eine `const`-Referenz auf ein Vector-Element aufrufen können? Was meldet der Compiler, wenn eine dort benötigte Methode **nicht** `const` ist?
3. Was ist der Unterschied zwischen `for (Member m : members)` und `for (const Member& m : members)`, wenn Sie über den Mitglieder-Vector iterieren? Welche Variante ist hier zu bevorzugen und warum?

---

## Lernfokus (nicht Teil der eigentlichen Klausur)

Diese Übungsklausur trainiert gezielt die Tipps des Profs. Wenn du sie löst, achte besonders auf:

### 1. Durchiterieren von Vektoren und Zugriff auf Klassen-Werte

Hier iterierst du nicht nur, um auszugeben, sondern um **Werte aufzusummieren / zu zählen** – das ist der Kern dieser Klausur:

```cpp
// (a) Summieren über einen Vector von Zeigern (Polymorphie -> Pfeil-Operator)
double EventManager::totalRevenue() const
{
    double revenue = 0.0;
    for (Event* event : events)                         // event ist ein Zeiger
    {
        revenue += event->get_booked_count()            // -> weil Zeiger
                 * event->calculate_ticket_price();      // polymorpher Aufruf
    }
    return revenue;
}

// (b) Zählen mit einer Bedingung
int EventManager::countSoldOutEvents() const
{
    int count = 0;
    for (const Event* event : events)
    {
        if (event->is_sold_out())                        // const-Methode!
        {
            count++;
        }
    }
    return count;
}

// (c) Iteration über einen Vector von OBJEKTEN (Punkt-Operator) zur Duplikatsuche
bool Event::is_member_booked(const Member& member) const
{
    for (const Member* participant : participants)       // hier ggf. Zeiger
    {
        if (participant->get_id() == member.get_id())    // const-Getter
        {
            return true;
        }
    }
    return false;
}
```

**Merke:** Bei einem Vector von **Objekten** (`std::vector<Member>`) greifst du mit `.` auf Member zu; bei einem Vector von **Zeigern** (`std::vector<Event*>`) brauchst du den Pfeil-Operator `->`. Bei `std::size()`/Index-Zugriff zusätzlich `events[i]->...`.

### 2. `const`-Getter vs. nicht-`const`-Getter – und was passiert

Das ist der Kernpunkt. Stell dir diese Situation vor:

```cpp
class Member
{
private:
    std::string name;
public:
    std::string get_name();                  // NICHT const
    const std::string& get_name_c() const;   // const
};

void EventManager::printAllMembers() const   // <-- const-Methode!
{
    for (const Member& member : members)      // <-- const-Referenz!
    {
        std::cout << member.get_name();       // FEHLER, wenn get_name() nicht const ist
        std::cout << member.get_name_c();     // OK, weil const
    }
}
```

Frage an dich selbst beim Üben:
- **Warum** schlägt `member.get_name()` fehl, wenn `member` eine `const`-Referenz ist?
  (Antwort: Auf einem `const`-Objekt darfst du nur Methoden aufrufen, die `const` sind – sonst könnte die Methode das Objekt verändern.)
- Wie lautet die typische **Compiler-Fehlermeldung**?
  (Sinngemäß: *"passing 'const Member' as 'this' argument discards qualifiers"* bzw. bei MSVC *"cannot convert 'this' pointer from 'const Member' to 'Member &'"*.)
- An welchen Stellen entstehen `const`-Objekte/-Referenzen "automatisch"?
  (z.B. in einer `const`-Methode, bei `const T&`-Parametern wie `is_member_booked(const Member&)`, bei `for (const auto& x : container)`.)

### 3. Selbstcheck-Fragen

- Welche Getter/Methoden müssen in deinem Code zwingend `const` sein, damit `totalRevenue() const`, `countSoldOutEvents() const` und `findEventById(...) const` kompilieren?
- Was passiert, wenn du in einer `const`-Methode versehentlich einen **Setter** (z.B. `book_member(...)`) aufrufst?
- Warum sollten `printInfo()` und `calculate_ticket_price()` `virtual` (mit `override` in den abgeleiteten Klassen) **und** `const` sein?
- Was wäre der Unterschied, wenn `EventManager` die Veranstaltungen als `std::vector<Event>` (Objekte) statt `std::vector<Event*>` (Zeiger) hielte? (Stichwort: *Object Slicing* und Polymorphie – die typabhängige Preisberechnung würde dann nicht mehr funktionieren.)

### Verwendete Konzepte (Abgleich mit den Labs/Skripten)

- Abstrakte Klasse + rein virtuelle Methode (`= 0`), `virtual`/`override`, virtueller Destruktor → Abschnitt 5 (Polymorphie), Lab 6
- Statisches Attribut für die ID-Vergabe → Abschnitt 3 (OOP), Lab 3
- `std::set` für die Interessensgebiete (geordnet/durchsuchbar, add/remove) → Abschnitt 6 (STL), Lab 5
- `std::vector` + Iteration über Basisklassenzeiger + **Aggregation (summieren/zählen)** → Abschnitt 6 (STL), Probeklausur Aufgabe c)
- Datenkapselung, Getter/Setter, `const`-Korrektheit → Coding Conventions §19, §21
