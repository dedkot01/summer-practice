#define _CRT_SECURE_NO_WARNINGS // ��� ���������� ������ scanf()
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <clocale>
#include "Header.h"

void load(int* num)					//�������� �� �� �����
{
    system("cls");
    char Filename[25];
    printf("��� �������� ���� ������ �� ����� ������� ��� ����� � ����������� .txt: ");
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
        printf("������� ����� �� ����������\n");

    }
}