#include <stdio.h>

#include <stdlib.h>
#include <time.h>

#define ARRLEN 100

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
    

    int maior = 0, menor = 0;
    for ( int i = 0; i < ARRLEN; i++ )
        if ( maior < arr[i] ) maior = arr[i];
    
    menor = maior;
    for ( int i = 0; i < ARRLEN; i++ )
        if ( menor > arr[i] ) menor = arr[i];

    print_arr ( ARRLEN, arr );

    printf ( "maior numero: %d\n", maior );
    printf ( "menor numero: %d\n", menor );

    return 0;
}