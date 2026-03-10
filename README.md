# 📚 Sistema de Gerenciamento de Alunos em C

Este projeto implementa um **sistema de gerenciamento de alunos** utilizando **estrutura de dados dinâmica** na linguagem **C**.

O programa permite:

- ➕ Inserir alunos
- ➖ Remover alunos
- 📋 Listar alunos cadastrados

O objetivo principal é demonstrar o funcionamento de **listas encadeadas** e da estrutura de dados **Fila (Queue)** utilizando **alocação dinâmica de memória**.

---

# 🧠 Conceitos Utilizados

Este projeto utiliza alguns conceitos importantes da programação em C:

- Estruturas (`struct`)
- Ponteiros
- Listas encadeadas
- Alocação dinâmica de memória
- Estrutura de dados **Fila (FIFO)**

---

# 👨‍🎓 Estrutura do Aluno

A estrutura principal do sistema representa um aluno.

```c
struct tp_aluno{
    int id;                     
    char nome[100];             
    int idade;                  
    char telefone[20];          
    struct tp_aluno *prox;      
};
```

### Campos da estrutura

| Campo | Descrição |
|------|-----------|
| `id` | Código identificador do aluno |
| `nome` | Nome completo |
| `idade` | Idade do aluno |
| `telefone` | Telefone para contato |
| `prox` | Ponteiro para o próximo aluno |

O campo `prox` permite conectar os alunos formando uma **lista encadeada**.

---

# 🔗 Lista Encadeada

Uma **lista encadeada** é uma estrutura de dados onde cada elemento aponta para o próximo.

### Representação visual

```
[inicio]
   ↓
[Aluno1] → [Aluno2] → [Aluno3] → NULL
                               ↑
                              [fim]
```

- `inicio` aponta para o primeiro elemento
- `fim` aponta para o último elemento

---

# 📥 Estrutura de Fila (Queue)

O programa utiliza a estrutura **Fila**.

Fila funciona com o princípio:

**FIFO — First In, First Out**

Ou seja:

> O primeiro que entra é o primeiro que sai.

### Exemplo

```
Entrada → [Aluno1] [Aluno2] [Aluno3] → Saída
```

Operações principais:

| Operação | Descrição |
|--------|--------|
| Enqueue | Inserir elemento na fila |
| Dequeue | Remover elemento da fila |

---

# ⚙️ Ponteiros Globais

O programa utiliza dois ponteiros globais:

```c
Aluno *inicio = NULL;
Aluno *fim = NULL;
```

| Ponteiro | Função |
|---------|--------|
| `inicio` | Aponta para o primeiro aluno da fila |
| `fim` | Aponta para o último aluno da fila |

---

# ➕ Função Inserir()

A função `Inserir()` adiciona um aluno **no final da fila**.

### Etapas

1. Alocar memória para o novo aluno

```c
Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));
```

2. Receber os dados do usuário
3. Definir `prox = NULL`
4. Inserir o aluno no final da fila

### Lógica

Se a fila estiver vazia:

```
inicio = aluno
fim = aluno
```

Caso contrário:

```
fim->prox = aluno
fim = aluno
```

---

# ➖ Função Remover()

A função `Remover()` remove o **primeiro aluno da fila**.

### Etapas

1. Verifica se a fila está vazia
2. Guarda o primeiro aluno em uma variável temporária
3. Move o ponteiro `inicio`
4. Libera a memória

```c
free(temp);
```

### Exemplo

Antes:

```
inicio → Aluno1 → Aluno2 → Aluno3
```

Depois:

```
inicio → Aluno2 → Aluno3
```

---

# 📋 Função Listar()

A função `Listar()` percorre toda a fila exibindo os alunos cadastrados.

### Código de percurso

```c
Aluno *aux = inicio;

while(aux != NULL){
    printf("Id: %d | Nome: %s | Idade: %d | Telefone: %s\n",
           aux->id, aux->nome, aux->idade, aux->telefone);
    aux = aux->prox;
}
```

Esse processo continua até encontrar `NULL`, que indica o final da lista.

---

# 🖥️ Menu do Sistema

O programa possui um menu interativo no terminal:

```
1 - Inserir Aluno
2 - Remover Aluno
3 - Listar Alunos
0 - Sair
```

Cada opção executa uma função do sistema.

---

# 🧱 Estrutura de Dados: Pilha (Stack)

Além da fila, outra estrutura muito comum é a **Pilha**.

A pilha segue o princípio:

**LIFO — Last In, First Out**

Ou seja:

> O último que entra é o primeiro que sai.

### Exemplo

```
Topo
 ↓
[3]
[2]
[1]
```

Operações principais:

| Operação | Descrição |
|--------|--------|
| Push | Inserir elemento |
| Pop | Remover elemento |

---

# 📊 Diferença entre Fila e Pilha

| Estrutura | Regra | Inserção | Remoção |
|----------|------|--------|--------|
| Pilha | LIFO | Topo | Topo |
| Fila | FIFO | Final | Início |

---

# 🛠️ Tecnologias Utilizadas

- Linguagem **C**
- **Listas Encadeadas**
- **Alocação dinâmica de memória**
- Estrutura de dados **Fila**

---

# 🎯 Objetivo do Projeto

Este projeto foi desenvolvido para praticar conceitos fundamentais de:

- Programação em **C**
- Manipulação de **ponteiros**
- **Estruturas de dados**
- **Listas encadeadas**
- **Gerenciamento de memória**

---

# 🚀 Possíveis Melhorias

Algumas melhorias futuras que podem ser adicionadas:

- 🔎 Buscar aluno por ID
- ✏️ Editar dados do aluno
- 💾 Salvar dados em arquivo
- 🧾 Interface mais amigável
- ✔️ Validação de entrada de dados

---

# 👨‍💻 Autor

Projeto desenvolvido para fins de estudo em **Estrutura de Dados utilizando C**.
