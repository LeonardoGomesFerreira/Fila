#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estrutura dos Alunos
struct tp_aluno{
int id;                     // Código interno do sistema
char nome[100];             // Nome completo
int idade;                  // Idade          
char telefone[20];          // Telefone para contato
struct tp_aluno *prox;      // Ponteiro para o próximo aluno
};

typedef struct tp_aluno Aluno;

// Ponteiros Globais
Aluno *inicio = NULL;
Aluno *fim = NULL;



// Função Limpar tela
void limparTela(){
    system("cls");   // Windows
}


// Função Inserir --- Insere sempre no final da fila
void Inserir() {

    // Aloca memória para um novo Aluno
    Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));

    if (aluno == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    // Perguntando os dados
    printf("Digite o ID do aluno: ");
    scanf("%d", &aluno->id);

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", aluno->nome);

    printf("Digite a idade do aluno: ");
    scanf("%d", &aluno->idade);

    printf("Digite o telefone do aluno: ");
    scanf(" %[^\n]", aluno->telefone);

    aluno->prox = NULL; // Novo aluno sempre aponta para NULL pois será o último da fila

    // Se a fila estiver vazia
    if(inicio == NULL){
        inicio = aluno; // O inicio da fila passa a ser o novo aluno
        fim = aluno;    // O fim da fila também passa a ser o novo aluno
    }
    else{
        fim->prox = aluno; // O antigo último aponta para o novo aluno
        fim = aluno;       // Atualiza o fim da fila
    }

    printf("\nAluno %s inserido com sucesso!\n", aluno->nome);
}


// Função Remover --- Remove sempre do inicio da fila
void Remover(){

    // Verifica se a fila está vazia
    if(inicio == NULL){
        printf("Fila Vazia!\n");
        return;
    }

    Aluno *temp = inicio;   // Guarda o primeiro aluno

    inicio = inicio->prox;  // O inicio passa a ser o próximo da fila

    // Se após remover a fila ficar vazia
    if(inicio == NULL){
        fim = NULL;
    }

    printf("Aluno %s removido com sucesso!\n", temp->nome);

    free(temp); // Libera a memória
}


// Função Listar --- Percorre a lista do inicio ate o fim --- mostra todas as informações dos alunos com as divisões
void Listar(){
Aluno *aux = inicio;

printf("\n====== Lista dos Alunos ======\n");

while(aux != NULL){
printf("========================================================\n");
printf("Id: %d | Nome: %s | Idade: %d | Telefone: %s\n", aux->id, aux->nome, aux->idade, aux->telefone);
printf("========================================================\n");
aux = aux->prox;
}
}


// Função Principal
int main(){
    setlocale(LC_ALL, "Portuguese");

    int escolha;

    do{
        printf("\n======= Menu =======\n");
        printf("1 - Inserir Aluno\n");
        printf("2 - Remover Aluno\n");
        printf("3 - Listar Alunos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        limparTela();

        switch(escolha){
            case 1:
                Inserir();
                break;

            case 2:
                Remover();
                break;

            case 3:
                Listar();
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

        printf("\nPressione ENTER para continuar...");
        getchar();
        getchar();

        limparTela();

    }while(escolha != 0);

    return 0;
}
