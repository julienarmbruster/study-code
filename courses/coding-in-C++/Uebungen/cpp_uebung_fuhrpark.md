# C++ Übung: Fuhrpark-Verwaltung

Eine kompakte Aufgabe, die **Smart Pointer**, **Komposition**, **Aggregation** und **`std::vector` mit `<algorithm>`** in einem zusammenhängenden Beispiel übt.

## Lernziele

Nach dieser Übung kannst du:

- ein Objekt per **Komposition** besitzen (`std::unique_ptr`, Lebensdauer gekoppelt)
- ein Objekt per **Aggregation** nur beobachten (Roh-Pointer, kein Eigentum)
- einen `std::vector` mit Algorithmen aus `<algorithm>` sortieren, zählen und durchsuchen

## Szenario

Du verwaltest einen Fuhrpark:

- Ein **`Motor`** hat eine Leistung in PS. Er ist **Teil** eines Autos und existiert nicht ohne Auto → **Komposition**.
- Ein **`Fahrer`** hat einen Namen. Er lebt eigenständig; ein Auto *kennt* seinen Fahrer nur, **besitzt** ihn aber nicht → **Aggregation**.
- Ein **`Auto`** hat eine Marke, besitzt genau einen Motor und kennt höchstens einen Fahrer (oder keinen).
- Der **`Fuhrpark`** hält mehrere Autos in einem `std::vector`.

## Aufgaben

### Teil A — Klassen & Beziehungen

1. Schreibe die Klasse `Motor` mit einem Attribut `leistungPS` (int) und einer Methode `getPS()`.
2. Schreibe die Klasse `Fahrer` mit einem Attribut `name` (string) und `getName()`.
3. Schreibe die Klasse `Auto`:
   - Attribut `marke` (string)
   - **Komposition:** Member `std::unique_ptr<Motor> motor`
   - **Aggregation:** Member `const Fahrer* fahrer` (darf `nullptr` sein)
   - Konstruktor, der Marke + PS bekommt und den Motor selbst erzeugt (`std::make_unique`)
   - Methode `setFahrer(const Fahrer* f)`
   - Methoden `getMarke()`, `getPS()` (fragt den Motor), `getFahrerName()` (gibt `"keiner"` zurück, falls kein Fahrer gesetzt)

### Teil B — Fuhrpark mit `vector`

4. Lege in `main` einen `std::vector<std::unique_ptr<Auto>>` an und füge die vier Autos aus der Tabelle unten hinzu.
5. Lege die beiden Fahrer als eigenständige Objekte an (sie müssen **länger leben** als die Autos, die auf sie zeigen!) und weise sie zu.

| Marke         | PS  | Fahrer |
|---------------|-----|--------|
| VW Golf       | 110 | Anna   |
| Tesla Model 3 | 283 | Ben    |
| Fiat 500      | 70  | —      |
| BMW M3        | 480 | Anna   |

### Teil C — `<algorithm>`

6. **Sortieren:** Sortiere den Vektor mit `std::sort` nach PS *absteigend* (Lambda als Vergleichsfunktion).
7. **Zählen:** Zähle mit `std::count_if`, wie viele Autos mehr als 100 PS haben.
8. **Suchen:** Finde mit `std::find_if` das erste Auto der Marke `"Fiat 500"` und gib dessen Fahrer aus.
9. **Ausgeben:** Gib mit `std::for_each` (oder einer range-based for) alle Autos sortiert aus.

## Erwartete Ausgabe

```
Fuhrpark (sortiert nach PS):
  BMW M3        | 480 PS | Fahrer: Anna
  Tesla Model 3 | 283 PS | Fahrer: Ben
  VW Golf       | 110 PS | Fahrer: Anna
  Fiat 500      |  70 PS | Fahrer: keiner

Autos mit > 100 PS: 3
Gesucht 'Fiat 500': gefunden, Fahrer = keiner
```

## Code-Gerüst

Fülle die `// TODO`-Stellen aus. Versuch es erst selbst, bevor du nach unten zu den Hinweisen schaust.

```cpp
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>

class Motor {
    int leistungPS;
public:
    explicit Motor(int ps) : leistungPS(ps) {}
    int getPS() const { return leistungPS; }
};

class Fahrer {
    std::string name;
public:
    explicit Fahrer(std::string n) : name(std::move(n)) {}
    const std::string& getName() const { return name; }
};

class Auto {
    std::string marke;
    std::unique_ptr<Motor> motor;   // Komposition: Auto besitzt den Motor
    const Fahrer* fahrer = nullptr; // Aggregation: Auto kennt den Fahrer nur

public:
    Auto(std::string m, int ps)
        : marke(std::move(m)), motor(std::make_unique<Motor>(ps)) {}

    void setFahrer(const Fahrer* f) { fahrer = f; }

    const std::string& getMarke() const { return marke; }
    int getPS() const { /* TODO: über den Motor */ }
    std::string getFahrerName() const {
        // TODO: "keiner" zurückgeben, wenn fahrer == nullptr,
        //       sonst fahrer->getName()
    }
};

int main() {
    // Fahrer leben eigenständig und MÜSSEN die Autos überleben
    Fahrer anna("Anna");
    Fahrer ben("Ben");

    std::vector<std::unique_ptr<Auto>> fuhrpark;
    // TODO: vier Autos per make_unique hinzufügen (push_back / emplace_back)
    //       und Fahrer zuweisen

    // TODO 6: std::sort nach PS absteigend (Lambda)

    // TODO 7: std::count_if -> Autos mit > 100 PS

    // TODO 8: std::find_if -> erstes Auto Marke "Fiat 500"

    // TODO 9: Ausgabe aller Autos
}
```

## Hinweise (erst nach eigenem Versuch lesen)

- **`push_back` eines `unique_ptr`:** Ein `unique_ptr` ist nicht kopierbar. Nutze `fuhrpark.push_back(std::make_unique<Auto>("VW Golf", 110));`.
- **Zugriff im Vektor:** Die Elemente sind `unique_ptr<Auto>`. Du musst also doppelt „durch": `auto->getPS()` wird zu `element->getPS()`, wobei `element` schon der `unique_ptr` ist und `->` an das `Auto` dahinter durchreicht.
- **`std::sort`-Lambda:** Die Signatur ist `[](const auto& a, const auto& b){ return a->getPS() > b->getPS(); }`. Das `>` macht es absteigend.
- **`std::count_if`:** `std::count_if(fuhrpark.begin(), fuhrpark.end(), [](const auto& a){ return a->getPS() > 100; });`
- **`std::find_if`:** Gibt einen Iterator zurück. Vergleiche das Ergebnis mit `.end()`, um zu prüfen, ob etwas gefunden wurde, bevor du dereferenzierst.
- **Lebensdauer-Falle (Aggregation!):** `anna` und `ben` müssen **vor** dem `fuhrpark` deklariert werden bzw. ihn überleben. Werden sie früher zerstört, zeigen die Auto-Pointer ins Leere (dangling pointer). Genau das ist der Unterschied zur Komposition: den Motor musst du nie selbst am Leben halten, den Fahrer schon.

## Bonus

- Ändere `fahrer` von `const Fahrer*` auf `std::shared_ptr<Fahrer>`. Wann wäre das sinnvoll, wann nicht? (Tipp: nur wenn das Auto den Fahrer *mitbesitzen* soll – hier eigentlich nicht.)
- Füge dem `Motor` einen Destruktor mit `std::cout` hinzu und beobachte, wann er aufgerufen wird, wenn ein Auto aus dem Vektor entfernt wird.
