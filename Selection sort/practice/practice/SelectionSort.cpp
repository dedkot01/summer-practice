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
    int n = 0;
    int v =0; // ����������, ������������, ���������� �� ������ ��� �������
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
                system("cls");
                printf("��� �� ������ ��������� ������?\n 1. �������\n 2. ������������� ���������� ������� �� 1 �� 100\n������� �����: ");
                scanf("%d", &choose);

                if (choose == 1) {
                    for (int i = 0; i < n; i++)
                    {
                        printf("a[%d] = ", i);
                        scanf("%d", &a[i]);
                    }
                }
                if (choose == 2) {
                    for (int i = 0; i < n; i++)
                    {
                        printf("a[%d] = ", i);
                        a[i] = rand() % 100;
                        printf("%d\n", a[i]);
                    }
                }
                system("pause");
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
            system("cls");
            char Filename[25];
            printf("��� �������� ���� ������ �� ����� ������� ��� ����� � ����������� .txt: ");
            scanf("%s", &Filename);
            char* p = Filename;
            a = load(p);
            n = loadsize(p);
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