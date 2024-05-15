#include <stdio.h>

void trocar( int *var1, int *var2)
{
    int temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}

int main()
{
    int n1, n2, n3;
    scanf ( "%d %d %d", &n1, &n2, &n3 );

    while ( n1 > n2 || n2 > n3 || n1 > n3)
    {
        if ( n1 > n2 )
            trocar ( &n1, &n2 );
        if ( n2 > n3 )
            trocar ( &n2, &n3 );
        if ( n1 > n2 )
            trocar ( &n1, &n2 );
    }

    printf ( "%d <= %d <= %d\n", n1, n2, n3 );
    
    return 0;
}