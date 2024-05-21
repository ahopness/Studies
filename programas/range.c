#include <stdio.h>

int range ( int a, int b )
{
    int n = a - b;
    
    if ( n < 0 )
        n = -n;
    
    return n;

}

int main()
{
    srand(time(NULL));
    int rd = rand() % 11;

    printf ( "Digite um numero entre 0 e 10 : " );
    int n; scanf ( "%d", &n );
    
    while ( 1 )
    {
        int rg = range ( n, rd );
        if ( rg == 0 )
        {
            printf ( "Parabens, voce acertou! o numero magico era: %d\n", rd );
            break;
        }
        else if ( rg > 0 && rg <= 2 )
        {
            printf ( "ta fervendo;\n" );
        }
        else if ( rg > 2 && rg <= 4 )
        {
            printf ( "ta esquentando;\n" );
        }
        else if ( rg > 4 && rg <= 10 )
        {
            printf ( "ta frio;\n" );
        }
        else if ( rg > 10 )
        {
            printf ( "ta congelando;\n" );
        }

        printf ( "Digite outro numero: ");
        scanf ( "%d", &n );
    }

    return 0;
}