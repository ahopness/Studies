#include <stdio.h>

float dar_aumento ( float *v )
{
    float aumento = 0;
    if      ( *v < 5000.0 )
        aumento = *v * .2;
    else if ( *v < 8000 )
        aumento = *v * .15;
    else if ( *v < 10000 )
        aumento = *v * .10;
    else
        aumento = *v * .075;
    
    *v += aumento;
    return aumento;
}

int main()
{
    float t_aumento = 0;

    for ( int i = 0; i < 10; i++ )
    {
        float salario;
        printf ( "Digite seu salario atual: ");
        scanf ( "%f", &salario );
        t_aumento += dar_aumento ( &salario );
        printf ( "Seu novo salario: %.4f\n", salario );
        printf ( "\n" );
    }
    
    printf ( "Total de aumento da folha de pagamento: %.4f\n", t_aumento );
    
    return 0;
}