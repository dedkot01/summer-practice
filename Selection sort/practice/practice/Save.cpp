#define _CRT_SECURE_NO_WARNINGS // ��� ���������� ������ scanf()
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <clocale>

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

}
