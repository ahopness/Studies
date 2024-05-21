#include <stdio.h>

void trocar( int *a, int *b )
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

int main()
{
    printf ( "Digite dois numeros: " );
    int n1, n2; scanf ( "%d %d", &n1, &n2 );

    trocar ( &n1, &n2 );

    printf ( "Numeros trocados: %d %d\n", n1, n2 );

    return 0;
}