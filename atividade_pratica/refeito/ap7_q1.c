#include <stdio.h>

#define STRMAX 500

int main()
{
    char tex[STRMAX];

    fgets(tex, STRMAX-1, stdin);

    int ct = 0;
    for ( int i = 0; i < STRMAX; i++ )
    {
        if ( tex[i] == 'a') 
            ct++;
    }

    printf("q. de 'a': %d\n", ct);

    return 0;
}