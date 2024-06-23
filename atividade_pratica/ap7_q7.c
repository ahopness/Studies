#include <stdio.h>

#include <string.h>

#define STRLEN   50
#define ASCIILEN 255

int main()
{
    char str[STRLEN]; fgets ( str, 50, stdin );
    int n; scanf ( "%d", &n );

    for ( int i = 0; i < strlen(str); i++ )
    {
        if ( str[i] > 'a' && str[i] < 'z' )
        {
            if ( str[i] + n > 'z' ) str[i] = 'a';
            str[i] += n;
        }
        else if ( str[i] > 'A' && str[i] < 'Z' )
        {
            if ( str[i] + n > 'Z' ) str[i] = 'A';
            str[i] += n;
        }
    }

    printf ( "%s\n", str );

    return 0;
}