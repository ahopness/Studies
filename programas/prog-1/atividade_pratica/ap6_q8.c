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
        arr[i] = i + 1;
        //arr[i] = (rand() % 100) + 1;
    
    print_arr( ARRLEN, arr );

    int a[ARRLEN/2], b[ARRLEN/2];
    int a_i = 0, b_i = 0;
    for ( int i = 0; i < ARRLEN; i++ )
    {
        if ( i % 2 == 0 ) 
        {
            a[a_i] = arr[i];
            a_i++;
        }
        else
        {
            b[b_i] = arr[i];
            b_i++;
        }
    }

    print_arr( ARRLEN/2, a );
    print_arr( ARRLEN/2, b );

    return 0;
}