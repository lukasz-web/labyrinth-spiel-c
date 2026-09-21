## Schritt-für-Schritt-Anleitung für Anfänger

Für das Starten des Spiels sind keine Programmierkenntnisse notwendig. Die folgenden Schritte zeigen, wie das Programm in einem GitHub Codespace gestartet werden kann.

### 1. Repository öffnen

Das GitHub-Repository **labyrinth-spiel-c** öffnen.

Im Repository befinden sich mindestens folgende Dateien:

```text
labyrinth-spiel-c/
├── main.c
└── README.md
```

Die Datei `main.c` enthält den eigentlichen Programmcode.

### 2. Codespace starten

Im GitHub-Repository oben auf **Code** klicken.

Anschliessend:

1. **Codespaces** auswählen.
2. **Create codespace on main** anklicken.
3. Warten, bis sich die Entwicklungsumgebung geöffnet hat.

GitHub öffnet anschliessend eine Entwicklungsumgebung ähnlich wie Visual Studio Code.

### 3. Terminal öffnen

Im Codespace oben im Menü **Terminal** auswählen und anschliessend auf **New Terminal** klicken.

Am unteren Rand des Fensters erscheint nun ein Terminal.

### 4. Programm kompilieren

Folgenden Befehl in das Terminal eingeben:

```bash
gcc main.c -o labyrinth
```

Danach **Enter** drücken.

Mit diesem Befehl wird aus der Datei `main.c` das ausführbare Programm `labyrinth` erstellt.

Wenn keine Fehlermeldung erscheint, wurde das Programm erfolgreich kompiliert.

### 5. Spiel starten

Anschliessend folgenden Befehl eingeben:

```bash
./labyrinth
```

Danach wieder **Enter** drücken.

Das Labyrinth-Spiel wird nun direkt im Terminal gestartet.

### 6. Spieler bewegen

Nach dem Start wird das Spielfeld angezeigt.

Die Steuerung erfolgt mit:

- `W` = Hoch
- `A` = Links
- `S` = Runter
- `D` = Rechts
- `Q` = Spiel beenden

Nach jeder Eingabe muss **Enter** gedrückt werden.

Beispiel:

```text
Eingabe: D
```

Der Spieler versucht dadurch, sich ein Feld nach rechts zu bewegen.

### 7. Ziel des Spiels

Auf dem Spielfeld werden folgende Zeichen verwendet:

- `P` = Spieler
- `T` = Schatz
- `O` = Hindernis
- `.` = freies Feld

Das Ziel besteht darin, den Spieler `P` zum Schatz `T` zu bewegen.

Hindernisse `O` können nicht betreten werden. Auch Bewegungen ausserhalb des Spielfelds werden verhindert.

Sobald der Spieler den Schatz erreicht, wird eine Siegesmeldung ausgegeben und das Spiel beendet.

### 8. Spiel erneut starten

Nach dem Spiel kann es mit folgendem Befehl erneut gestartet werden:

```bash
./labyrinth
```

Bei einem neuen Programmstart werden Spieler, Schatz und Hindernisse erneut zufällig platziert.

### Problem: `./labyrinth: No such file or directory`

Falls diese Meldung erscheint:

```text
bash: ./labyrinth: No such file or directory
```

wurde das Programm noch nicht kompiliert.

Zuerst ausführen:

```bash
gcc main.c -o labyrinth
```

und danach:

```bash
./labyrinth
```
