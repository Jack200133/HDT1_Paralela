// Ejercicio 1: Hello World con OpenMP
// Autor: Juan Angel Carrera Soto
// 11/08/2023

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void hello_world(void);

int main(int argc, char *argv[])
{
    int thread_count = 10;

    if (argc > 1)
    {
        thread_count = strtol(argv[1], NULL, 10);
    }

#pragma omp parallel num_threads(thread_count)
    hello_world();

    return 0;
}

void hello_world(void)
{
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();
    printf("Hello from thread %d of %d\n", my_rank, thread_count);
}