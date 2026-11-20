# C-Programmierrichtlinien (MSW / AE2)

Diese Richtlinie beschreibt die Konventionen für die Programmierung in C (ANSI C-Standard) an der Mechatronik Schule Winterthur (Abteilung AE2). 

Konventionen sind Regeln, an die sich Entwickler halten, um die Softwarequalität bezüglich **Lesbarkeit, Überprüfbarkeit, Zuverlässigkeit, Wartbarkeit, Erweiterbarkeit und Wiederverwendbarkeit** nachhaltig zu steigern.

---

## 1. Grundprinzipien

* **Prinzip der integrierten Dokumentation:** Die Dokumentation ist direkt in den Kommentaren im Quellcode enthalten.
* **Prinzip der Verbalisierung:** Alle Namen werden so gewählt, dass sie ihre Funktion und Bedeutung klar preisgeben.

---

## 2. Formatierung & Code-Layout

### 2.1 Einrückung und Tabulatoren
* **Keine Tabulatoren (`\t`) verwenden!** Es dürfen ausschließlich Leerzeichen genutzt werden.
* Eine Einrückungsebene entspricht genau **4 Leerzeichen**.

```c
void beispielFunktion(void)
{
    // 4 Leerzeichen Einrückung
    uint8_t zaehler = 0;
}
```

### 2.2 Maximale Zeilenlänge
* Pro Zeile stehen **maximal 83 Zeichen**. Dies garantiert gute Lesbarkeit auf allen Bildschirmen und in Code-Reviews.

```c
// Gute Aufteilung bei langen Zeilen / Kommentaren:
Anweisungen; // Kommentare können auch rechts vom Code und auf der
             // nächsten Zeile fortgesetzt werden, falls der Platz nicht reicht.
```

### 2.3 Geschwungene Klammern `{}`
* Geschwungene Klammern stehen **immer auf einer separaten Zeile** und werden nicht an die Anweisung angehängt.

```c
// Richtig:
if (bedeutung == 1)
{
    anweisung();
}

// Falsch:
// if (bedeutung == 1) {
//     anweisung();
// }
```

### 2.4 Leerzeichen um Operatoren
* Vor und nach jedem Operator (Zuweisungen, Vergleiche, arithmetische Operatoren) steht ein Leerzeichen.

```c
// Richtig:
for (uint16_t i = 0; i < 4; i++)
{
    resultat = messwert + 10;
}

// Falsch:
// for(uint16_t i=0;i<4;i++){ resultat=messwert+10; }
```

---

## 3. Namenskonventionen

### 3.1 Variablen und Funktionen (`lowerCamelCase`)
* Namen beginnen immer mit einem **Kleinbuchstaben**.
* Zusammengesetzte Wörter werden durch Großbuchstaben getrennt (*lowerCamelCase*).

```c
// Variable
uint8_t zustand;
uint16_t messwertSpeicher;

// Funktion
uint8_t invertiereLeds(uint8_t zuInvertierendeBits);
```

### 3.2 Konstanten und Makros (`UPPER_SNAKE_CASE`)
* Namen von Konstanten und `#define`-Makros werden durchgehend in **Grossbuchstaben** geschrieben.
* Zusammengesetzte Wörter werden mit einem Unterstrich `_` getrennt.

```c
#define IN_SCHALTER  PINK
#define OUT_LED      PORTA

#define MAX_BUFFER_SIZE  128
```

### 3.3 Eigene Datentypen (`typedef`)
* Selbst definierte Datentypen (z. B. `enum`, `struct`) erhalten das Suffix `_t`, um sofort als Typ erkennbar zu sein.

```c
// Definition eines Enumerated Types (enum)
typedef enum tag_t {
    MONTAG, 
    DIENSTAG, 
    MITTWOCH, 
    DONNERSTAG,
    FREITAG, 
    SAMSTAG, 
    SONNTAG
} tag_t;

// Verwendung des Typs
tag_t heute = DIENSTAG;
```

---

## 4. Standardisierte Datentypen

Um die Portierbarkeit auf verschiedene Mikrocontroller und Systeme zu gewährleisten, werden ausschließlich standardisierte Datentypen aus `<stdint.h>` sowie für Wahrheitswerte aus `<stdbool.h>` verwendet (keine ungenauen Basistypen wie `int` oder `long`).

