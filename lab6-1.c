#include <stdio.h>
#include <float.h>

#define M 3  // Кількість рядків
#define N 4  // Кількість стовпців

int main() {
    system("chcp 65001");
    // Задаємо матриці A і B
    double A[M][N] = {
        {1.5, 2.3, 4.0, 0.5},
        {1.7, 3.2, 5.1, 8.4},
        {0.5, 2.7, 3.1, 6.9}
    };
    
    double B[M][N] = {
        {0.5, 1.3, 2.0, 0.1},
        {1.0, 2.2, 4.1, 7.4},
        {0.1, 1.7, 2.1, 5.9}
    };
    
    // Матриця C = A - B
    double C[M][N];
    
    // Обчислюємо матрицю C
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    
    // Виводимо матриці для наглядності
    printf("Матриця A:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%6.2f ", A[i][j]);
        }
        printf("\n");
    }
    
    printf("\nМатриця B:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%6.2f ", B[i][j]);
        }
        printf("\n");
    }
    
    printf("\nМатриця C = A - B:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%6.2f ", C[i][j]);
        }
        printf("\n");
    }
    
    // Обчислюємо коефіцієнти для кожного рядка (середнє значення)
    double coefficients[M];
    for (int i = 0; i < M; i++) {
        double sum = 0;
        for (int j = 0; j < N; j++) {
            sum += C[i][j];
        }
        coefficients[i] = sum / N;  // Середнє арифметичне
    }
    
    // Знаходимо рядок з мінімальним коефіцієнтом
    int min_row = 0;
    double min_coeff = coefficients[0];
    for (int i = 1; i < M; i++) {
        if (coefficients[i] < min_coeff) {
            min_coeff = coefficients[i];
            min_row = i;
        }
    }
    
    // Виводимо результати
    printf("\nКоефіцієнти рядків (середнє значення):\n");
    for (int i = 0; i < M; i++) {
        printf("Рядок %d: %.2f\n", i+1, coefficients[i]);
    }
    
    printf("\nРядок з мінімальним коефіцієнтом: %d (коефіцієнт = %.2f)\n", 
           min_row+1, min_coeff);
    printf("Елементи цього рядка матриці C:\n");
    for (int j = 0; j < N; j++) {
        printf("%6.2f ", C[min_row][j]);
    }
    
    return 0;
}