# Übung: Vektoren als Klassenattribute iterieren

## Lernziel

Du übst, Vektoren als Attribute in Klassen zu speichern und auf verschiedene Arten zu iterieren:
index-basiert, range-based for, und mit Iteratoren.

---

## Aufgabe 1 – Einfache Bibliothek

Erstelle eine Klasse `Bibliothek`, die eine Liste von Buchtiteln (`std::vector<std::string>`) als Attribut hält.

**Anforderungen:**

- Methode `buchHinzufuegen(std::string titel)` — fügt einen Titel in den Vektor ein
- Methode `alleBuecherAusgeben()` — gibt alle Titel nummeriert aus (index-basierte Schleife)
- Methode `sucheNachTitel(std::string suchbegriff)` — gibt aus, ob ein Titel gefunden wurde (range-based for)

**Erwartete Ausgabe (Beispiel):**

```
1. Der Prozess
2. Die Verwandlung
3. Faust
Suche nach "Faust": gefunden
Suche nach "Hamlet": nicht gefunden
```

---

## Aufgabe 2 – Notenverwaltung

Erstelle eine Klasse `Kurs`, die einen Kursnamen und eine Liste von Noten (`std::vector<double>`) speichert.

**Anforderungen:**

- Methode `noteHinzufuegen(double note)`
- Methode `durchschnittBerechnen()` — iteriert mit einem Iterator (`begin()`/`end()`) über den Vektor und gibt den Durchschnitt zurück
- Methode `besteNote()` — gibt die niedrigste (beste) Note zurück
- Methode `notenAusgeben()` — gibt alle Noten aus

**Erwartete Ausgabe (Beispiel):**

```
Kurs: Programmierung
Noten: 1.3  2.0  1.7  3.0
Durchschnitt: 2.0
Beste Note: 1.3
```

---

## Aufgabe 3 – Klasse mit Vektor von Objekten *(Erweiterung)*

Erstelle zwei Klassen: `Student` (Name + Matrikelnummer) und `Seminar` (hält `std::vector<Student>`).

**Anforderungen:**

- Methode `studentAnmelden(Student s)` — fügt einen Studenten hinzu
- Methode `teilnehmerlisteAusgeben()` — gibt alle Studenten aus (range-based for über Vektor von Objekten)
- Methode `anzahlTeilnehmer()` — gibt die Größe des Vektors zurück

**Erwartete Ausgabe (Beispiel):**

```
Seminar: Algorithmen
Teilnehmer (3):
  - Anna Müller (Mat.-Nr.: 12345)
  - Ben Schmidt (Mat.-Nr.: 67890)
  - Clara Weber (Mat.-Nr.: 11111)
```

---

## Hinweise

| Schleifenart | Syntax | Wann benutzen |
|---|---|---|
| Index-basiert | `for (int i = 0; i < v.size(); ++i)` | Wenn du den Index brauchst |
| Range-based for | `for (const auto& x : v)` | Einfaches Durchlaufen, kein Index nötig |
| Iterator | `for (auto it = v.begin(); it != v.end(); ++it)` | Wenn du `it` manipulieren willst |

- `const auto&` beim range-based for vermeidet unnötige Kopien
- `v.size()` gibt einen `size_t` (unsigned) zurück — beim Vergleich mit `int` kann es Warnungen geben, besser `size_t i` oder `int i` mit Cast verwenden

---

## Musterlösung (erst nach eigenem Versuch anschauen)

<details>
<summary>Aufgabe 1 – Bibliothek</summary>

```cpp
#include <iostream>
#include <vector>
#include <string>

class Bibliothek {
private:
    std::vector<std::string> buecher;

public:
    void buchHinzufuegen(std::string titel) {
        buecher.push_back(titel);
    }

    void alleBuecherAusgeben() {
        for (int i = 0; i < static_cast<int>(buecher.size()); ++i) {
            std::cout << (i + 1) << ". " << buecher[i] << "\n";
        }
    }

    void sucheNachTitel(std::string suchbegriff) {
        for (const auto& titel : buecher) {
            if (titel == suchbegriff) {
                std::cout << "Suche nach \"" << suchbegriff << "\": gefunden\n";
                return;
            }
        }
        std::cout << "Suche nach \"" << suchbegriff << "\": nicht gefunden\n";
    }
};

int main() {
    Bibliothek bib;
    bib.buchHinzufuegen("Der Prozess");
    bib.buchHinzufuegen("Die Verwandlung");
    bib.buchHinzufuegen("Faust");

    bib.alleBuecherAusgeben();
    bib.sucheNachTitel("Faust");
    bib.sucheNachTitel("Hamlet");
}
```

</details>

<details>
<summary>Aufgabe 2 – Notenverwaltung</summary>

```cpp
#include <iostream>
#include <vector>
#include <string>

class Kurs {
private:
    std::string name;
    std::vector<double> noten;

public:
    Kurs(std::string n) : name(n) {}

    void noteHinzufuegen(double note) {
        noten.push_back(note);
    }

    double durchschnittBerechnen() {
        double summe = 0.0;
        for (auto it = noten.begin(); it != noten.end(); ++it) {
            summe += *it;
        }
        return summe / noten.size();
    }

    double besteNote() {
        double beste = noten[0];
        for (auto it = noten.begin(); it != noten.end(); ++it) {
            if (*it < beste) beste = *it;
        }
        return beste;
    }

    void notenAusgeben() {
        std::cout << "Kurs: " << name << "\nNoten: ";
        for (const auto& n : noten) {
            std::cout << n << "  ";
        }
        std::cout << "\nDurchschnitt: " << durchschnittBerechnen();
        std::cout << "\nBeste Note: " << besteNote() << "\n";
    }
};

int main() {
    Kurs k("Programmierung");
    k.noteHinzufuegen(1.3);
    k.noteHinzufuegen(2.0);
    k.noteHinzufuegen(1.7);
    k.noteHinzufuegen(3.0);
    k.notenAusgeben();
}
```

</details>

<details>
<summary>Aufgabe 3 – Seminar mit Studenten</summary>

```cpp
#include <iostream>
#include <vector>
#include <string>

struct Student {
    std::string name;
    int matNr;
};

class Seminar {
private:
    std::string titel;
    std::vector<Student> teilnehmer;

public:
    Seminar(std::string t) : titel(t) {}

    void studentAnmelden(Student s) {
        teilnehmer.push_back(s);
    }

    void teilnehmerlisteAusgeben() {
        std::cout << "Seminar: " << titel << "\n";
        std::cout << "Teilnehmer (" << anzahlTeilnehmer() << "):\n";
        for (const auto& s : teilnehmer) {
            std::cout << "  - " << s.name << " (Mat.-Nr.: " << s.matNr << ")\n";
        }
    }

    int anzahlTeilnehmer() {
        return static_cast<int>(teilnehmer.size());
    }
};

int main() {
    Seminar sem("Algorithmen");
    sem.studentAnmelden({"Anna Müller", 12345});
    sem.studentAnmelden({"Ben Schmidt", 67890});
    sem.studentAnmelden({"Clara Weber", 11111});
    sem.teilnehmerlisteAusgeben();
}
```

</details>
