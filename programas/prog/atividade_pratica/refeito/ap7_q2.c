#include <stdio.h>
#include <string.h>

#define STRMAX 500

int comparar(char str1[], char str2[], int sz)
{
    int resultado = 0;
    for ( int i = 0; i < sz; i++)
    {
        if ( str1[i] == '\0' )
            break;
        if ( str1[i] != str2[i] )
            resultado++;
    }

    return resultado;
}

int main()
{
    char s1[STRMAX];
    fgets ( s1, STRMAX, stdin );
    
    char s2[STRMAX];
    fgets ( s2, STRMAX, stdin );

    printf( "de acordo com a string.h:  ");
    if ( strcmp(s1, s2) == 0 )
        printf ( "é igual!\n" );
    else
        printf ( "não é igual!\n" );
    
    printf ( "de acordo com a minha cabeça: " );
    if ( comparar ( s1, s2, STRMAX ) == 0 )
        printf ( "é igual!\n" );
    else
        printf ( "não é igual!\n" );    

    return 0;
}