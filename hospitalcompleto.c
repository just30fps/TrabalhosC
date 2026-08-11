#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char nome[100];
    char especialidade[50];
    int ativom;
} medico;

typedef struct{
    int id;
    char nome[100];
    char rg[50];
    char end[100];
    char tel[50];
    char sexo[20];
    int ativop;
} paciente;

typedef struct{
    int numero;
    int medicoid;
    int pacienteid;
    char horario[6];
    int duracao;
    char data[20];
    int ativoc;
} consulta;

void inc_medico(medico **listam, int *qmedico){
    medico *temp = (medico*) realloc(*listam, (*qmedico + 1) * sizeof(medico));

    if (temp == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    *listam = temp;

    printf("Digite o identificador do medico:");
    scanf("%d", &(*listam)[*qmedico].id);
    printf("\nDigite o nome do medico:");
    scanf(" %[^\n]", (*listam)[*qmedico].nome);
    printf("\nDigite a especialidade do medico:");
    scanf(" %[^\n]", (*listam)[*qmedico].especialidade);
    (*listam)[*qmedico].ativom = 1;
    (*qmedico)++;
    printf("\nMedico cadastrado!\n");
}

void inc_paciente(paciente **listap, int *qpaciente){
    paciente *temp = (paciente*) realloc(*listap, (*qpaciente + 1) * sizeof(paciente));

    if (temp == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    *listap = temp;

    printf("Digite o identificador do paciente:");
    scanf("%d", &(*listap)[*qpaciente].id);
    printf("\nDigite o nome do paciente:");
    scanf(" %[^\n]", (*listap)[*qpaciente].nome);
    printf("\nDigite a identidade do paciente:");
    scanf(" %[^\n]", (*listap)[*qpaciente].rg);
    printf("\nDigite o endereco do paciente:");
    scanf(" %[^\n]", (*listap)[*qpaciente].end);
    printf("\nDigite o telefone do paciente:");
    scanf(" %[^\n]", (*listap)[*qpaciente].tel);
    printf("\nDigite o sexo do paciente:");
    scanf(" %[^\n]", (*listap)[*qpaciente].sexo);
    (*listap)[*qpaciente].ativop = 1;
    (*qpaciente)++;
    printf("\nPaciente cadastrado!\n");
}

void inc_consulta(consulta **listac, int *qconsulta, medico *listam, int qmedico, paciente *listap, int qpaciente){
    int id_med_temp, id_pac_temp;
    int med_ok = 0, pac_ok = 0;

    printf("Digite o identificador do medico:");
    scanf("%d", &id_med_temp);

    for(int i = 0; i < qmedico; i++){
        if(listam[i].id == id_med_temp && listam[i].ativom == 1){
            med_ok = 1;
            break;
        }
    }

    if(med_ok == 0){
        printf("Erro: Medico nao encontrado ou inativo!\n");
        return;
    }

    printf("\nDigite o identificador do paciente:");
    scanf("%d", &id_pac_temp);

    for(int i = 0; i < qpaciente; i++){
        if(listap[i].id == id_pac_temp && listap[i].ativop == 1){
            pac_ok = 1;
            break;
        }
    }

    if(pac_ok == 0){
        printf("Erro: Paciente nao encontrado ou inativo!\n");
        return;
    }

    consulta *temp = (consulta*) realloc(*listac, (*qconsulta + 1) * sizeof(consulta));

    if (temp == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    *listac = temp;

    (*listac)[*qconsulta].medicoid = id_med_temp;
    (*listac)[*qconsulta].pacienteid = id_pac_temp;

    printf("\nDigite o numero da consulta:");
    scanf("%d", &(*listac)[*qconsulta].numero);
    printf("\nDigite o horario da consulta:");
    scanf(" %[^\n]", (*listac)[*qconsulta].horario);
    printf("\nDigite a data da consulta:");
    scanf(" %[^\n]", (*listac)[*qconsulta].data);
    printf("\nDigite a duracao da consulta:");
    scanf("%d", &(*listac)[*qconsulta].duracao);
    (*listac)[*qconsulta].ativoc = 1;
    (*qconsulta)++;
    printf("\nConsulta cadastrada com sucesso!\n");
}

void excluir_paciente(paciente listap[], int tamanho_lista, int id, consulta listac[], int tamanho_listac){
    int encontrado = 0;

    for (int i = 0; i < tamanho_lista; i++)
    {
        if (listap[i].id == id)
        {
            encontrado = 1;

            if (listap[i].ativop == 1)
            {
                int consultasexcluidas = 0;

                for (int j = 0; j < tamanho_listac; j++){
                   if (listac[j].pacienteid == id && listac[j].ativoc == 1 ){
                    listac[j].ativoc = 0;
                    consultasexcluidas++;
                   }
                }

                listap[i].ativop = 0;

                printf("Paciente excluido com sucesso! Total de consultas canceladas: %d\n", consultasexcluidas);
                break;
            }
            else {
                printf("Paciente ja excluido!\n");
                break;
            }
        }
    }

    if (encontrado == 0)
    {
        printf("ID do paciente nao encontrado!\n");
    }
    return;
}

void excluir_consulta(consulta listac[], int tamanho_lista, int num){
    int encontrado = 0;
    for (int i = 0; i < tamanho_lista; i++)
    {
        if (listac[i].numero == num)
        {
            encontrado = 1;
            if (listac[i].ativoc == 1)
            {
                printf("\nDados da consulta a ser excluida:\n");
                printf("\nNumero da consulta: %d", listac[i].numero);
                printf("\nIdentificador do medico: %d", listac[i].medicoid);
                printf("\nIdentificador do paciente: %d", listac[i].pacienteid);
                printf("\nHorario da consulta: %s", listac[i].horario);
                printf("\nData da consulta: %s", listac[i].data);
                printf("\nDuracao da consulta: %d", listac[i].duracao);
                listac[i].ativoc = 0;
                printf("\nConsulta excluida com sucesso!\n");
                break;
            }else {
                printf("Consulta ja excluida!\n");
                break;
            }
        }
    }
    if (encontrado == 0)
    {
        printf("Numero da consulta nao encontrado!\n");
    }
    return;
}

void excluir_medico(medico listam[], int tamanho_lista, int id, consulta listac[], int tamanho_listac){
    int encontrado = 0;

    for (int i = 0; i < tamanho_lista; i++)
    {
        if (listam[i].id == id)
        {
            encontrado = 1;

            if (listam[i].ativom == 1)
            {
                int consultasexcluidas = 0;

                for (int j = 0; j < tamanho_listac; j++){
                   if (listac[j].medicoid == id && listac[j].ativoc == 1 ){
                    listac[j].ativoc = 0;
                    consultasexcluidas++;
                   }
                }

                listam[i].ativom = 0;

                printf("Medico excluido com sucesso! Total de consultas canceladas: %d\n", consultasexcluidas);
                break;
            }
            else {
                printf("Medico ja excluido!\n");
                break;
            }
        }
    }

    if (encontrado == 0)
    {
        printf("ID do medico nao encontrado!\n");
    }
    return;
}

void alterar_paciente(paciente listap[], int totalP, int idpaciente){
    int indice_encontrado = -1;

    for (int i = 0; i < totalP; i++)
    {
        if (listap[i].ativop && listap[i].id == idpaciente)
        {
            indice_encontrado = i;
            break;
        }

    }
    if (indice_encontrado == -1) {
    printf("Paciente nao encontrado!\n");
    return;
    }
    printf("ID: %d\n", listap[indice_encontrado].id);
    printf("Nome: %s\n", listap[indice_encontrado].nome);
    printf("RG: %s\n", listap[indice_encontrado].rg);
    printf("Endereco: %s\n", listap[indice_encontrado].end);
    printf("Telefone: %s\n", listap[indice_encontrado].tel);
    printf("Sexo: %s\n", listap[indice_encontrado].sexo);
    printf("Status: %d\n", listap[indice_encontrado].ativop);
    int opcao;

    do {
        printf("\nOPCOES DE ALTERACAO\n");
        printf("1 - Alterar Nome\n");
        printf("2 - Alterar RG\n");
        printf("3 - Alterar Endereco\n");
        printf("4 - Alterar Telefone\n");
        printf("5 - Alterar Sexo\n");
        printf("6 - Finalizar Alteracoes\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o novo nome: ");
                scanf(" %[^\n]", listap[indice_encontrado].nome);
                printf("Nome atualizado com sucesso!\n");
                break;

            case 2:
                printf("Digite o novo RG: ");
                scanf(" %[^\n]", listap[indice_encontrado].rg);
                printf("RG atualizado com sucesso!\n");
                break;

            case 3:
                printf("Digite o novo endereco: ");
                scanf(" %[^\n]", listap[indice_encontrado].end);
                printf("Endereco atualizado com sucesso!\n");
                break;

            case 4:
                printf("Digite o novo telefone: ");
                scanf(" %[^\n]", listap[indice_encontrado].tel);
                printf("Telefone atualizado com sucesso!\n");
                break;

            case 5:
                printf("Digite o novo sexo: ");
                scanf(" %[^\n]", listap[indice_encontrado].sexo);
                printf("Sexo atualizado com sucesso!\n");
                break;

            case 6:
                printf("Saindo da edicao...\n");
                break;

            default:
                printf("Opcao invalida...\n");
        }

    } while (opcao != 6);
}

void alterar_medico(medico listam[], int totalM, int idmedico){
    int indice_encontrado = -1;

    for (int i = 0; i < totalM; i++)
    {
        if (listam[i].ativom && listam[i].id == idmedico)
        {
            indice_encontrado = i;
            break;
        }
    }

    if (indice_encontrado == -1) {
        printf("Medico nao encontrado!\n");
        return;
    }

    printf("ID: %d\n", listam[indice_encontrado].id);
    printf("Nome: %s\n", listam[indice_encontrado].nome);
    printf("Especialidade: %s\n", listam[indice_encontrado].especialidade);
    printf("Status: %d\n", listam[indice_encontrado].ativom);

    int opcao;

    do {
        printf("\nMENU DE ALTERACAO\n");
        printf("1 - Alterar Nome\n");
        printf("2 - Alterar Especialidade\n");
        printf("0 - Finalizar Alteracoes\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o novo nome: ");
                scanf(" %[^\n]", listam[indice_encontrado].nome);
                printf("Nome atualizado com sucesso!\n");
                break;

            case 2:
                printf("Digite a nova especialidade: ");
                scanf(" %[^\n]", listam[indice_encontrado].especialidade);
                printf("Especialidade atualizada com sucesso!\n");
                break;

            case 0:
                printf("Saindo da edicao...\n");
                break;

            default:
                printf("Opcao invalida...\n");
        }

    } while (opcao != 0);
}

void alterar_consulta(consulta listac[], int totalC, int numero_consulta){
    int indice_encontrado = -1;

    for (int i = 0; i < totalC; i++)
    {
        if (listac[i].ativoc && listac[i].numero == numero_consulta)
        {
            indice_encontrado = i;
            break;
        }
    }

    if (indice_encontrado == -1) {
        printf("Consulta nao encontrada!\n");
        return;
    }

    printf("Numero Consulta: %d\n", listac[indice_encontrado].numero);
    printf("ID Medico: %d\n", listac[indice_encontrado].medicoid);
    printf("ID Paciente: %d\n", listac[indice_encontrado].pacienteid);
    printf("Data: %s\n", listac[indice_encontrado].data);
    printf("Horario: %s\n", listac[indice_encontrado].horario);
    printf("Duracao: %d min\n", listac[indice_encontrado].duracao);

    int opcao;

    do {
        printf("\nMENU DE ALTERACAO\n");
        printf("1. Alterar ID do Medico\n");
        printf("2. Alterar ID do Paciente\n");
        printf("3. Alterar Data\n");
        printf("4. Alterar Horario\n");
        printf("5. Alterar Duracao\n");
        printf("0. Finalizar Alteracoes\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o novo ID do Medico: ");
                scanf("%d", &listac[indice_encontrado].medicoid);
                printf("Medico atualizado! (Verifique se o ID existe)\n");
                break;

            case 2:
                printf("Digite o novo ID do Paciente: ");
                scanf("%d", &listac[indice_encontrado].pacienteid);
                printf("Paciente atualizado! (Verifique se o ID existe)\n");
                break;

            case 3:
                printf("Digite a nova Data (DD/MM/AAAA): ");
                scanf(" %[^\n]", listac[indice_encontrado].data);
                printf("Data atualizada com sucesso!\n");
                break;

            case 4:
                printf("Digite o novo Horario (HH:MM): ");
                scanf(" %[^\n]", listac[indice_encontrado].horario);
                printf("Horario atualizado com sucesso!\n");
                break;

            case 5:
                printf("Digite a nova Duracao (minutos): ");
                scanf("%d", &listac[indice_encontrado].duracao);
                printf("Duracao atualizada com sucesso!\n");
                break;

            case 0:
                printf("Saindo da edicao...\n");
                break;

            default:
                printf("Opcao invalida...\n");
        }

    } while (opcao != 0);
}

