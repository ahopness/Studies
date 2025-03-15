#include <stdio.h>

#include <string.h>

#define STRLEN 50

int main()
{
    char str[STRLEN]; fgets ( str, 50, stdin );

    int qts[255] = { 0 };

    for ( int i = 0; i < strlen(str); i++ )
        qts[str[i]]++;

    for ( int i = 0; i < 255; i++ )
        if ( (i > 'a' && i < 'z') || (i > 'A' && i < 'Z') ) 
            printf ( "%c: %d\n", i, qts[i]);

    return 0;
}