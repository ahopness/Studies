**17/03 - Banco de Dados - Modelagem de Dados**

- Muitas vezes chamadas de **mini-mundo**, um banco de dados reflete fatores presentes no mundo real, refeltindo mudanças e se adaptando para cumprir tarefas.

---

- Em um mundo perfeito, cada banco de dados, com seus dados e informações, são acessados de forma ordenada, sem conflitos e engasgos. No mundo real, como não podemos nos depender da civilidade dos programas tentando requerer nossas informações, temos que lidar com **Sistemas Gerenciadores de Bancos de Dados (SGBD, DBMS em inglês)**.

<div align="center">

<br>
<img height="250px" src="https://www.erp-information.com/wp-content/uploads/2021/01/database-management.png"></img>

***Componentes**: dados, metadados (logs), hardware (servidor), software (ex.: OracleSQL), Usuarios (Usuario final, Admin).*

</div>

---

### Modelos de dados

- *Modelos Físicos:* Descreve a implementação física tais
como arquivos, índices, etc.

- *Modelos Lógicos:* Descreve a implementação do modelo
conceitual a partir de uma SGBD.
  - Modelo Relacional: Dados conseguem se relacionar mesmo estando em tabelas diferentes, criando laços entre dados pre-existentes para evitar repetições.
  - Modelo Orientado a Objetos: Outro tipo de modelo relacional onde dados podem se mesclar dependendo de suas relações.

- *Modelos Conceituais:* Descreve e analisa um banco de dados de forma a planejar e modelar a estrutura dos dados e informações. •Para obtenção desse modelo, utilizamos o **Modelo Entidade Relacionamento (MER)**.