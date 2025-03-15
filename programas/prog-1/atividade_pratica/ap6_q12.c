#include <stdio.h>

#include <stdlib.h>
#include <time.h>

#define Q_MESES    12
#define Q_PRODUTOS 10

int main()
{
    int vendas[Q_MESES][Q_PRODUTOS];
    
    srand(time(NULL));
    for ( int i = 0; i < Q_MESES; i++ )
        for ( int j = 0; j < Q_PRODUTOS; j++ )
            vendas[i][j] = (rand() % 100) + 1;

    // Imprimindo *toda a matriz*
    for ( int i = 0; i < Q_MESES; i++ )
    {
        for ( int j = 0; j < Q_PRODUTOS; j++ )
            printf ( "%d\t", vendas[i][j] );
        printf ( "\n" );
    }
    printf ( "\n" );

    // Imprimindo *total de vendas anuais*
    int q_vendas_anual = 0;
    for ( int i = 0; i < Q_MESES; i++ )
        for ( int j = 0; j < Q_PRODUTOS; j++ )
            q_vendas_anual += vendas[i][j];
    printf ( "total de vendas: %d\n", q_vendas_anual );
    printf ( "\n" );

    // Imprimindo *total de vendas por mes*
    for ( int i = 0; i < Q_MESES; i++ )
    {
        int q_vendas_mensal = 0;

        for ( int j = 0; j < Q_PRODUTOS; j++ )
            q_vendas_mensal += vendas[i][j];
        
        printf ( "total de vendas no mes %d: %d\n", i+1, q_vendas_mensal );
    }
    printf ( "\n" );

    // Imprimindo *total de vendas anuais de cada produto*
    for ( int i = 0; i < Q_PRODUTOS; i++ )
    {
        int q_vendas_anual_produtos = 0;

        for ( int j = 0; j < Q_MESES; j++ )
            q_vendas_anual_produtos += vendas[i][j];
        
        printf ( "total de vendas no ano do produto %d: %d\n", i+1, q_vendas_anual_produtos );
    }
    printf ( "\n" );

    // Imprimindo *qual o mês de maior venda de cada produto*
    for ( int i = 0; i < Q_PRODUTOS; i++ )
    {
        int mes_maior_vendas = 0;

        for ( int j = 0; j < Q_MESES; j++ )
        {
            if ( vendas[i][j] > vendas[i][mes_maior_vendas] )
                mes_maior_vendas = j;

        }

        printf ( "mes de maior venda do produto %d: %d\n", i+1, mes_maior_vendas+1 );
    }

    ///////AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA Q CONFUSO
    return 0;
}