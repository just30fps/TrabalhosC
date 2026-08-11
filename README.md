# 💻 Projetos em C - Fundamentos e Lógica de Programação

Este repositório consolida meus primeiros projetos e estudos na linguagem C, com foco em estruturação de código, manipulação de dados e fundamentos de ciência da computação. Desenvolvido por Gabriel Henrique.

## 🏥 1. Sistema de Gestão Hospitalar (`hospitalcompleto.c`)
**Contexto:** Trabalho final da disciplina de Lógica de Programação do curso de Engenharia de Computação no CEFET-MG.

**Descrição:** 
Um sistema interativo via linha de comando (CLI) para gerenciar o fluxo de atendimento de um hospital. O programa permite o cadastro completo (CRUD), alteração, exclusão e pesquisa de pacientes e médicos, além de realizar o agendamento de consultas vinculando os profissionais aos pacientes. O sistema também gera relatórios filtrados, como a listagem de consultas por médico/paciente e pacientes agrupados por especialidade médica.

**Conceitos Técnicos Aplicados:**
*   **Estruturas Heterogêneas (`structs`):** Utilizadas para modelar de forma organizada as entidades `medico`, `paciente` e `consulta`.
*   **Alocação Dinâmica de Memória:** Uso de ponteiros e da função `realloc` para gerenciar as listas de cadastros, permitindo que o sistema cresça sob demanda sem a limitação de vetores com tamanho fixo.
*   **Passagem por Referência:** Uso de ponteiros duplos (`**listam`, `**listap`, `**listac`) para modificar os dados diretamente na memória através das funções.
*   **Inativação Lógica (Soft Delete):** Implementação de variáveis de status (`ativom`, `ativop`, `ativoc`) para inativar registros em vez de excluí-los definitivamente, preservando o histórico de dados no sistema e cancelando as consultas em cascata.
*   **Controle de Fluxo:** Estruturação de menus iterativos utilizando `do-while` e aninhamento de `switch-case`.

---

## 🎓 2. Projetos do Curso CS50 - Harvard (`MiniCurso_C/CodigosC`)
**Contexto:** Resoluções de problemas e códigos desenvolvidos durante os estudos baseados no CS50 (Introduction to Computer Science) da Universidade de Harvard.

**Descrição:**
Diretório contendo exercícios focados no desenvolvimento do pensamento computacional. Os códigos exploram a manipulação de strings, laços de repetição, lógica condicional e abstração de tipos utilizando as bibliotecas padrão do C (como `<stdio.h>` e `<string.h>`), além da biblioteca didática `<cs50.h>`.

---

## 🚀 Como Executar
Para compilar e executar os códigos deste repositório, é necessário ter um compilador C instalado (como o GCC).

Exemplo para compilar e rodar o projeto do hospital no terminal:
```bash
gcc hospitalcompleto.c -o hospital
./hospital
```
