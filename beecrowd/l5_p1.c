#include <stdio.h>
#include <string.h>

#define STRLEN 50

// [int last_char]
// -1 nao comecou a contagem
// 0 para minusculo
// 1 para maiusculo

int main() {
    char str[STRLEN];
    
    do 
    {
        fgets ( str, STRLEN, stdin );
        
        int last_char = -1;
        for ( int i = 0; i < strlen ( str ); i++ )
        {
            if ( str[i] == ' ' )
                continue;
            
            if ( last_char == -1  || last_char == 0)
            {
                if ( str[i] >= 'a' && str[i] <= 'z' )
                    str[i] -= 32;
                last_char = 1;
            }
            else if ( last_char == 1 )
            {
                if ( str[i] >= 'A' && str[i] <= 'Z' )
                    str[i] += 32;
                last_char = 0;
            }
        }

        printf ( "%s", str );
    } 
    while ( str[0] != '\n' );
    
    return 0;
}