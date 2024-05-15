#include <stdio.h>

int a;

void proc1 ( int b )
{
    a = a * b;
}

int main()
{
    a = 3;
    int b = 5;
    
    printf ( "Antes: %d - %d\n", a, b );
    
    proc1 ( a );
    printf ( "Depois: %d - %d\n", a, b );

    return 0;
}