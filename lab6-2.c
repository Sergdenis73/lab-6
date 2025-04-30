#include <stdio.h>

#define SIZE 5

int main() {
    system("chcp 65001");
    int s[SIZE][SIZE];
    
    printf("Введіть елементи матриці %dx%d:\n", SIZE, SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &s[i][j]);
        }
    }
    
    printf("\nПочаткова матриця:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", s[i][j]);
        }
        printf("\n");
    }
    
    int max_in_column[SIZE];
    for (int j = 0; j < SIZE; j++) {
        int max = s[0][j];
        for (int i = 1; i < SIZE; i++) {
            if (s[i][j] > max) {
                max = s[i][j];
            }
        }
        max_in_column[j] = max;
    }
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (s[i][j] == 0) {
                s[i][j] = max_in_column[j];
            }
        }
    }
    
    printf("\nРезультуюча матриця:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", s[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}