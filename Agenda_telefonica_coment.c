#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definições de tamanhos máximos para os campos das informações do contato
#define MAX_NOME 40
#define MAX_TELEFONE 15
#define MAX_CELULAR 15
#define MAX_EMAIL 40

// Estrutura para armazenar a data de aniversário (dia e mês)
typedef struct {
    int dia;
    int mes;
} Data;

// Estrutura para armazenar as informações do contato
typedef struct {
    char nome[MAX_NOME];
    char telefone[MAX_TELEFONE];
    char celular[MAX_CELULAR];
    char email[MAX_EMAIL];
    Data dataAniversario;
} Contato;

// Estrutura para os elementos da lista encadeada
typedef struct elemento {
    Contato info;          // Informações do contato
    struct elemento* prox; // Ponteiro para o próximo elemento da lista
} Elemento;

// Função para criar uma nova agenda (lista encadeada), inicializando-a como NULL
Elemento* cria_agenda() {
    return NULL;
}

// Função para inserir um novo contato na lista encadeada
void insere_contato(Elemento** lista, Contato novoContato) {
    // Aloca memória para o novo elemento
    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
    if (novoElemento == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    // Preenche as informações do novo elemento
    novoElemento->info = novoContato;
    novoElemento->prox = NULL;
    
    // Insere o novo elemento no final da lista
    if (*lista == NULL) {
        *lista = novoElemento; // Lista estava vazia
    } else {
        Elemento* temp = *lista;
        // Navega até o final da lista
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        // Anexa o novo elemento ao final da lista
        temp->prox = novoElemento;
    }
}

// Função para listar todos os contatos na lista
void lista_contatos(Elemento* lista) {
    Elemento* temp = lista;
    // Percorre a lista e imprime as informações de cada contato
    while (temp != NULL) {
        printf("Nome: %s\n", temp->info.nome);
        printf("Telefone: %s\n", temp->info.telefone);
        printf("Celular: %s\n", temp->info.celular);
        printf("Email: %s\n", temp->info.email);
        printf("Data de Aniversário: %02d/%02d\n", temp->info.dataAniversario.dia, temp->info.dataAniversario.mes);
        printf("----------------------------\n\n");
        temp = temp->prox;
    }
}

// Função para buscar um contato pelo nome na lista
Elemento* busca_contato(Elemento* lista, const char* nome) {
    Elemento* temp = lista;
    // Percorre a lista procurando pelo nome do contato
    while (temp != NULL) {
        if (strcmp(temp->info.nome, nome) == 0) {
            return temp; // Contato encontrado
        }
        temp = temp->prox;
    }
    return NULL; // Contato não encontrado
}

// Função para remover um contato pelo nome da lista
void remove_contato(Elemento** lista, const char* nome) {
    Elemento* temp = *lista;
    Elemento* anterior = NULL;

    // Percorre a lista procurando pelo nome do contato
    while (temp != NULL && strcmp(temp->info.nome, nome) != 0) {
        anterior = temp;
        temp = temp->prox;
    }

    // Verifica se o contato foi encontrado
    if (temp == NULL) {
        printf("Contato não encontrado.\n");
        return;
    }

    // Ajusta o ponteiro do anterior para pular o contato a ser removido
    if (anterior == NULL) {
        *lista = temp->prox; // Contato a ser removido é o primeiro da lista
    } else {
        anterior->prox = temp->prox;
    }

    // Libera a memória do contato removido
    free(temp);
    printf("Contato removido.\n");
}

// Função para atualizar as informações de um contato
void atualiza_contato(Elemento* lista, const char* nome) {
    Elemento* contato = busca_contato(lista, nome);
    if (contato == NULL) {
        printf("Contato não encontrado.\n");
        return;
    }

    // Solicita e lê novos dados para o contato
    printf("Digite o novo telefone: ");
    fgets(contato->info.telefone, MAX_TELEFONE, stdin);
    contato->info.telefone[strcspn(contato->info.telefone, "\n")] = '\0';

    printf("Digite o novo celular: ");
    fgets(contato->info.celular, MAX_CELULAR, stdin);
    contato->info.celular[strcspn(contato->info.celular, "\n")] = '\0';

    printf("Digite o novo email: ");
    fgets(contato->info.email, MAX_EMAIL, stdin);
    contato->info.email[strcspn(contato->info.email, "\n")] = '\0';

    printf("Digite o novo dia do aniversário: ");
    scanf("%d", &contato->info.dataAniversario.dia);
    printf("Digite o novo mês do aniversário: ");
    scanf("%d", &contato->info.dataAniversario.mes);
    getchar(); // Limpa o buffer do teclado
}

// Função principal do programa
int main() {
    Elemento* agenda = cria_agenda(); // Cria a lista encadeada inicial
    int opcao;
    char nome[MAX_NOME];
    Contato novoContato;

    do {
        // Exibe o menu de opções
        printf("\nMenu:\n\n");
        printf("1. Inserir Contato\n");
        printf("2. Listar Contatos\n");
        printf("3. Buscar Contato\n");
        printf("4. Editar Contato\n");
        printf("5. Remover Contato\n");
        printf("6. Sair\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                // Insere um novo contato
                printf("Digite o nome: ");
                fgets(novoContato.nome, MAX_NOME, stdin);
                novoContato.nome[strcspn(novoContato.nome, "\n")] = '\0';
                
                printf("Digite o telefone: ");
                fgets(novoContato.telefone, MAX_TELEFONE, stdin);
                novoContato.telefone[strcspn(novoContato.telefone, "\n")] = '\0';

                printf("Digite o celular: ");
                fgets(novoContato.celular, MAX_CELULAR, stdin);
                novoContato.celular[strcspn(novoContato.celular, "\n")] = '\0';

                printf("Digite o email: ");
                fgets(novoContato.email, MAX_EMAIL, stdin);
                novoContato.email[strcspn(novoContato.email, "\n")] = '\0';

                printf("Digite o dia do aniversário: ");
                scanf("%d", &novoContato.dataAniversario.dia);
                printf("Digite o mês do aniversário: ");
                scanf("%d", &novoContato.dataAniversario.mes);
                getchar(); // Limpa o buffer do teclado
                
                // Insere o contato na agenda
                insere_contato(&agenda, novoContato);
                break;

            case 2:
                // Lista todos os contatos
                lista_contatos(agenda);
                break;

            case 3:
                // Busca um contato pelo nome e exibe suas informações
                printf("Digite o nome do contato a buscar: ");
                fgets(nome, MAX_NOME, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                Elemento* contatoBuscado = busca_contato(agenda, nome);
                if (contatoBuscado) {
                    printf("Contato encontrado:\n\n");
                    printf("Nome: %s\n", contatoBuscado->info.nome);
                    printf("Telefone: %s\n", contatoBuscado->info.telefone);
                    printf("Celular: %s\n", contatoBuscado->info.celular);
                    printf("Email: %s\n", contatoBuscado->info.email);
                    printf("Data de Aniversário: %02d/%02d\n", contatoBuscado->info.dataAniversario.dia, contatoBuscado->info.dataAniversario.mes);
                } else {
                    printf("Contato não encontrado.\n");
                }
                break;

            case 4:
                // Atualiza as informações de um contato
                printf("Digite o nome do contato a editar: ");
                fgets(nome, MAX_NOME, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                atualiza_contato(agenda, nome);
                break;

            case 5:
                // Remove um contato pelo nome
                printf("Digite o nome do contato a remover: ");
                fgets(nome, MAX_NOME, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                remove_contato(&agenda, nome);
                break;

            case 6:
                // Encerra o programa
                printf("Saindo...\n");
                break;

            default:
                // Trata opções inválidas
                printf("Opção inválida. Tente novamente.\n");
                break;
        }

    } while (opcao != 6); // Repete até que o usuário escolha a opção de sair

    // Libera a memória usada pela lista antes de sair
    Elemento* temp;
    while (agenda != NULL) {
        temp = agenda;
        agenda = agenda->prox;
        free(temp);
    }

    return 0; // Termina o programa com sucesso
}
