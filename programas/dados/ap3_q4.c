#include <stdio.h>
#include <stdlib.h>

#define TAM_NAIPES 54
char naipes[] = { 'P', 'C', 'O', 'E' };

typedef struct
{
    char naipe;
    int numero;
} carta;

#define TAM_BARALHO 54
carta baralho[TAM_BARALHO];

void trocar_cartas(int inicial, int final)
{
    carta temp = baralho[inicial];
    baralho[inicial] = baralho[final];
    baralho[final] = temp;
}

void main()
{
    srand(time(NULL));

    // INICIALIZAÇÃO
    for ( int i = 0; i < TAM_BARALHO; i++ )
    {
        baralho[i].naipe = naipes[rand() % 3];
        baralho[i].numero = rand() % 13 + 1; 
    }

    // ORDENANDO OS NAIPES
    int total_ordenado = 0;
    for ( int i = 0; i < TAM_NAIPES; i++ )
    {
        int pos_naipe = 0;
        for ( int j = total_ordenado; j < TAM_BARALHO; j++)
        {
            if ( baralho[j].naipe == naipes[i] )
            {
                trocar_cartas(j, pos_naipe);
                pos_naipe += 1;
            }
        }
    }
}