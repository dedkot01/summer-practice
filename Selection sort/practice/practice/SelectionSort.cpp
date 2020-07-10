#define _CRT_SECURE_NO_WARNINGS // ��� ���������� ������ scanf()
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <clocale>
#include "Header.h"
// ������� ���������� ������ �������

void print(int* num, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", num[i]);
}

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
    printf("����� ����������, ������� ����� ������ ���������� ");
    system("pause");
}

void Savefile(int* num) {

    char FileName[20];
    if (*num == NULL)
    {
        printf("�� ������� ��������� ������");
        system("pause");
        return;

    }
    printf("���������� ������� ��� ����� � ����������� .txt: ");
    scanf("%s", &FileName);
    FILE* f = fopen(FileName, "w");
    for (int i = 0; i < 10; i++)
    {
        fprintf(f, "%d\n", num[i]);
    }
    fclose(f);
    printf("����� ����������, ������� ����� ������ ����������  ");
    system("pause");

}

void selectionSort(int* num, int size)
{
    int min, temp; // ��� ������ ������������ �������� � ��� ������
    for (int i = 0; i < size - 1; i++)
    {
        min = i; // ���������� ������ �������� ��������
        // ���� ����������� ������� ����� ��������� �� ����� i-���
        for (int j = i + 1; j < size; j++)  // ��� ��������� ��������� ����� i-���
        {
            if (num[j] < num[min]) // ���� ������� ������ ������������,
                min = j;       // ���������� ��� ������ � min
        }
        temp = num[i];      // ������ ������� i-�� � ����������� ��������
        num[i] = num[min];
        num[min] = temp;
    }
}
int main()
{
    setlocale(LC_ALL, "Rus");
    int choose;
    int a[10];
    while (true) {
        system("cls");
        mainmenu();
        scanf("%d", &choose);
        system("cls");
        if (choose == 1) {
            // ��������� ������ �� 10 ���������
           // ������ �������� ��������� �������
            for (int i = 0; i < 10; i++)
            {
                printf("a[%d] = ", i);
                scanf("%d", &a[i]);
            }
            system("pause");
            continue;
        }

        if (choose == 2) {
            selectionSort(a, 10);
            system("pause");
            continue;
        }

        if (choose == 3) {
            Savefile(a);
            system("pause");
            continue;
        }
        if (choose == 4) {
            load(a);
            system("pause");
            continue;
        }

        if (choose == 5)
        {
            print(a, 10);
            system("pause");
            continue;
        }

        if (choose == 6) {
            break;
        }

    }
    return 0;
}