| Standard-Typ | Header | Beschreibung | Wertebereich / Werte |
| ----- | ----- | ----- | ----- |
| `bool` | `<stdbool.h>` | Wahrheitswert | `true` oder `false` |
| `int8_t` | `<stdint.h>` | 8-Bit vorzeichenbehaftet | -128 bis 127 |
| `uint8_t` | `<stdint.h>` | 8-Bit vorzeichenlos | 0 bis 255 |
| `int16_t` | `<stdint.h>` | 16-Bit vorzeichenbehaftet | -32'768 bis 32'767 |
| `uint16_t` | `<stdint.h>` | 16-Bit vorzeichenlos | 0 bis 65'535 |
| `int32_t` | `<stdint.h>` | 32-Bit vorzeichenbehaftet | -2'147'483'648 bis 2'147'483'647 |
| `uint32_t` | `<stdint.h>` | 32-Bit vorzeichenlos | 0 bis 4'294'967'295 |
| `int64_t` | `<stdint.h>` | 64-Bit vorzeichenbehaftet | -9'223'372'036'854'775'808 bis 9'223'372'036'854'775'807 |
| `uint64_t` | `<stdint.h>` | 64-Bit vorzeichenlos | 0 bis 18'446'744'073'709'551'615 |

```c
#include <stdint.h>
#include <stdbool.h>

uint8_t  index;        // 8-Bit vorzeichenlos
int8_t   temperatur;   // 8-Bit vorzeichenbehaftet
uint16_t messwert;     // 16-Bit vorzeichenlos
uint32_t resultat;     // 32-Bit vorzeichenlos
uint64_t zeitstempel;  // 64-Bit vorzeichenlos
int64_t  grosserWert;  // 64-Bit vorzeichenbehaftet

bool     istEingeschaltet = true;  // Wahrheitswert (true/false)
bool     hatFehler        = false;
```

---

## 5. Dokumentation & Kommentare

### 5.1 Funktionskommentare
Jede Funktion muss mit einem standardisierten Kommentarblock eingeleitet werden, der die Funktion, ihre Parameter und den Rückgabewert beschreibt.

```c
/*********************************************************************************\
* invertiereLeds
*
* Kurzbeschreibung der Funktion (in Stichworten, kein Aufsatz):
* Invertiert die gewünschten Bits an den LEDs.
*
* Parameter:
* zuInvertierendeBits = Bits, die hier auf 1 sind, werden an den LEDs invertiert.
*
* Rückgabewert: Der neu angezeigte Wert wird zurückgegeben.
*
\*********************************************************************************/
uint8_t invertiereLeds(uint8_t zuInvertierendeBits)
{
    LED = LED ^ zuInvertierendeBits;
    return LED;
}
```

### 5.2 Zeilen- und Blockkommentare
* Einzeilige Kommentare werden mit `//` eingeleitet.
* Kommentare rechts vom Code beginnen eingerückt auf fixer Höhe oder direkt nach der Anweisung.

```c
// Definition des Eingangsports
#define SCHALTER PINK

uint8_t zustand = 0; // Initialisierung des Systemzustands
```

### 5.3 Ende-Markierungen von Blöcken
* Das Ende von längeren Schleifen oder Hauptfunktionen wird mit einem kurzen Kommentar markiert (z. B. `// end while`, `// end main`).

```c
while (1)
{
    // Anweisungen...
} // end while
```

---

## 6. Kontrollstrukturen

### 6.1 `if` / `else`-Verzweigungen

```c
if (resultat > 0)
{
    anweisungA();
}
else
{
    anweisungB();
}
```

### 6.2 `for`-Schleifen

```c
for (uint16_t i = 0; i < 4; i++)
{
    verarbeiteDaten(i);
}
```

### 6.3 `switch` / `case`-Anweisungen
* `case`-Label stehen eingerückt im `switch`-Block, die Anweisungen darunter werden nochmals eingerückt.

```c
switch (i)
{
    case 1:
        anweisungEins();
        break;

    case 2:
        anweisungZwei();
        break;

    default:
        anweisungDefault();
        break;
}
```

---

## 7. Aufbau von Header-Dateien (`.h`)

Header-Dateien verhindern Mehrfach-Inkludierungen über Include-Guards (`#ifndef`, `#define`, `#endif`) und folgen einer festen Sektionsstruktur.

```c
#ifndef RICHTLINIEN_H /* Abfrage, ob Name schon definiert wurde */
#define RICHTLINIEN_H /* Definiere den Namen */

/*--- #includes -----------------------------------------------------------------*/
#include <stdint.h>

/*--- #define-Konstanten und Makros ---------------------------------------------*/
#define BUFFER_SIZE 64

/*--- Datentypen (typedef) ------------------------------------------------------*/
typedef enum status_t {
    OK,
    FEHLER
} status_t;

/*--- Globale Konstanten (extern) -----------------------------------------------*/

/*--- Globale Variablen (extern) ------------------------------------------------*/

/*--- Prototypen globaler Funktionen --------------------------------------------*/
void invertiereAlleLeds(void);
uint8_t invertiereLeds(uint8_t zuInvertierendeBits);

#endif /* RICHTLINIEN_H */
```
