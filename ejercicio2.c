// Ejercicio 2: Saludos y cumpleaños
// Autor: Juan Angel Carrera Soto
// 11/08/2023

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void print_message(void);

int main(int argc, char *argv[])
{
    int thread_count = 10;

    if (argc > 1)
    {
        thread_count = strtol(argv[1], NULL, 10);
    }

#pragma omp parallel num_threads(thread_count)
    print_message();

    return 0;
}

void print_message(void)
{
    int thread_id = omp_get_thread_num();
    int thread_count = omp_get_num_threads();

    if (thread_id % 2 == 0)
    {
        printf("Saludos del hilo %d\n", thread_id);
    }
    else
    {
        printf("Feliz cumpleaños número %d!\n", thread_count);
    }
}
