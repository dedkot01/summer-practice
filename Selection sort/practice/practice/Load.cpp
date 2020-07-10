#define _CRT_SECURE_NO_WARNINGS // для корректной работы scanf()
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <clocale>
#include "Header.h"

void load(int* num)					//загрузка БД из файла
{
    system("cls");
    char Filename[25];
    printf("Для загрузки базы данных из файла введите имя файла с разрешением .txt: ");
    scanf("%s", &Filename);

    if (FILE* r = fopen(Filename, "r+b"))
    {

        for (int i = 0; i < 10; i++)
        {
            fscanf(r, "%d\n", &num[i]);
        }

        fclose(r);

    }
    else
    {
        printf("Данного файла не существует\n");

    }
}