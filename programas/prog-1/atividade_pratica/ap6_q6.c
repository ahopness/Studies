#include <stdio.h>

#include <stdlib.h>
#include <time.h>

#define ARRLEN 30

void print_arr( int size, int arr[size] )
{
    for ( int i = 0; i < size; i++ )
    {
        printf ( "%d", arr[i] );
        if ( i != size-1 ) printf( ", " );
    }

    printf ( "\n" );
}

int main()
{
    int arr[ARRLEN] = { 0 };
    srand(time(NULL));
    for ( int i = 0; i < ARRLEN; i++ )
        arr[i] = (rand() % 100) + 1;
    
    print_arr( ARRLEN, arr ); //printf ( "\n");

    int sum_impar = 0, sum_par = 0;
    for ( int i = 0; i < ARRLEN; i++ )
    {
        if ( i % 2 != 0 ) sum_impar += arr[i];
        if ( i % 2 == 0 ) sum_par += arr[i];
    }

    float div = (float)sum_impar / (float)sum_par;

    printf ( "\n" );
    printf ( "sum impar: %d\n", sum_impar );
    printf ( "sum par  : %d\n", sum_par );
    printf ( "resultado: %.3f\n", div );

    return 0;
}