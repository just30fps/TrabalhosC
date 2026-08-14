#include <stdio.h>
#include <string.h>


typedef struct {
    char descricao[50];
    float valor;
    int mes;
    int ano;
} Despesa;

void menu() {
    printf("\n--- CADASTRO DE DESPESAS ---\n");
    printf("1. Incluir Despesa\n");
    printf("2. Pesquisar Despesa\n");
    printf("3. Listar Despesas\n");
    printf("4. Alterar Despesa\n");
    printf("5. Excluir Despesa\n");
    printf("0. Sair\n");
}

// Funcao auxiliar para retornar o indice da despesa ou -1 se nao encontrar
int buscarDespesa(Despesa d[], int total, char desc[]) {
    for(int i = 0; i < total; i++) {
        if(strcmp(d[i].descricao, desc) == 0) {
            return i; 
        }
    }
    return -1; 
}

// Inclusao de Despesa
void incluirDespesa(Despesa d[], int *total, int limite) {
    if (*total >= limite) { // Valida o limite definido pelo usuario
        printf("\nErro: Limite de cadastro atingido!\n");
        return;
    }

    char desc[50];
    printf("\nDigite a descricao da despesa: ");
    scanf(" %[^\n]", desc);

    // Impede descricoes duplicadas
    if(buscarDespesa(d, *total, desc) != -1) {
        printf("\nErro: Ja existe uma despesa com essa descricao!\n");
        return;
    }

    // Armazena os dados no vetor 
    strcpy(d[*total].descricao, desc);
    printf("Digite o valor: R$ ");
    scanf("%f", &d[*total].valor);

    do {
        printf("Digite o mes (1-12): ");
        scanf("%d", &d[*total].mes);
        if (d[*total].mes < 1 || d[*total].mes > 12) {
            printf("Mes invalido! Digite um valor entre 1 e 12.\n");
        }
    } while (d[*total].mes < 1 || d[*total].mes > 12);

    printf("Digite o ano: ");
    scanf("%d", &d[*total].ano);

    (*total)++; // Incrementa o total cadastrado
    printf("\nDespesa incluida com sucesso!\n");
}


// Pesquisa de Despesa
void pesquisarDespesa(Despesa d[], int total) {
    char desc[50];
    printf("\nDigite a descricao para pesquisar: ");
    scanf(" %[^\n]", desc);

    int indice = buscarDespesa(d, total, desc);

    if(indice != -1) {
        printf("\n--- Dados da Despesa ---\n");
        printf("Descricao: %s\n", d[indice].descricao);
        printf("Valor: R$ %.2f\n", d[indice].valor);
        printf("Data: %02d/%d\n", d[indice].mes, d[indice].ano);
    } else {
        printf("\nDespesa nao encontrada.\n");
    }
}

// Listagem de Despesas
void listarDespesas(Despesa d[], int total) {
    if(total == 0) {
        printf("\nNenhuma despesa cadastrada.\n");
        return;
    }

    printf("\n LISTA DE DESPESAS CADASTRADAS \n");
    for(int i = 0; i < total; i++) {
        printf("%d. %s | R$ %.2f | %02d/%d\n", i+1, d[i].descricao, d[i].valor, d[i].mes, d[i].ano);
    }
}

// Alteracao de Despesa
void alterarDespesa(Despesa d[], int total) {
    char desc[50];
    printf("\nDigite a descricao da despesa que deseja alterar: ");
    scanf(" %[^\n]", desc);

    int indice = buscarDespesa(d, total, desc);

    if(indice != -1) {
        
        printf("\nDados atuais: %s | R$ %.2f | %02d/%d\n", d[indice].descricao, d[indice].valor, d[indice].mes, d[indice].ano);

        
        printf("\nDigite o novo valor: R$ ");
        scanf("%f", &d[indice].valor);

        do {
            printf("Digite o novo mes (1-12): ");
            scanf("%d", &d[indice].mes);
            if (d[indice].mes < 1 || d[indice].mes > 12) {
                printf("Mes invalido! Digite um valor entre 1 e 12.\n");
            }
        } while (d[indice].mes < 1 || d[indice].mes > 12);

        printf("Digite o novo ano: ");
        scanf("%d", &d[indice].ano);

        printf("\nDespesa alterada com sucesso!\n");
    } else {
        printf("\nDespesa nao encontrada.\n");
    }
}

// Exclusao de Despesa
void excluirDespesa(Despesa d[], int *total) {
    char desc[50];
    printf("\nDigite a descricao da despesa que deseja excluir: ");
    scanf(" %[^\n]", desc);

    int indice = buscarDespesa(d, *total, desc);

    if(indice != -1) {
        // Exibe dados antes de excluir
        printf("\nDados da despesa: %s | R$ %.2f | %02d/%d\n", d[indice].descricao, d[indice].valor, d[indice].mes, d[indice].ano);

        char confirma;
        printf("Tem certeza que deseja excluir? (S/N): ");
        scanf(" %c", &confirma);

        if(confirma == 'S' || confirma == 's') {
            // Move os elementos para tras para eliminar o registro
            for(int i = indice; i < (*total) - 1; i++) {
                d[i] = d[i + 1];
            }
            (*total)--; // Reduz o tamanho ocupado
            printf("\nDespesa excluida com sucesso!\n");
        } else {
            printf("\nExclusao cancelada. Registro mantido.\n");
        }
    } else {
        printf("\nDespesa nao encontrada.\n");
    }
}

int main() {
    int limite;

    printf("Defina a capacidade maxima do cadastro: ");
    scanf("%d", &limite);

    Despesa cadastro[limite]; 
    int totalDespesas = 0;    
    int opcao;

    do {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: incluirDespesa(cadastro, &totalDespesas, limite); break;
            case 2: pesquisarDespesa(cadastro, totalDespesas); break;
            case 3: listarDespesas(cadastro, totalDespesas); break;
            case 4: alterarDespesa(cadastro, totalDespesas); break;
            case 5: excluirDespesa(cadastro, &totalDespesas); break;
            case 0: printf("\nSaindo do programa...\n"); break;
            default: printf("\nOpcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}
