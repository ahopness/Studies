#include <stdio.h>
 
#define ARRLEN 10
 
int main() {
 
    int arr[ARRLEN];
    
    for ( int i = 0; i < ARRLEN; i++ )
    {
        scanf ( "%d", &arr[i] );
    
        if ( arr[i] <= 0 )
            arr[i] = 1;
    }
    
    for ( int i = 0; i < ARRLEN; i++ )
    {
        printf ( "X[%d] = %d\n", i, arr[i] );
    }
 
    return 0;
}