// Blok2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning(disable:4996)
#include <stdio.h>
#include "blok2.h"

int main()
{
    //uloha2_1_1();
    uloha2_1_2();
    return 0;
}

void uloha2_1_1()
{
    int cisloA, cisloB, sum;
    printf("Zadaj dve cisla:");
    scanf("%d %d", &cisloA, &cisloB);

    printf("\ncisloA = %d cisloB = %d", cisloA, cisloB);

    __asm {                          // zaciatok bloku asm
        MOV EAX, cisloA             // do EAX vloz hodnotu premennej cisloA (z pamate)
        ADD EAX, cisloB
        MOV sum, EAX           // do premennej iVysledok vloz vysledok z registra EAX
    }

    printf("\nsum = %d", sum);
}

void uloha2_1_2()
{
    int cisloA, sucin;
    printf("Zadaj cislo:");
    scanf("%d", &cisloA);
    printf("\ncisloA = %d", cisloA);

    __asm {
        MOV EAX, cisloA;
        SHL EAX, 1;
        MOV sucin, EAX;
    }
    printf("\ncislo %d * 2 = %d",cisloA, sucin);
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu