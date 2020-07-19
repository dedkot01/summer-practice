#define _CRT_SECURE_NO_WARNINGS // для корректной работы scanf()
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <clocale>

void mainmenu() {
	printf("1. Заполнить массив\n");
	printf("2. Сортировать массив с помощью алгоритма выбора (selection sort)\n");
	printf("3. Сохранить массив\n");
	printf("4. Загрузить массив\n");
	printf("5. Вывести массив на экран\n");
	printf("6. Выход из программы\n");
	printf("Выберите действие: ");
}