void pesquisar_paciente(paciente listap[], int tamanho_lista, int id){
    int encontrado = 0;

    for (int i = 0; i < tamanho_lista; i++) {
        if (listap[i].id == id && listap[i].ativop == 1) {
            encontrado = 1;
            printf("\n--- DADOS DO PACIENTE ---\n");
            printf("ID: %d\n", listap[i].id);
            printf("Nome: %s\n", listap[i].nome);
            printf("RG: %s\n", listap[i].rg);
            printf("Endereco: %s\n", listap[i].end);
            printf("Telefone: %s\n", listap[i].tel);
            printf("Sexo: %s\n", listap[i].sexo);
            break;
        }
    }

    if (!encontrado) {
        printf("Paciente com ID %d nao encontrado ou inativo.\n", id);
    }
}

void pesquisar_medico(medico listam[], int tamanho_lista, int id){
    int encontrado = 0;

    for (int i = 0; i < tamanho_lista; i++) {
        if (listam[i].id == id && listam[i].ativom == 1) {
            encontrado = 1;
            printf("\nDADOS DO MEDICO\n");
            printf("ID: %d\n", listam[i].id);
            printf("Nome: %s\n", listam[i].nome);
            printf("Especialidade: %s\n", listam[i].especialidade);
            break;
        }
    }

    if (!encontrado) {
        printf("Medico com ID %d nao encontrado ou inativo.\n", id);
    }
}

