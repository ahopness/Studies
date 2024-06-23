#include <stdio.h>

#include <string.h>

#define STRLEN   50
#define ASCIILEN 255

char to_upper ( char c )
{
    if ( c > 'a' && c < 'z' ) 
        return c - 32;
    else
        return c;
}
char to_lower ( char c )
{
    if ( c > 'A' && c < 'Z' ) 
        return c + 32;
    else
        return c;
}

int main()
{
    char str[STRLEN]; fgets ( str, 50, stdin );

    int primeira_letra = 1;
    for ( int i = 0; i < strlen(str); i++ )
    {
        if ( primeira_letra > 0 )
        {
            str[i] = to_upper ( str[i] );
            primeira_letra = 0;
        }
        else
        {
            str[i] = to_lower ( str[i] );
        }

        if ( str[i] == ' ' ) primeira_letra = 1;
    }

    printf ( "%s\n", str );

    return 0;
}