#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

// Функция для заполнения матрицы случайными числами от -50 до 50
void fill_matrix_random(int **matrix, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 101 - 50; // числа от -50 до 50
        }
    }
}

// Функция для сортировки строк матрицы в порядке убывания
void sort_matrix_rows_descending(int **matrix, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        // Сортировка каждой строки пузырьковой сортировкой
        for(int j = 0; j < cols - 1; j++) {
            for(int k = 0; k < cols - j - 1; k++) {
                if(matrix[i][k] < matrix[i][k + 1]) {
                    // Обмен элементов в строке
                    int temp = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = temp;
                }
            }
        }
    }
}

// Функция для вывода матрицы
void print_matrix(int **matrix, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%6d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Функция для освобождения памяти матрицы
void free_matrix(int **matrix, int rows) {
    for(int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}