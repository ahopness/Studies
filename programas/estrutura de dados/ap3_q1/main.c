#include <stdio.h>
#include <stdlib.h>

#include "cadastros.h"

int main()
{
    printf("### SUPER MEGA BANCO DE DADOS FUNCIONAL 3000 ###\n\n");
    
    int escolha = 0;
    while(1)
    {
        //printf("\e[1;1H\e[2J");
        printf("Lista de comandos:\n");
        printf("- Adicionar novo funcionario: 1\n");
        printf("- Remover funcionario: 2\n");
        printf("- Listar funcionarios: 3\n");
        printf("- Fechar app: 4\n\n");
        printf("Aguardando input... ");
        scanf("%d", &escolha);

        switch (escolha)
        {
            case 1:
                adicionar_funcionario();
                break;
            case 2:
                remover_funcionarios();
                break;
            case 3:
                listar_funcionarios();
                break;
            case 4:
                free(cadastros);
                return 0;
                break;
            default:
                continue;
                break;
        }

    }
}