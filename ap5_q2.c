#include <stdio.h>

void proc1( int *a, int b )
{
    *a = *a * b;
}

int main(){

    int a = 3, b = 5;
    printf ( "Antes: %d - %d\n", a, b );
    proc1( &a, b );
    printf ( "Depois: %d - %d\n", a, b );

    return 0;
}