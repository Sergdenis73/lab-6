#include <stdio.h>

#define SIZE 5

int main() {
    int s[SIZE][SIZE];
    
    // Введення матриці
    printf("Введіть елементи матриці %dx%d:\n", SIZE, SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &s[i][j]);
        }
    }
    
    // Виведення початкової матриці
    printf("\nПочаткова матриця:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", s[i][j]);
        }
        printf("\n");
    }
    
    // Знаходження максимального елемента в кожному стовпці
    int max_in_column[SIZE];
    for (int j = 0; j < SIZE; j++) {
        int max = s[0][j]; // Ініціалізація максимуму першим елементом стовпця
        for (int i = 1; i < SIZE; i++) {
            if (s[i][j] > max) {
                max = s[i][j];
            }
        }
        max_in_column[j] = max; // Зберігаємо максимум для стовпця
    }
    
    // Заміна нулів на максимальний елемент відповідного стовпця
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (s[i][j] == 0) {
                s[i][j] = max_in_column[j];
            }
        }
    }
    
    // Виведення результуючої матриці
    printf("\nРезультуюча матриця:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", s[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}