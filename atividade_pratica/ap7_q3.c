#include <stdio.h>

#include <string.h>

#define STRLEN 50

int main()
{
    char str[STRLEN]; fgets ( str, 50, stdin );

    for ( int i = 0; i < strlen(str); i++)
        if ( str[i] > 'a' && str[i] < 'z' ) str[i] -= 32;
    
    printf ( "%s\n", str );

    return 0;
}