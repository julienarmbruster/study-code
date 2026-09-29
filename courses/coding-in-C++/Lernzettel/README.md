# C++ Lernzettel – Programmieren II

Kompakter, prüfungs- und praxisorientierter Lernzettel zum gesamten Stoff der
Vorlesung **Programmieren II (TSA/TSL 25, DHBW Ravensburg, Prof. Dr. Christian
Braunagel)** – zum Lernen und zum Nachschlagen beim Programmieren.

## Inhalt

| Abschnitt | Thema |
|-----------|-------|
| 1 | Schnellübersicht (Cheat-Sheet) |
| 2 | Von C zu C++ |
| 3 | OOP-Grundlagen (Klassen) |
| 4 | UML & Vererbung |
| 5 | UML-Notation ↔ C++ (Spickzettel: Ein-/Ausgabewerte, const/static/virtual) |
| 6 | Polymorphie |
| 7 | Generische Programmierung & STL |
| 8 | Exceptions & Smart Pointer |
| 9 | Code-Design (SOLID, Design Patterns) |
| 10 | Algorithmen & Datenstrukturen (Sortierung, Graphen/Dijkstra) |
| 11 | Tooling & Testing (GoogleTest, CMake) |
| 12 | Coding-Conventions (Kurzreferenz) |

## Aufbau der Dateien

```
Lernzettel.tex        Hauptdokument (Deckblatt + Inhaltsverzeichnis + \input der Module)
preambel.tex          Pakete, farbige Boxen, C++-Syntax-Highlighting
module/               ein .tex pro Abschnitt (00-cheatsheet … 10-konventionen)
bilder/               eingebundene Folien-Screenshots (PNG)
```

Die farbigen Boxen: **Definition** (blau), **Merke/Prüfungstipp** (rot),
**Syntax** (grün), **Beispiel** (orange), **Best Practice/Konvention** (türkis).

## Bauen

Voraussetzung: eine TeX-Distribution (z. B. TeX Live) mit `latexmk` und `pdflatex`.

```powershell
latexmk -pdf Lernzettel.tex      # erzeugt Lernzettel.pdf
latexmk -c                       # Hilfsdateien aufräumen (PDF bleibt)
```

## Screenshots aktualisieren / ergänzen

Die Folien-Screenshots wurden aus den PDFs in `../Scripte/` mit
[poppler](https://poppler.freedesktop.org/) (`pdftoppm`) gerendert, z. B.:

```bash
# Seite 5 aus dem Polymorphie-Foliensatz als PNG (150 dpi) nach bilder/
pdftoppm -png -r 150 -f 5 -l 5 \
  "../Scripte/TSA-TSL25_Programmieren-II_Abschnitt-5_Polymorphie.pdf" \
  bilder/polymorphie_schema
```

Einbinden im Text über den Hilfsbefehl aus `preambel.tex`:
`\folie{0.7}{dateiname}{Bildunterschrift}`.
