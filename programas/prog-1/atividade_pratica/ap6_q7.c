#include <stdio.h>

#include <stdlib.h>
#include <time.h>

#define ARRLEN 20

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
    for ( int i = 0; i < (ARRLEN / 2); i++ )
        arr[i] = i+1;
    
    print_arr( ARRLEN, arr );

    int j = 1;
    for ( int i = (ARRLEN / 2); i < ARRLEN; i++ )
    {
        arr[i] = arr[(ARRLEN / 2) - j];
        j++;
    }
    
    print_arr( ARRLEN, arr );

    return 0;
}