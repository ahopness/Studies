#include <stdio.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int r = (rand() % 10) + 1;

    printf ( "Digite um numero entre 1 e 10 : " );
    int n; scanf ( "%d", &n );
    
    while ( 1 )
    {
        if ( n < r )
        {
            printf ( "O numero magico eh *maior* do que o digitado;\n" );
        }
        else if ( n > r )
        {
            printf ( "O numero magico eh *menor* do que o digitado;\n" );
        }
        else if ( n == r )
        {
            printf ( "Parabens, voce acertou! o numero magico era: %d\n", r );
            break;
        }

        printf ( "Digite outro numero: ");
        scanf ( "%d", &n );
    }

    return 0;
}