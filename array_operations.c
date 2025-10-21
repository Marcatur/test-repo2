#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

// Функция для заполнения массива случайными числами от -50 до 50
void fill_array_random(int *array, int size) {
    for(int i = 0; i < size; i++) {
        array[i] = rand() % 101 - 50; // числа от -50 до 50
    }
}

// Функция для сортировки массива в порядке убывания (пузырьковая сортировка)
void sort_array_descending(int *array, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(array[j] < array[j + 1]) {
                // Обмен элементов
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Функция для вывода массива
void print_array(int *array, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}