#include <stdio.h>

#define ARRMAX 2000

int main()
{
    int nums[ARRMAX] = { 0 };
    int entries[ARRMAX] = { 0 };

    int ct; scanf( "%d", &ct );
    if ( ct > ARRMAX ) ct = ARRMAX;

    for ( int i = 0; i < ct; i++ )
    {
        scanf ( "%d", &nums[i] );
        entries[nums[i]] += 1;
    }

    for ( int i = 0; i < ARRMAX; i++ )
    {
        if ( entries[i] > 0 )
            printf ( "%d aparece %d vez(es)\n", i, entries[i]);
    }

    return 0;
}