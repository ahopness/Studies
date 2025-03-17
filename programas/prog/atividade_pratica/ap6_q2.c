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
    for ( int i = 0; i < ARRLEN; i++ )
        arr[i] = (rand() % 100) + 1;
    
    int n; scanf ( "%d", &n );
    int qt = 0; 
    int pos[ARRLEN] = { -1 }; int pos_i = 0;
    for ( int i = 0; i < ARRLEN; i++ )
    {
        if ( arr[i] == n )
        {
            qt++;
            pos[pos_i] = i; 
            pos_i++;
        }
    }

    if ( qt > 0 )
    {
        printf ( "numero encontrado dentro do vetor!\n" );
        printf ( "%d vezes\n", qt );
        printf ( "nas posições: " );
        for ( int i = 0; i < ARRLEN; i++ )
            if ( pos[i] > 0 )
                printf ( "%d ", pos[i] );
        printf ( "\n " );
    }
    else
    {
        printf ( "numero NÃO encontrado dentro do vetor!\n" );
    }
    
    printf ( "\n" );
    print_arr ( ARRLEN, arr );

    return 0;
}