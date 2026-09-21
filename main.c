/*
 * Bibliotheken
 * Diese Bibliotheken stellen Funktionen für Ein-/Ausgabe,
 * Zufallszahlen, Zeitfunktionen und Zeichenverarbeitung bereit.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/*
 * Konstanten
 * Definieren die Grösse des Spielfeldes und die Anzahl Hindernisse.
 */
#define ROWS 10
#define COLS 10
#define OBSTACLE_COUNT 10

/*
 * Spielfeldsymbole
 * Legen fest, wie die Objekte im Labyrinth dargestellt werden.
 */
#define EMPTY '.'
#define PLAYER 'P'
#define TREASURE 'T'
#define OBSTACLE 'O'

/*
 * Datenstruktur Position
 * Speichert die Zeile und Spalte eines Objekts im Labyrinth.
 */
typedef struct {
    int row;
    int col;
} Position;

/*
 * Füllt das Labyrinth mit leeren Feldern.
 * Dadurch wird das Grundspielfeld erstellt,
 * bevor Spieler, Schatz und Hindernisse platziert werden.
 */
void initializeLabyrinth(char labyrinth[ROWS][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            labyrinth[row][col] = EMPTY;
        }
    }
}

/*
 * Gibt das aktuelle Labyrinth auf der Konsole aus.
 * Diese Funktion dient nur der Darstellung und
 * verändert die Spiellogik nicht.
 */
void printLabyrinth(char labyrinth[ROWS][COLS]) {
    printf("\n   ");

    for (int col = 0; col < COLS; col++) {
        printf("%d ", col);
    }

    printf("\n");

    for (int row = 0; row < ROWS; row++) {
        printf("%d  ", row);

        for (int col = 0; col < COLS; col++) {
            printf("%c ", labyrinth[row][col]);
        }

        printf("\n");
    }

    printf("\n");
}

/*
 * Ermittelt eine zufällige freie Position im Labyrinth.
 * Frei bedeutet, dass das Feld aktuell leer ist.
 */
Position getRandomFreePosition(char labyrinth[ROWS][COLS]) {
    Position position;

    do {
        position.row = rand() % ROWS;
        position.col = rand() % COLS;
    } while (labyrinth[position.row][position.col] != EMPTY);

    return position;
}

/*
 * Platziert den Spieler, den Schatz und die Hindernisse
 * an zufälligen Positionen.
 * Dabei wird sichergestellt, dass sich keine Objekte überlappen.
 */
void placeGameObjects(char labyrinth[ROWS][COLS], Position *playerPosition, Position *treasurePosition) {
    *playerPosition = getRandomFreePosition(labyrinth);
    labyrinth[playerPosition->row][playerPosition->col] = PLAYER;

    *treasurePosition = getRandomFreePosition(labyrinth);
    labyrinth[treasurePosition->row][treasurePosition->col] = TREASURE;

    for (int i = 0; i < OBSTACLE_COUNT; i++) {
        Position obstaclePosition = getRandomFreePosition(labyrinth);
        labyrinth[obstaclePosition.row][obstaclePosition.col] = OBSTACLE;
    }
}

/*
 * Prüft, ob eine Bewegung gültig ist.
 * Der Spieler darf das Spielfeld nicht verlassen
 * und nicht auf ein Hindernis laufen.
 */
int isValidMove(char labyrinth[ROWS][COLS], int newRow, int newCol) {
    if (newRow < 0 || newRow >= ROWS || newCol < 0 || newCol >= COLS) {
        return 0;
    }

    if (labyrinth[newRow][newCol] == OBSTACLE) {
        return 0;
    }

    return 1;
}

/*
 * Bewegt den Spieler entsprechend der Benutzereingabe.
 * W = hoch, A = links, S = runter, D = rechts.
 */
int movePlayer(char labyrinth[ROWS][COLS], Position *playerPosition, char input) {
    int newRow = playerPosition->row;
    int newCol = playerPosition->col;

    input = toupper(input);

    if (input == 'W') {
        newRow--;
    } else if (input == 'A') {
        newCol--;
    } else if (input == 'S') {
        newRow++;
    } else if (input == 'D') {
        newCol++;
    } else {
        return 0;
    }

    if (!isValidMove(labyrinth, newRow, newCol)) {
        return 0;
    }

    labyrinth[playerPosition->row][playerPosition->col] = EMPTY;

    playerPosition->row = newRow;
    playerPosition->col = newCol;

    labyrinth[playerPosition->row][playerPosition->col] = PLAYER;

    return 1;
}

/*
 * Prüft, ob der Spieler den Schatz erreicht hat.
 * Das Spiel ist gewonnen, wenn Spieler und Schatz
 * dieselbe Position besitzen.
 */
int hasPlayerWon(Position playerPosition, Position treasurePosition) {
    return playerPosition.row == treasurePosition.row &&
           playerPosition.col == treasurePosition.col;
}

/*
 * Hauptfunktion des Programms.
 * Initialisiert das Spiel, verarbeitet die Benutzereingaben
 * und steuert die Spielschleife.
 */
int main(void) {
    char labyrinth[ROWS][COLS];
    Position playerPosition;
    Position treasurePosition;
    char input;
    int gameRunning = 1;

    srand(time(NULL));

    initializeLabyrinth(labyrinth);
    placeGameObjects(labyrinth, &playerPosition, &treasurePosition);

    printf("Labyrinth-Spiel\n");
    printf("Steuerung: W = hoch, A = links, S = runter, D = rechts, Q = beenden\n");

    while (gameRunning) {
        printLabyrinth(labyrinth);

        printf("Eingabe: ");
        scanf(" %c", &input);

        input = toupper(input);
        if (input == 'Q') {
            printf("Spiel wurde beendet.\n");
            gameRunning = 0;
        } else {
            int moved = movePlayer(labyrinth, &playerPosition, input);
            if (!moved) {
                printf("Ungültige Bewegung.\n");
            }
            if (hasPlayerWon(playerPosition, treasurePosition)) {
                printLabyrinth(labyrinth);
                printf("Glueckwunsch! Du hast den Schatz gefunden.\n");
                gameRunning = 0;
            }
        }
    }
    return 0;
}
