#include <stdio.h>

#include <stdlib.h>
#include <time.h>

#define ARRLEN 10

int main()
{
    int arr[ARRLEN][ARRLEN];

    srand(time(NULL));
    for ( int i = 0; i < ARRLEN; i++ )
        for ( int j = 0; j < ARRLEN; j++ )
            arr[i][j] = (rand() % 100) + 1;
    
    // Imprimindo *toda a matriz*
    for ( int i = 0; i < ARRLEN; i++ )
    {
        for ( int j = 0; j < ARRLEN; j++ )
        {
            printf ( "%d\t", arr[i][j] );
        }
        printf ( "\n" );
    }
    printf ( "\n" );

    // Imprimindo *apenas as linhas pares*
    for ( int i = 0; i < ARRLEN; i++ )
    {
        if ( i % 2 == 0)
        {
            for ( int j = 0; j < ARRLEN; j++ )
            {
                printf ( "%d\t", arr[i][j] );
            }
            printf ( "\n" );
        }
        else
        {
            for ( int j = 0; j < ARRLEN; j++ )
            {
                printf ( "-\t" );
            }
            printf ( "\n" );
        }
    }
    printf ( "\n" );

    // Imprimindo *apenas as colunas ímpares*
    for ( int i = 0; i < ARRLEN; i++ )
    {
        for ( int j = 0; j < ARRLEN; j++ )
        {
            if ( j % 2 != 0 )
            {
                printf ( "%d\t", arr[i][j] );
            }
            else
            {
                printf ( "-\t" );
            }
        }
        printf ( "\n" );
    }
    printf ( "\n" );
    
    // Imprimindo *apenas os elementos contidos em posições onde a soma do índice da linha e da coluna seja um número par*
    for ( int i = 0; i < ARRLEN; i++ )
    {
        for ( int j = 0; j < ARRLEN; j++ )
        {
            if ( (i + j) % 2 == 0 )
            {
                printf ( "%d\t", arr[i][j] );
            }
            else
            {
                printf ( "-\t" );
            }
        }
        printf ( "\n" );
    }
    printf ( "\n" );

    return 0;
}