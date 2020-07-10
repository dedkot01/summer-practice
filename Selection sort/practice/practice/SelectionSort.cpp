#define _CRT_SECURE_NO_WARNINGS // для корректной работы scanf()
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <clocale>
// Функция сортировки прямым выбором

void print(int* num, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", num[i]);
}

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
    printf("Чтобы продолжить, нажмите любую кнопку клавиатуры ");
    system("pause");
}

void Savefile(int* num) {

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
    for (int i = 0; i < 10; i++)
    {
        fprintf(f, "%d\n", num[i]);
    }
    fclose(f);
    printf("Чтобы продолжить, нажмите любую кнопку клавиатуры  ");
    system("pause");

}

void selectionSort(int* num, int size)
{
    int min, temp; // для поиска минимального элемента и для обмена
    for (int i = 0; i < size - 1; i++)
    {
        min = i; // запоминаем индекс текущего элемента
        // ищем минимальный элемент чтобы поместить на место i-ого
        for (int j = i + 1; j < size; j++)  // для остальных элементов после i-ого
        {
            if (num[j] < num[min]) // если элемент меньше минимального,
                min = j;       // запоминаем его индекс в min
        }
        temp = num[i];      // меняем местами i-ый и минимальный элементы
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

        scanf("%d", &choose);

        if (choose == 1) {
            // Объявляем массив из 10 элементов
           // Вводим значения элементов массива
            for (int i = 0; i < 10; i++)
            {
                printf("a[%d] = ", i);
                scanf("%d", &a[i]);
            }
            selectionSort(a, 10);  // вызываем функцию сортировк
            system("pause");
            continue;
        }

        if (choose == 2) {
            Savefile(a);
            continue;
        }
        if (choose == 3) {
            load(a);
            continue;
        }

        if (choose == 4)
        {
            print(a, 10);
            continue;
        }

        if (choose == 5) {
            break;
        }

    }
    return 0;
}