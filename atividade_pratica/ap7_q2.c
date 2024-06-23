#include <stdio.h>

#define STRLEN 50

int main()
{
    char str_a[STRLEN]; fgets ( str_a, 50, stdin );
    char str_b[STRLEN]; fgets ( str_b, 50, stdin );

    int dif = 0;
    for ( int i = 0; i < STRLEN; i++ )
    {
        if ( str_a[i] == '\0' ) break;
        if ( str_a[i] != str_b[i] ) dif++;
    }

    if ( dif != 0 )
        printf ( "as strings são diferentes\n" );
    else
        printf ( "as strings são iguais\n" );

    return 0;
}