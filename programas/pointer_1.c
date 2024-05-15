#include <stdio.h>

int edit ( int *a )
{
    *a = 6;
    return 7;
}

int main()
{
    int a = 0;

    printf ( "%d e %d\n", edit( &a ), a );

    return 0;
}