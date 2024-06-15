#include <stdio.h>

#define ARRLEN 10

int main() {
    int arr[ARRLEN];
 
    for ( int i = 0; i < ARRLEN; i++ )
    {
        printf ( "[%d]: ", i );
        scanf ( "%d", &arr[i] );
    }

    int temp;
    for ( int i = 0; i < ARRLEN/2; i++ )
    {
        temp = arr[i];
        arr[i] = arr[((ARRLEN-1)-i)];
        arr[((ARRLEN-1)-i)] = temp;
    }
    
    for ( int i = 0; i < ARRLEN; i++ )
    {
        printf ( "N[%d] = %d\n", i, arr[i] );
    }

    return 0;
}