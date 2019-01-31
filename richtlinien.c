/*********************************************************************************\
*
* MMMMMMMMMMMMMMMMMM   SSSSSSSSSSSSSSSSSS   WWWW   WWWW   WWWW
* MMMMMMMMMMMMMMMMMM   SSSSSSSSSSSSSSSSSS   WWWW   WWWW   WWWW   MECHATRONIK
* MMMMMMMMMMMMMMMMMM   SSSSS                WWWW   WWWW   WWWW
* MMMM   MMMM   MMMM   SSSSSSSSSSSSSSSSSS   WWWW   WWWW   WWWW   SCHULE
* MMMM   MMMM   MMMM   SSSSSSSSSSSSSSSSSS   WWWW   WWWW   WWWW
* MMMM   MMMM   MMMM                SSSSS   WWWWWWWWWWWWWWWWWW   WINTERTHUR
* MMMM   MMMM   MMMM   SSSSSSSSSSSSSSSSSS   WWWWWWWWWWWWWWWWWW
* MMMM   MMMM   MMMM   SSSSSSSSSSSSSSSSSS   WWWWWWWWWWWWWWWWWW   www.msw.ch
*
*
* Dateiname: richtlinien.c
*
* Projekt  : cRichtlinien
* Hardware : Mocca-Board, ATmega2560v von Atmel
*
*
* Copyright: MSW, AE2
*
* Beschreibung:
* =============
* Diese Datei zeigt den prinzipiellen Aufbau einer .C-Datei, der den
* C-Programmier-Regeln der msw-winterthur, Abteilung AE2 genügt.
*
* Die Syntax der Programmiersprache C lässt dem Entwickler sehr viel Spielraum in
* Bezug auf die Schreibweise von Programmen. Diese Richtlinie beschreibt
* Konventionen für die Programmierung in der Programmiersprache C, entsprechend dem
* ANSI C-Standard. Konventionen sind Regeln, an die sich der Programmierer
* freiwillig hält, deren Einhaltung aber nicht vom Compiler erzwungen wird. Die
* verwendung der Regeln soll dazu beitragen, die Qualität neu erstellter Software
* hinsichtlich der Kriterien
*  - Lesbarkeit,
*  - Überprüfbarkeit,
*  - Zuverlässigkeit,
*  - Wartbarkeit,
*  - Erweiterbarkeit und
*  - Wiederverwendbarkeit
* zu erhöhen.
*
* Mit den nachfolgend festgelegten Regeln sollen folgende Prinzipien umgesetzt
* werden:
*  - Prinzip der integrierten Dokumentation
*    (Die Dokumentation ist direkt in den Kommentaren im Code enthalten)
*  - Prinzip der Verbalisierung
*    (Alle Namen werden so gewählt, dass sie ihre Funktion preisgeben)
*
* ==========================Hier die wichtigsten Regeln==========================
*                                                                               |
* - Es werden KEINE Tabulatoren verwendet, sondern nur Leerzeichen. Eine        |
*   Enrückung entspricht 4 Leerzeichen.                                         |
*                                                                               |
* - Namen beginnen immer mit einem Kleinbuchstaben. Zusammengesetzte Wörter     |
*   werden durch Grossbuchstaben getrennt. Z. B. : diesIstEinVariabelname oder  |
*   diesIstEinFunktionsname                                                     |
*                                                                               |
* - Namen von Konstanten und Definitionen, also Werte die nicht verändert       |
*   werden können, werden in Grossbuchstaben geschrieben. Zusammengesetzte      |
*   Wörter werden mit "_" getrennt. Z. B. : ICH_BIN_EINE_KONSTANTE              |
*                                                                               |
* - Um die Portierbarkeit zu erhöhen werden ausschliesslich Standardisierte     |
*   Datentypen aus stdint.h verwendet. Z. B. : uint8_t oder uint16_t            |
*   Siehe auch:                                                                 |
*   https://de.wikibooks.org/wiki/C-Programmierung_mit_AVR-GCC/_Datentypen      |
*                                                                               |
* - Auf einer Zeile stehen maximal 83 Zeichen.                                  |
*                                                                               |
* - Geschwungene Klammern, "{" oder "}" stehen auf einer separaten Zeile.       |
*                                                                               |
* ===============================================================================
*
* Portbelegung:
* =============
* Eingänge
* PORTK.0 nicht belegt
* PORTK.1 nicht belegt
* PORTK.2 nicht belegt
* PORTK.3 nicht belegt
* PORTK.4 nicht belegt
* PORTK.5 nicht belegt
* PORTK.6 nicht belegt
* PORTK.7 nicht belegt
*
* Ausgänge
* PORTA.0 nicht belegt
* PORTA.1 nicht belegt
* PORTA.2 nicht belegt
* PORTA.3 nicht belegt
* PORTA.4 nicht belegt
* PORTA.5 nicht belegt
* PORTA.6 nicht belegt
*
* Verlauf:
* ========
* Datum:      Autor:         Version   Grund der Änderung:
* dd.mm.yyyy  M. Muster      V1.0      Neuerstellung
*
\*********************************************************************************/

