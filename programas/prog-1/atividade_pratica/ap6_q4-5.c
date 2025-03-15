#include <stdio.h>

#include <stdlib.h>
#include <time.h>

#define ARRLEN 50

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
    
    for ( int i = 0; i < ARRLEN; i++ )
    {
        int n = arr[i];
        int qt = 0;
        
        for ( int j = 0; j < ARRLEN; j++ )
            if ( arr[j] == n ) qt++;
        
        if ( qt > 1 )
            printf ( "numero %d encontrado %d vezes\n", n, qt );
    }

    return 0;
}