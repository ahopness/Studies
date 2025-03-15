#include <stdio.h>
#include <string.h>

void to_caps(char str[])
{
    for ( int i = 0; i <= strlen(str); i++ )
    {
        if ( str[i] >= 'a' && str[i] <= 'z' )
            str[i] -= 32;
    }
}

int main()
{
    char string[500];

    fgets ( string, 500, stdin );

    to_caps( string );

    printf ( "%s\n", string );

    return 0;
}