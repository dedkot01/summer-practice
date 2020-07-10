#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <clocale>
#include "Header.h"
// ‘ункци€ сортировки пр€мым выбором

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
            // ќбъ€вл€ем массив из 10 элементов
           // ¬водим значени€ элементов массива
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