void pesquisar_consulta(consulta listac[], int tamanho_lista, int numero){
    int encontrado = 0;

    for (int i = 0; i < tamanho_lista; i++) {
        if (listac[i].numero == numero && listac[i].ativoc == 1) {
            encontrado = 1;
            printf("\nDADOS DA CONSULTA\n");
            printf("Numero: %d\n", listac[i].numero);
            printf("ID Medico: %d\n", listac[i].medicoid);
            printf("ID Paciente: %d\n", listac[i].pacienteid);
            printf("Data: %s\n", listac[i].data);
            printf("Horario: %s\n", listac[i].horario);
            printf("Duracao: %d min\n", listac[i].duracao);
            break;
        }
    }

    if (!encontrado) {
        printf("Consulta numero %d nao encontrada ou cancelada.\n", numero);
    }
}


void relatorio_paciente_consultas(consulta listac[], int qconsulta){
    int id_pac, encontrados = 0;
    printf("\nDigite o ID do paciente para buscar consultas: ");
    scanf("%d", &id_pac);

    printf("\n--- CONSULTAS DO PACIENTE %d ---\n", id_pac);
    for(int i = 0; i < qconsulta; i++){
        if(listac[i].pacienteid == id_pac && listac[i].ativoc == 1){
            printf("Consulta: %d | Data: %s | Horario: %s | Medico ID: %d\n",
                listac[i].numero, listac[i].data, listac[i].horario, listac[i].medicoid);
            encontrados++;
        }
    }
    if(encontrados == 0){
        printf("Nenhuma consulta encontrada para este paciente.\n");
    }
}

