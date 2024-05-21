#include <stdio.h>

int main()
{
    do
    {   
        printf ( "Digite um numero: " );
        int num; scanf ( "%d", &num );
        if ( num < 0 )
        {
            printf ( "Nao pode ser numero negativo!\n");
            continue;
        }

        for ( int i = 1; i <= 10; i++ )
        {
            printf ( "%d X %d = %d\n", num, i, (num*i) );
        }
        break;
    }
    while( 1 );

    return 0;
}