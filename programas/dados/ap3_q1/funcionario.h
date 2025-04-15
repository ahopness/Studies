typedef struct
{
    int dia;
    int mes;
    int ano;
} data;

typedef struct
{
    int id;
    char nome[255];
    data data_de_nascimento;
    int carga_horario; 
    float salario;
} funcionario;

