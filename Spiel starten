# Labyrinth-Spiel in C

Praxisarbeit im Modul **Programmiertechnik A & B**.

## Beschreibung

Dieses Projekt ist ein textbasiertes Labyrinth-Spiel, das in der Programmiersprache **C** entwickelt wurde.

Das Spiel besteht aus einem **10 × 10 grossen Spielfeld**. Zu Beginn werden der Spieler, ein Schatz und zehn Hindernisse zufällig auf freien Feldern platziert.

Ziel des Spiels ist es, den Schatz zu erreichen, ohne auf ein Hindernis zu laufen oder das Spielfeld zu verlassen.

## Spielfeld

Für die Darstellung werden folgende Zeichen verwendet:

- `P` = Spieler
- `T` = Schatz
- `O` = Hindernis
- `.` = freies Feld

## Steuerung

Der Spieler wird über die Tastatur gesteuert:

- `W` = Hoch
- `A` = Links
- `S` = Runter
- `D` = Rechts
- `Q` = Spiel beenden

Auch Kleinbuchstaben werden erkannt.

## Funktionen

Das Programm beinhaltet unter anderem:

- zufällige Platzierung von Spieler, Schatz und Hindernissen
- Verhinderung von Überschneidungen bei der Platzierung
- Prüfung der Spielfeldgrenzen
- Erkennung von Hindernissen
- Überprüfung der Siegbedingung
- Verarbeitung ungültiger Eingaben
- manuelles Beenden des Spiels

## Kompilieren

Das Programm kann mit GCC kompiliert werden:

```bash
gcc main.c -o labyrinth
```

## Starten

Nach dem Kompilieren wird das Spiel mit folgendem Befehl gestartet:

```bash
./labyrinth
```

## Projektstruktur

```text
labyrinth-spiel-c/
├── main.c
└── README.md
```

`main.c` enthält den vollständigen Quellcode des Labyrinth-Spiels.

## Technische Umsetzung

Das Spielfeld wird als zweidimensionales `char`-Array umgesetzt. Die Positionen des Spielers und des Schatzes werden mit der selbst definierten Struktur `Position` gespeichert.

Der Programmcode ist in mehrere Funktionen aufgeteilt, darunter:

- `initializeLabyrinth()` – initialisiert das Spielfeld
- `printLabyrinth()` – gibt das Spielfeld aus
- `getRandomFreePosition()` – ermittelt eine zufällige freie Position
- `placeGameObjects()` – platziert Spieler, Schatz und Hindernisse
- `isValidMove()` – überprüft eine Bewegung
- `movePlayer()` – bewegt den Spieler
- `hasPlayerWon()` – überprüft die Siegbedingung

## Hinweis

Die Positionen der Spielobjekte werden bei jedem Programmstart zufällig bestimmt. Das Programm stellt sicher, dass sich Spieler, Schatz und Hindernisse bei der Platzierung nicht überschneiden.

Eine Überprüfung, ob der Schatz bei jeder zufälligen Anordnung tatsächlich erreichbar ist, ist in der aktuellen Version nicht implementiert.

## Autor

**Lukas Zumwald**

Praxisarbeit – Programmiertechnik A & B
