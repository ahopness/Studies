#include <stdio.h>

// Não consegui fazer esse direito, pedir ajuda pro professor dps

int rec_int2bi(int num)
{
    if (num > 1)
        rec_int2bi(num / 2);

    printf("%d", num % 2);
}

int main()
{
    int number; scanf("%d", &number);

    rec_int2bi(number);

    return 0;
}