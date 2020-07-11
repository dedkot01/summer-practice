#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <clocale>
#include "Header.h"

void Savefile(int* num, int size) {

    char FileName[20];
    if (*num == NULL)
    {
        printf("Не удалось сохранить массив");
        system("pause");
        return;

    }
    printf("Пожалуйста введите имя файла с разрешением .txt: ");
    scanf("%s", &FileName);
    FILE* f = fopen(FileName, "w");
    for (int i = 0; i < size; i++)
    {
        fprintf(f, "%d\n", num[i]);
    }
    fclose(f);

}
