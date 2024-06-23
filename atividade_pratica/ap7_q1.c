#include <stdio.h>

#include <string.h>

int main()
{
    char str[50]; fgets ( str, 50, stdin );

    int qt = 0;
    for ( int i = 0; i < strlen(str); i++ )
        if ( str[i] == 'a' ) qt++;
    
    printf ( "%d 'a' encontrado(s) no texto\n", qt );

    return 0;
}