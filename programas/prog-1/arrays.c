#include <stdio.h>

#define ARRLENGTH(x) ( ( int )( sizeof(x) / sizeof( x[0] ) ) )

int main()
{
    // VLA
    int size = 2;
    int vec1[size];

    // Trad. Arr
    int vec2[2];

    int vec3[] = { 3, 4, 7 };

    printf( "vec1 size: %d\n", ARRLENGTH( vec1 ) );
    printf( "vec2 size: %d\n", ARRLENGTH( vec2 ) );
    printf( "vec3 size: %d\n", ARRLENGTH( vec3 ) );

    return 0;
}