void relatorio_medico_consultas(consulta listac[], int qconsulta){
    int id_med, encontrados = 0;
    printf("\nDigite o ID do medico para buscar consultas: ");
    scanf("%d", &id_med);

    printf("\n--- CONSULTAS DO MEDICO %d ---\n", id_med);
    for(int i = 0; i < qconsulta; i++){
        if(listac[i].medicoid == id_med && listac[i].ativoc == 1){
            printf("Consulta: %d | Data: %s | Horario: %s | Paciente ID: %d\n",
                listac[i].numero, listac[i].data, listac[i].horario, listac[i].pacienteid);
            encontrados++;
        }
    }
    if(encontrados == 0){
        printf("Nenhuma consulta encontrada para este medico.\n");
    }
}


void relatorio_especialidade_pacientes(medico listam[], int qmedico, consulta listac[], int qconsulta, paciente listap[], int qpaciente){
    char busca_especialidade[50];
    int total_encontrados = 0;

    printf("\nDigite a especialidade a pesquisar: ");
    scanf(" %[^\n]", busca_especialidade);

    printf("\n--- PACIENTES ATENDIDOS POR: %s ---\n", busca_especialidade);

    for(int i = 0; i < qmedico; i++){
        if(listam[i].ativom == 1 && strcmp(listam[i].especialidade, busca_especialidade) == 0){

            int id_med_atual = listam[i].id;

            for(int j = 0; j < qconsulta; j++){
                if(listac[j].ativoc == 1 && listac[j].medicoid == id_med_atual){

                    int id_pac_atual = listac[j].pacienteid;


                    for(int k = 0; k < qpaciente; k++){
                        if(listap[k].ativop == 1 && listap[k].id == id_pac_atual){
                            printf("- Paciente: %s (ID: %d) | Medico: %s\n", listap[k].nome, listap[k].id, listam[i].nome);
                            total_encontrados++;
                        }
                    }
                }
            }
        }
    }

    if(total_encontrados == 0){
        printf("Nenhum paciente encontrado para esta especialidade.\n");
    }
}

