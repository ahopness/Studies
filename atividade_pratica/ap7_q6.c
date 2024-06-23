#include <stdio.h>

#include <string.h>

#define STRLEN   50
#define ASCIILEN 255

int main()
{
    char str[STRLEN]; fgets ( str, 50, stdin );

    for ( int i = 0, j = strlen(str)-1; i < j; i++, j-- )
    {
        int temp;
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    printf ( "%s\n", str );

    return 0;
}