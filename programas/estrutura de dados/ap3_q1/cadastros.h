#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcionario.h"

funcionario* cadastros;
int num_cadastros = 0;

void adicionar_funcionario()
{
    funcionario novo_funcionario;

    novo_funcionario.id = num_cadastros;
    num_cadastros += 1;
    printf("\nNOVO FUNCIONARIO REGISTRADO NO ID %d\n", novo_funcionario.id);

    printf( "\nQual o nome do funcionario?\n");
    scanf( "%255s", novo_funcionario.nome );

    printf( "\nQual a data de nasciemnto do funcionario? (digite dia, mes e ano, cada um seguidos por enter)\n" );
    scanf( "%d", &novo_funcionario.data_de_nascimento.dia );
    scanf( "%d", &novo_funcionario.data_de_nascimento.mes );
    scanf( "%d", &novo_funcionario.data_de_nascimento.ano );

    printf( "\nQual a cargo horaria do funcionario?\n" );
    scanf( "%d", &novo_funcionario.carga_horario );

    printf( "\nQual o salario do funcionario?\n" );
    scanf( "%f", &novo_funcionario.salario );

    if (cadastros == NULL)
    {
        cadastros = (funcionario*) malloc( 1 * sizeof( funcionario ) );
    }
    else
    {
        cadastros = (funcionario*) realloc( cadastros, num_cadastros * sizeof( funcionario ) );
    }

    cadastros[novo_funcionario.id] = novo_funcionario;

    printf("\n");
}

void remover_funcionarios()
{
    if ( num_cadastros == 0 )
    {
        printf("\nA lista de funcionarios esta vazia, insira um novo funcionario primeiro...\n");
    }
    else
    {
        printf("\nDigite o ID do funcionario a ser deletado: "); 
        int id; scanf("%d", &id);
    
        int indice = -1;
        for ( int i = 0; i < num_cadastros; i++ )
        {
            if ( cadastros[i].id == id )
            {
                indice = i;
            }
        }
        
        if ( indice == -1 )
        {
            printf("Esse ID não pertence a nenhum funcionario, tente denovo.\n\n");
            return;
        }
    
        if ( num_cadastros == 1 )
        {
            free(cadastros);
            num_cadastros = 0;
        }
        else
        {
            for ( int i = indice; i < num_cadastros; i++ )
            {
                cadastros[i] = cadastros[i+1];
            }
            
            num_cadastros -= 1;
            cadastros = (funcionario*) realloc( cadastros, num_cadastros * sizeof( funcionario ) );
        }
        
        printf("Funcionario removido com sucesso.\n\n");
    }
}

void listar_funcionarios()
{
    if ( num_cadastros == 0 )
    {
        printf("\nA lista de funcionarios esta vazia, insira um novo funcionario primeiro...\n");
    }
    else
    {
        for ( int i = 0; i < num_cadastros; i++ )
        {
            printf("\n");
            printf("FUNCIONARIO # %d\n", cadastros[i].id);
            printf("Nome: %s\n", cadastros[i].nome);
            printf("Data de Nascimento: %d/%d/%d\n", cadastros[i].data_de_nascimento.dia, cadastros[i].data_de_nascimento.mes, cadastros[i].data_de_nascimento.ano);
            printf("Carga Horaria: %d horas semanais\n", cadastros[i].carga_horario);
            printf("Salario: R$%.00f/mes\n", cadastros[i].salario);
        }
    }

    printf("\n");
}