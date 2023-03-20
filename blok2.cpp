// Blok2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include "blok2.h"

int main()
{
    //uloha2_1_1();
    //uloha2_1_2();
    //while (1)
    //{
    //    uloha2_1_3();
    //}
    uloha2_1_4();
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

void uloha2_1_3()
{
    unsigned int cislo, vystup;
    do
    {
        printf("\nZadaj cislo v intervale<0,15>: ");
        scanf("%d", &cislo);
    } while(cislo < 0 || cislo > 15);
    //printf("%d", cislo);
    
    __asm {
        MOV EAX, cislo;
        CMP EAX, 9;
        JG vacsie;
        ADD EAX, 48;
        JMP koniec;
    vacsie: 
        ADD EAX, 55;

    koniec:
        MOV vystup, EAX;
    }

    printf("vstup: %d, vystup: %c (%d)", cislo, vystup, vystup);
}

void uloha2_1_4()
{
    int vendorString[12] = { 0 };
    __asm {
        MOV EAX, 0;
        CPUID;
        //MOV obsahEBX, EBX;
        MOV vendorString[0], EBX;
        MOV vendorString[4], EDX;
        MOV vendorString[8], ECX;
    }
    printf("%s\n", vendorString);
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu