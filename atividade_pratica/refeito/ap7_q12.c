#include <stdio.h>

#include <stdlib.h>
#include <time.h>

#define NL() printf( "\n" )
#define NT() printf( "\t" )

#define M_X 12
#define M_Y 10

void ler_matriz( int x, int y, int m[x][y] )
{
    srand(time(NULL));

    for ( int i = 0; i < x; i++ )
    {
        for ( int j = 0; j < y; j++ )
        {
            //printf( "Didite um valor para (%d, %d): ", i, j );
            //scanf ( "%d", &m[i][j]);
            m[i][j] = rand() % 1000;
        }
    }
}
void imprimir_matriz( int x, int y, int m[x][y] )
{
    for ( int i = 0; i < y+1; i++ )
    {
        if ( i != 0 )
            printf( "p %d:\t", i);
        else
            NT();
    }
    NL();
    
    for ( int i = 0; i < x; i++ )
    {
        printf ( "mes %d:\t", i+1);

        for ( int j = 0; j < y; j++ )
        {
            printf( "%d\t", m[i][j] );
        }

        NL();
    }
}

int total_vendas_ano( int x, int y, int m[x][y] )
{
    int vendas = 0;

    for ( int i = 0; i < x; i++ )
    {
        for ( int j = 0; j < y; j++ )
        {
            vendas += m[i][j];
        }
    }

    return vendas;
}
int total_vendas_mes( int x, int y, int m[x][y], int mes )
{
    int vendas = 0;

    for ( int i = 0; i < y; i++ )
        vendas += m[mes][i];

    return vendas;
}
int total_vendas_produto( int x, int y, int m[x][y], int produto )
{
    int vendas = 0;

    for ( int i = 0; i < y; i++ )
        vendas += m[i][produto];

    return vendas;
}

int produto_mais_vendido_no_mes( int x, int y, int m[x][y], int mes )
{
    int prod = 0;

    for ( int i = 0; i < y; i++ )
    {
        if ( m[mes][i] > m[mes][prod] )
            prod = i;
    }

    return prod;
}
int mes_mais_rentavel_do_produto( int x, int y, int m[x][y], int prod )
{
    int mes = 0;

    for ( int i = 0; i < y; i++ )
    {
        if ( m[i][prod] > m[mes][prod] )
            mes = i;
    }

    return mes;
}

int main()
{
    int matriz[M_X][M_Y];

    ler_matriz ( M_X, M_Y, matriz );
    
    imprimir_matriz ( M_X, M_Y, matriz );
    NL();

    printf( "total de vendas anuais: %d\n", total_vendas_ano( M_X, M_Y, matriz ) );
    NL();

    for ( int i = 0; i < M_X; i++ )
        printf( "total de vendas no mes %d: %d\n", i+1, total_vendas_mes( M_X, M_Y, matriz, i ) );
    NL();

    for ( int i = 0; i < M_Y; i++ )
        printf( "total de vendas do produto %d: %d\n", i+1, total_vendas_mes( M_X, M_Y, matriz, i ) );
    NL();

    for ( int i = 0; i < M_X; i++ )
        printf( "produto mais vendido no mes %d: %d\n", i+1, produto_mais_vendido_no_mes( M_X, M_Y, matriz, i )+1 );
    NL();

    for ( int i = 0; i < M_Y; i++ )
        printf( "mes mais rentavel do produto %d: %d\n", i+1, mes_mais_rentavel_do_produto( M_X, M_Y, matriz, i )+1 );
    NL();

    return 0;
}