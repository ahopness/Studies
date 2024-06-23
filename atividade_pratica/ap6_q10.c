#include <stdio.h>

#include <stdlib.h>
#include <time.h>

#define ARRLEN 10

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
    

    /* Criando um vetor simetrico (não faz parte da atividade)
    int j = 1;
    for ( int i = (ARRLEN / 2); i < ARRLEN; i++ )
    {
        arr[i] = arr[(ARRLEN / 2) - j];
        j++;
    }
    
    print_arr( ARRLEN, arr );
    */ 

    int simetrico = 0;

    for ( int i = 0; i < ARRLEN/2; i++ )
    {
        if ( arr[i] == arr[(ARRLEN-1) - i] ) 
        {
            simetrico++;
        }
    }

    if ( simetrico != 0 )
        printf ( "o vetor é simetrico\n" );
    else
        printf ( "o NÃO vetor é simetrico\n" );

    return 0;
}