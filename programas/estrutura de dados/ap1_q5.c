#include <stdio.h>

int rec_power(int num, int pow)
{
//    if (pow > 1)
//        return rec_power(num * num, pow - 1);
    if (pow > 1) 
        return num * rec_power(num, pow - 1);
}

int main()
{
    int a, b; 
    printf("digite um numero: "); scanf("%d", &a);
    printf("digite sua potencia: "); scanf("%d", &b);

    printf("\nresultado: %d\n", rec_power(a, b));

    return 0;
}