# Musterlösung – Probeklausur 2: Bibliotheksverwaltung

Diese Musterlösung baut auf deiner Originallösung (`../bib.hpp`, `../bib.cpp`,
`../image.png`) auf. Dein Grundgerüst (abstrakte `Media`, abgeleitete Medientypen,
`Member`, Template-`Administration`) wurde übernommen und korrigiert/vervollständigt.

## Dateien

| Datei        | Aufgabe | Inhalt                                                   |
|--------------|---------|----------------------------------------------------------|
| `UML.puml`   | a)      | Korrigiertes UML-Klassendiagramm (PlantUML, renderbar)   |
| `bib.hpp`    | b)      | Deklarationen (Klassen + Template)                       |
| `bib.cpp`    | b)      | Implementierung + Definition der statischen Attribute    |
| `main.cpp`   | c) + e) | `main`-Funktion **und** Wissensfragen als Kommentarblock |

## Kompilieren & Ausführen

```bash
g++ -std=c++17 -Wall -Wextra bib.cpp main.cpp -o bib.exe
./bib.exe
```

Kompiliert ohne Warnungen; die Ausgabe entspricht dem Tabellenformat aus der
Aufgabenstellung (`Yes/No`, `12.5 MB`, `660 min`, `Borrowed By … / None`).

## Was wurde gegenüber deiner Lösung geändert – und warum

| # | Dein Code                                                       | Korrektur in der Musterlösung                                                                                  | Grund |
|---|-----------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------|-------|
| 1 | `int Media::nextid=0;` im Header, vor der Klasse                 | Definition der statischen Attribute in `bib.cpp`                                                               | Im Header verursacht das Mehrfachdefinitionen; vor der Klasse ist `Media` noch unbekannt → kompiliert nicht. |
| 2 | `Member` ohne Konstruktor, `const id`, `nextid` undefiniert      | Konstruktor `Member(name)` mit `id(++nextId)`, statisches `nextId` in `.cpp` definiert, `hasBorrowedItem=false` | `const`-Member **muss** im Konstruktor initialisiert werden; ohne Definition des `static` → Linkerfehler. |
| 3 | `Member` hatte kein `name`                                       | Attribut `name` + `getName()` ergänzt                                                                           | Aufgabe verlangt ausdrücklich ID **+ Name** + Berechtigungen; Beispiel zeigt „Borrowed By Anna Mueller". |
| 4 | `accessRights : vector<string>`, `deleteRights` via `std::replace`| `std::set<string>` mit `insert` / `erase` / `count`                                                            | Aufgabe verlangt einen „geordnet/effizient durchsuchbaren" Container. `std::replace` löschte nicht, sondern setzte `"empty"`. |
| 5 | `rentMedia` → `void`, setzt `activeRent`/`status` nie            | `rentMedia`/`returnMedia` → `bool`, prüfen alle 3 Bedingungen, setzen `available` + `hasBorrowedItem`           | Aufgabe (Hinweis 3) verlangt Prüfung aller Bedingungen **und** Rückmeldung (bool). |
| 6 | `printInfo` gibt Zeiger aus, Format mit Doppelpunkten/`boolalpha`| Format an Beispiel angepasst, „Borrowed By" zeigt `getName()` bzw. `None`; gemeinsamer Teil in `printFooter()` | Muss dem geforderten Tabellenformat entsprechen; `printFooter()` vermeidet Code-Duplizierung (DRY). |
| 7 | `Administration<V,E>` mit **zwei** festen Vektoren              | `Administration<T>` mit **einem** Vektor + `add` / `count` / `findById`                                         | Aufgabe will *eine generische, wiederverwendbare* Verwaltung. Zwei feste Vektoren sind nicht generisch. |
| 8 | `Hearbook` (Tippfehler)                                          | `Audiobook`                                                                                                     | Saubere, sprechende Benennung; Ausgabe heißt ohnehin „Audiobook". |
| 9 | Getter nicht `const`                                            | Alle Getter `const`, Parameter `const&`                                                                         | const-Korrektheit (eigenes Requirement der Aufgabe). |

## UML – wichtigste Korrekturen (Aufgabe a)

- `Member` um `name : string` ergänzt; `accessRights` als `set<string>`.
- `Administration` korrekt als **parametrisierte Klasse** `Administration<T>`
  mit `<<bind>>`-Beziehung zu `Media` bzw. `Member` (statt zwei fest verdrahteter
  Attribute).
- Beziehung `Media ↔ Member` mit Multiplizität `0..1`, Navigierbarkeit
  (Media → Member über `activeCustomer`) und Beziehungsname „borrowed by".
- Statische Attribute (`nextId`) unterstrichen/`{static}`, `id` als `{readOnly}`,
  `printInfo()` `{abstract}`, abfragende Methoden als `{query}` (= `const`).
