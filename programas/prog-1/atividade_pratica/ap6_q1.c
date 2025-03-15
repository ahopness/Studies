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
        //scanf ( "%d", &arr[i] );
    
    print_arr( ARRLEN, arr );

    // invertendo arr
    for ( int i = 0, j = ARRLEN-1; i < j; i++, j-- )
    {
        int temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    print_arr( ARRLEN, arr );
    printf ( "\n" );

    printf ( "pares:  " );
    for ( int i = 0; i < ARRLEN; i++ )
        if ( arr[i] % 2 == 0 ) printf ( "%d ", arr[i] );
    printf ( "\n" );

    printf ( "impares:" );
    for ( int i = 0; i < ARRLEN; i++ )
        if ( arr[i] % 2 != 0 ) printf ( "%d ", arr[i] );
    printf ( "\n" );

    return 0;
}