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
* Dateiname: main.c
*
* Projekt  : Muster
* Hardware : Mocca-Board, ATmega2560v von Atmel
*
* Copyright: MSW, E2
*
* Beschreibung:
* =============
* Siehe Prüfungsaufgabe
*
* Portbelegung:
* =============
* Siehe Hardwarestruktur
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

//Definition des Eingangsports
#define SCHALTER    PINK
//Definition des Ausgangsports
#define LED         PORTA
//Initialisierung des Ausgangsports
#define INIT_LED    (DDRA = 0xFF)


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
uint8_t invertiereLeds (uint8_t zuInvertierendeBits)
{
    LED = LED ^ zuInvertierendeBits;
    return LED;
}


/* Hauptprogramm *****************************************************************/
int main (void)
{
    uint8_t variable;
    
    INIT_LED;
    
    //Endlosschlaufe
    while (1)
    {
        
    }                               // end while
}                                   // end main
