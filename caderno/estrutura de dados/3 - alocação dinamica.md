**26/03 - Algoritmos e Estrutura de Dados - Alocação Dinamica**

- Na criação de uma variavel de um tipo não tradicional, é necessario manipular sua memoria de forma além do que as ferramentas tradicionais nos possibilita.

---

### `malloc()` & `free()`: Partners in crime

```c
int arr[2] = { 1, 2, 3 }:
```

*Ex.1: Alocação Sequencial.*

```c
int* arr = malloc( sizeof(int) * 3 );
```

*Ex.2: Alocação Dinamica.*

<br>

- Para tipos tradicionais essa função se torna meio redundate, mas digamos que estamaos tentando criar um tipo novo usando `typedef`, onde a quantidade de memoria utilizada é um item que deve ser inspecionado com cautela, então um manuseio mais preciso da memoria usando `malloc` é necessario.

- Agora, se estamos alocando memoria manualmente, a linguaguem pede para liberar a mesma memoria manualmente, pois é assumido que a autoridade da memoria alocada agora é de sua autoridade:
  - Numa *alocação sequencial*:
    - Se a variavel for *local*, sua memoria vai ser liberada ao fim de uma função;
    - Se a variavel for *global*, sua memoria vai ser liberada ao fim do programa.
  - Numa *alocação dinamica*:
    - Sua memoria apenas pode ser liberada pelo proprio programa, ou pelo sistema operacional ao fim do programa.

<br>

```c
free( &arr );
```

*Ex.3: Liberação de memoria.*

- Quando o programa esta alocando memoria dinamicamente, muita das vezes ele vai querer fazer uma administração de memoria mais manual e precisa, mantendo apenas o endereço da memoria e utilizando o free com o mesmo para liberar a memoria no fim de uma rotina.

---

### Breaking News: Bonnie & Clyde *MORRERAM*!!!

<br>
<div align="center">
    <img height="250px" src="https://miro.medium.com/v2/resize:fit:720/1*2LP80A-JSDJu8uPN0fsMvg.png"></img>
    <br>
    <p>Ok, aqui começa o problema...</p>
</div>

- Toda vez que nós temos um tipo novo nós temos que nos preucupar com a manipulação de seus dados. *Para nossa alegria* temos uma checklist para verificar isso:
  - Inserir/Criar valores;
  - Deletar/Remover valores;
  - Buscar valores (se for um vetor);
  - Acessar valores;
  - Alterar valores;

- Se o programa conseguir fazer estas manipulações um novo tipo usando referencias, então ta tudo certo 👍, questão é fazer essas manipulações sem ter um estoro de memoria/segfault/off by one...