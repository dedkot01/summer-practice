#define _CRT_SECURE_NO_WARNINGS // для корректной работы scanf()
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <clocale>
#include "Header.h"

int *load(char *p)					//загрузка массива из файла
{
    int* a = nullptr;
    int size;
    char Filename[25];
    int v = 0;
    for (int i = 0; i < 25; i++) {
        Filename[i] = p[i];
    }
    if (FILE* r = fopen(Filename, "r+b"))
    {
        fscanf(r, "%d\n", &size);
        v = 1;
        a = (int*)malloc(size * sizeof(int));
        for (int i = 0; i < size; i++)
        {
            fscanf(r, "%d\n", &a[i]);
        }

        fclose(r);

    }
 
    else
    {
        printf("Данного файла не существует\n");
        return 0;
    }

    return a;
}




int loadsize(char *p){
    char Filename[25];
    int size;
    for (int i = 0; i < 25; i++) {
        Filename[i] = p[i];
    }
    if (FILE* r = fopen(Filename, "r+b"))
    {
        fscanf(r, "%d\n", &size);
        fclose(r);

    }

    else
    {
        printf("Данного файла не существует\n");
        return 0;
    }
    return size;
}