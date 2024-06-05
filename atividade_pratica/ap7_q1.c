#include <stdio.h>

#define ARRMAX 5

int main()
{
    int m[ARRMAX];
    for( int i = 0; i < ARRMAX; i++ )
        scanf( "%d", &m[i] );

    for( int i = 0; i < ARRMAX; i++ )
    {
        int temp = m[i];
        m[i] = m[ARRMAX - (i+1)];
        m[ARRMAX - (i+1)] = temp;
    }
    
    for( int i = 0; i < ARRMAX; i++ )
        printf( "%d\t", m[i] );

    printf( "\n" );

    return 0;
}