#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <clocale>
#include <malloc.h>
#include "Header.h"
// Функция сортировки прямым выбором

int main()
{
    setlocale(LC_ALL, "Rus");
    int choose;
    int* a = nullptr; //указатель на массив
    int n = 0;
    int v =0; // переменная, запоминающая, выделилась ли память для массива
    while (true) {
        system("cls");
        mainmenu();
        scanf("%d", &choose);
        system("cls");
        if (choose == 1) {
                system("cls");
                printf("Введите размер массива: ");
                scanf("%d", &n);
                // Выделение памяти
                v = 1;
                a = (int*)malloc(n * sizeof(int));
                // Ввод элементов массива
                system("cls");
                printf("Как вы хотите заполнить массив?\n 1. Вручную\n 2. Автоматически случайными числами от 1 до 100\nВведите число: ");
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
            printf("Для загрузки базы данных из файла введите имя файла с разрешением .txt: ");
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