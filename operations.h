#ifndef OPERATIONS_H
#define OPERATIONS_H

// Функции для работы с массивом
void sort_array_descending(int *array, int size);
void print_array(int *array, int size);
void fill_array_random(int *array, int size);

// Функции для работы с матрицей  
void sort_matrix_rows_descending(int **matrix, int rows, int cols);
void print_matrix(int **matrix, int rows, int cols);
void fill_matrix_random(int **matrix, int rows, int cols);
void free_matrix(int **matrix, int rows);

#endif