int main(){
    medico *listam = NULL;
    paciente *listap = NULL;
    consulta *listac = NULL;

    int qmedico = 0, qpaciente = 0, qconsulta = 0;
    int x;
    int y1, y2, y3, y4;
    int num_consulta;
    int id_paciente;
    int id_medico;

    do
    {
        printf("\nESCOLHA A OPCAO DESEJADA\n");
        printf("1 - Consulta\n");
        printf("2 - Paciente\n");
        printf("3 - Medico\n");
        printf("4 - Relatorio\n");
        printf("5 - Sair\n");
        printf("Escolha a opcao de 1 a 5:");
        scanf("%d", &x);

        switch (x){
        case 1:
            printf("\nOPCOES PARA CONSULTA\n");
            printf("1 - Incluir Consulta\n");
            printf("2 - Excluir Consulta\n");
            printf("3 - Alterar Consulta\n");
            printf("4 - Pesquisar Consulta\n");
            printf("Escolha a opcao:");
            scanf("%d", &y1);
            switch (y1) {
                case 1:
                    inc_consulta(&listac, &qconsulta, listam, qmedico, listap, qpaciente);
                    break;
                case 2:
                    printf("Digite o numero da consulta a excluir:");
                    scanf("%d", &num_consulta);
                    excluir_consulta(listac, qconsulta, num_consulta);
                    break;
                case 3:
                    printf("Digite o numero da consulta a alterar:");
                    scanf("%d", &num_consulta);
                    alterar_consulta(listac, qconsulta, num_consulta);
                    break;
                case 4:
                    printf("Digite o numero da consulta a pesquisar:");
                    scanf("%d", &num_consulta);
                    pesquisar_consulta(listac, qconsulta, num_consulta);
                    break;
                default:
                    printf("Opcao invalida para Consulta!\n");
                    break;
            }
            break;
        case 2:
            printf("\nOPCOES PARA PACIENTES\n");
            printf("1 - Incluir Paciente\n");
            printf("2 - Excluir Paciente\n");
            printf("3 - Alterar Paciente\n");
            printf("4 - Pesquisar Paciente\n");
            printf("Escolha a opcao:");
            scanf("%d", &y2);
            switch (y2) {
                case 1:
                    inc_paciente(&listap, &qpaciente);
                    break;
                case 2:
                    printf("Digite o ID do paciente a excluir:");
                    scanf("%d", &id_paciente);
                    excluir_paciente(listap, qpaciente, id_paciente, listac, qconsulta);
                    break;
                case 3:
                    printf("Digite o ID do paciente a ser alterado:");
                    scanf("%d", &id_paciente);
                    alterar_paciente(listap, qpaciente, id_paciente);
                    break;
                case 4:
                    printf("Digite o ID do paciente a pesquisar:");
                    scanf("%d", &id_paciente);
                    pesquisar_paciente(listap, qpaciente, id_paciente);
                    break;
                default:
                    printf("Opcao invalida para Paciente!\n");
                    break;
            }
            break;
        case 3:
            printf("\nOPCOES PARA MEDICOS\n");
            printf("1 - Incluir Medico\n");
            printf("2 - Excluir Medico\n");
            printf("3 - Alterar Medico\n");
            printf("4 - Pesquisar Medico\n");
            printf("Escolha a opcao:");
            scanf("%d", &y3);
            switch (y3) {
                case 1:
                    inc_medico(&listam, &qmedico);
                    break;
                case 2:
                    printf("Digite o ID do medico a excluir:");
                    scanf("%d", &id_medico);
                    excluir_medico(listam, qmedico, id_medico, listac, qconsulta);
                    break;
                case 3:
                    printf("Digite o ID do medico a ser alterado:");
                    scanf("%d", &id_medico);
                    alterar_medico(listam, qmedico, id_medico);
                    break;
                case 4:
                    printf("Digite o ID do medico a pesquisar:");
                    scanf("%d", &id_medico);
                    pesquisar_medico(listam, qmedico, id_medico);
                    break;
                default:
                    printf("Opcao invalida para Medico!\n");
                    break;
            }
            break;
        case 4:
            printf("\nMENU DE RELATORIOS\n");
            printf("1 - Consultas por Paciente\n");
            printf("2 - Consultas por Medico\n");
            printf("3 - Pacientes por Especialidade\n");
            printf("Escolha a opcao:");
            scanf("%d", &y4);
            switch(y4){
                case 1:
                    relatorio_paciente_consultas(listac, qconsulta);
                    break;
                case 2:
                    relatorio_medico_consultas(listac, qconsulta);
                    break;
                case 3:
                    relatorio_especialidade_pacientes(listam, qmedico, listac, qconsulta, listap, qpaciente);
                    break;
                default:
                    printf("Opcao invalida para Relatorios!\n");
            }
            break;
        case 5:
            printf("Desligando...\n");
            if (listam) free(listam);
            if (listap) free(listap);
            if (listac) free(listac);
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }

    } while (x != 5);

    return 0;
}
