#include <stdio.h>


void print(int* num, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", num[i]);
}