//Standardisierte Datentypen
#include <stdint.h>
//ATmega2560v I/O-Definitionen
#include <avr/io.h>

//Kommentare dürfen als Block wie hier festgelegt werden:
//Definition des Eingangsports
#define SCHALTER    PINK
//Definition des Ausgangsports
#define LED         PORTA
//Initialisierung des Ausgangsports
#define INIT_LED    (DDRA = 0xFF)

//Definition einer globalen Variabel
uint8_t zustand = 0;

/*********************************************************************************\
* invertiereLeds
*
* Kurzbeschreibung, was die Funktion macht (mehr in Stichworten, kein Aufsatz!).
* Für diese Funktion würde die Beschreibung etwa so lauten:
* Invertiert die Gewünschten Bits an den LEDs.
*
* Parameter:
* zuInvertierendeBits = Bits die hier auf 1 sind, werden an den LEDs invertiert.
*
* Rückgabewert: Der neu angezeigte Wert wird zurückgegeben.
*
\*********************************************************************************/
uint8_t invertiereLeds(uint8_t zuInvertierendeBits)
{
    LED = LED ^ zuInvertierendeBits;
    return LED;
}

/*********************************************************************************\
* invertiereAlleLeds
*
* Invertiert alle LEDs.
*
\*********************************************************************************/
void invertiereAlleLeds(void)
{
    LED = ~LED;
}

/* Hauptprogramm *****************************************************************/
int main(void)
{
    //Es werden nur Standardisierte Datentypen verwendet, mehr dazu im Fileheader.
    uint8_t i;
    //Temperatur in milli Grad Celsius
    int8_t temperatur;
    //Zwischenspeicher für Messwerte
    uint16_t messwert;
    //Berechnungen werden hier abgespeichert
    uint32_t resultat;
    
    //Port LED auf Ausgang initialisieren
    INIT_LED;
    
    //Endlosschlaufe
    while(1)
    {
        Anweisungen;                //Kommentare können auch rechts vom Code
        Anweisungen;                //..geschrieben und und auf der
        Anweisungen;                //..nächsten Zeile vortgesetzt werden, falls
        Anweisungen;                //.. der Platz nicht reicht.
        Anweisungen;                //Pro Zeile stehen maximal 83 Zeichen.
        
        if (resultat > 0)           //Vor und nach jedem Operator steht ein Abstand
        {                           //Geschwungene Klammern stehen auf eigenen 
            Anweisungen;            //..Zeilen alles was innerhalb geschwungener 
        }                           //..Klammern steht, wird eingerückt.
        else
        {
            Anweisungen;
        }
        
        //So sieht der Kopf einer For-Schlaufe aus
        for (i = 0; i < 4; i ++)
        {
            Anweisungen;
        }
        
        //So werden Switch-Statements formatiert
        switch (i)
        {
            //1: die entsprechenden Anweisungen werden in diesem case ausgeführt
            case 1:
            //Anweisungen werden eingerückt
            Anweisungen;
            break;
            case 2:
            Anweisungen;
            break;
            default:
            Anweisungen;
        }
        
    }                               // end while
}                                   // end main
