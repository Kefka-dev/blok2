// Blok2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include "blok2.h"

const unsigned char BottomLeftCorner = 200;
const unsigned char BottomRightCorner = 188;
const unsigned char TopRightCorner = 187; 
const unsigned char TopLeftCorner = 201; 
const unsigned char HorizontalLine = 205;
const unsigned char VerticalLine = 186;
const unsigned char Tshape = 203;
const unsigned char TshapeUP = 202;
const unsigned char TshapeRight = 204;
const unsigned char TshapeLeft = 185;
const unsigned char Cross = 206;

#define YELLOW 14
#define GREEN 10
#define MAX_DLZKA_MENA 50
#define DLZKA_TELC 15
#define LEFT_COL 11
#define ROWS 10
#define BORDERS 3
#define WHITE_SPACE 2
#define TRUE 1
#define FALSE 0
int main()
{
    //uloha2_1_1();
    //uloha2_1_2();
    //while (1)
    //{
       //uloha2_1_3();
    //}
    //uloha2_1_4();
    //uloha2_5_1();
    uloha2_5_2();
    return 0;
}

void uloha2_1_1()//1b
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

void uloha2_1_2()//1b
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

void uloha2_1_3()//3b
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

void uloha2_1_4()//2b
{
    int vendorString[4] = { 0 };
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

//grafika
void uloha2_5_1()//1b
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int farba = 1;
    for (int i = 0; i < 51; i++)
    {
        if (i % 5 == 0)
        {
            SetConsoleTextAttribute(hConsole,farba);
            farba++;
        }
        printf("%03d\n", i);
        Sleep(1000);
    }
}

void uloha2_5_2()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    int x, y;
    int vyska = 150, hmotnost= 80;
    int rightColWidth, nameLen;
    char menoPriezvisko[MAX_DLZKA_MENA] = "frantisek stromokocur";
    char telC[DLZKA_TELC] = "0969 / 123 123";

    printf("\nZadaj surednice na ktorych sa zobrazi tabulka:");
    scanf("%d %d", &x, &y);

    COORD point = { x, y };
    SetConsoleCursorPosition(hConsole, point);
    
    
    nameLen = strlen(menoPriezvisko);

    if (nameLen > DLZKA_TELC)
    {
        rightColWidth = nameLen;
    }
    else
    {
        rightColWidth = DLZKA_TELC;
    }
    
    genTable(rightColWidth, &x,&y);

    printf("x = %d y = %d", x, y);
    //printf("%d", rightColWidth);
    //test znakov
    //printf("%c %c %c %c %c %c %c %c %c %c %c", TopLeftCorner, TopRightCorner, BottomLeftCorner, BottomRightCorner, HorizontalLine, VerticalLine, Tshape,TshapeUP,TshapeLeft,TshapeRight,Cross);

}

void genTable(int rightWidth, int* p_posX, int* p_posY) 
{
    tableHead(rightWidth, p_posX, p_posY);

}

void tableHead(int rightWidth, int* p_posX, int* p_posY)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD point = {*p_posX, *p_posY};
    
    SetConsoleTextAttribute(hConsole, YELLOW);
    printf("%c%c", TopLeftCorner, HorizontalLine);
    
    SetConsoleTextAttribute(hConsole, GREEN);
    printf("Zaznam 000");
    
    SetConsoleTextAttribute(hConsole, YELLOW);
    printf("%c", HorizontalLine);

    for (int i = 0; i < rightWidth; i++)
    {
        printf("%c", HorizontalLine);
    }

    printf("%c", TopRightCorner);
    point.Y++;
    (*p_posY)++;
    SetConsoleCursorPosition(hConsole, point);
    
    printf("%c", TshapeRight);
    for (int i = 0; i < (LEFT_COL + rightWidth); i++)
    {
        printf("%c", HorizontalLine);
        if (i == LEFT_COL)
        {
            printf("%c", Tshape);
        }
    }
    printf("%c", TshapeLeft);
}

//void tableData(int rightWidth, int posX)
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu