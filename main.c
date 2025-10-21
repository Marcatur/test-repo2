#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dlfcn.h>   // Linux-заголовок вместо windows.h

// Объявления типов для функций из библиотек
typedef void (*sort_array_func)(int*, int);
typedef void (*print_array_func)(int*, int);
typedef void (*fill_array_func)(int*, int);
typedef void (*sort_matrix_func)(int**, int, int);
typedef void (*print_matrix_func)(int**, int, int);
typedef void (*fill_matrix_func)(int**, int, int);
typedef void (*free_matrix_func)(int**, int);

int main() {
    srand(time(NULL)); // Инициализация генератора случайных чисел
    int choice;
    void* library_handle = NULL;  // Linux использует void* вместо HINSTANCE
    
    // Указатели на функции
    sort_array_func sort_array_ptr = NULL;
    print_array_func print_array_ptr = NULL;
    fill_array_func fill_array_ptr = NULL;
    sort_matrix_func sort_matrix_ptr = NULL;
    print_matrix_func print_matrix_ptr = NULL;
    fill_matrix_func fill_matrix_ptr = NULL;
    free_matrix_func free_matrix_ptr = NULL;
    
    do {
        printf("\n=== Selection Menu (LINUX VERSION) ===\n");
        printf("1 - Array Sorting (50 elements)\n");
        printf("2 - Matrix Rows Sorting (6x7)\n");
        printf("3 - Exit\n");
        printf("Select option: ");
        scanf("%d", &choice);
        
        if(choice == 1) {
            // Загрузка библиотеки для работы с массивом (Linux версия)
            library_handle = dlopen("./libarray.so", RTLD_LAZY);
            
            if(!library_handle) {
                printf("Error loading array library: %s\n", dlerror());
                continue;
            }
            
            // Загрузка функций из библиотеки
            sort_array_ptr = (sort_array_func)dlsym(library_handle, "sort_array_descending");
            print_array_ptr = (print_array_func)dlsym(library_handle, "print_array");
            fill_array_ptr = (fill_array_func)dlsym(library_handle, "fill_array_random");
            
            if(sort_array_ptr && print_array_ptr && fill_array_ptr) {
                int array[50];
                
                printf("\n--- Array Processing (Linux) ---\n");
                printf("Original array:\n");
                fill_array_ptr(array, 50);
                print_array_ptr(array, 50);
                
                printf("\nArray after sorting in descending order:\n");
                sort_array_ptr(array, 50);
                print_array_ptr(array, 50);
            } else {
                printf("Error loading functions from library!\n");
            }
            
            // Выгрузка библиотеки (Linux версия)
            dlclose(library_handle);
            
        } else if(choice == 2) {
            // Загрузка библиотеки для работы с матрицей (Linux версия)
            library_handle = dlopen("./libmatrix.so", RTLD_LAZY);
            
            if(!library_handle) {
                printf("Error loading matrix library: %s\n", dlerror());
                continue;
            }
            
            // Загрузка функций из библиотеки
            sort_matrix_ptr = (sort_matrix_func)dlsym(library_handle, "sort_matrix_rows_descending");
            print_matrix_ptr = (print_matrix_func)dlsym(library_handle, "print_matrix");
            fill_matrix_ptr = (fill_matrix_func)dlsym(library_handle, "fill_matrix_random");
            free_matrix_ptr = (free_matrix_func)dlsym(library_handle, "free_matrix");
            
            if(sort_matrix_ptr && print_matrix_ptr && fill_matrix_ptr && free_matrix_ptr) {
                // Создание матрицы 6x7
                int **matrix = (int**)malloc(6 * sizeof(int*));
                for(int i = 0; i < 6; i++) {
                    matrix[i] = (int*)malloc(7 * sizeof(int));
                }
                
                printf("\n--- Matrix Processing (Linux) ---\n");
                printf("Original matrix:\n");
                fill_matrix_ptr(matrix, 6, 7);
                print_matrix_ptr(matrix, 6, 7);
                
                printf("\nMatrix after sorting rows in descending order:\n");
                sort_matrix_ptr(matrix, 6, 7);
                print_matrix_ptr(matrix, 6, 7);
                
                free_matrix_ptr(matrix, 6);
            } else {
                printf("Error loading functions from library!\n");
            }
            
            // Выгрузка библиотеки (Linux версия)
            dlclose(library_handle);
        }
        
    } while(choice != 3);
    
    printf("Exiting Linux version program.\n");
    return 0;
}