#include <stdio.h>

int edit ( int *a )
{
    *a = 6;
    return 7;
}

int main()
{
    int a = 0, b = edit( &a );

    printf ( "%d e %d\n", b, a );

    return 0;
}