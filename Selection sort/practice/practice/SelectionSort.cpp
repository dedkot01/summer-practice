#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <clocale>
#include <malloc.h>
#include "Header.h"
// ������� ���������� ������ �������

int main()
{
    setlocale(LC_ALL, "Rus");
    int choose;
    int* a = nullptr; //��������� �� ������
    int n;
    int v; // ����������, ������������, ���������� �� ������ ��� �������
    while (true) {
        system("cls");
        mainmenu();
        scanf("%d", &choose);
        system("cls");
        if (choose == 1) {
                system("cls");
                printf("������� ������ �������: ");
                scanf("%d", &n);
                // ��������� ������
                v = 1;
                a = (int*)malloc(n * sizeof(int));
                // ���� ��������� �������
                for (int i = 0; i < n; i++)
                {
                    printf("a[%d] = ", i);
                    scanf("%d", &a[i]);
                }

            continue;
        }

        if (choose == 2) {
            selectionSort(a, n);
            system("pause");
            continue;
        }

        if (choose == 3) {
            Savefile(a, n);
            system("pause");
            continue;
        }
        if (choose == 4) {
            load(a, n);
            system("pause");
            continue;
        }

        if (choose == 5)
        {
            print(a, n);
            system("pause");
            continue;
        }

        if (choose == 6) {
            break;
        }

    }


    if (v==1) {
        free(a);
    }
    return 0;
}