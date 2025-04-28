#include <stdio.h>

int rec_digit_count(int num, int dig)
{
    if (num > 0)
        return rec_digit_count(num / 10, dig + 1);
    else
        return dig;
}

int main()
{
    int number; scanf("%d", &number);

    printf("%d\n", rec_digit_count(number, 0));

    return 0;
}