#include <stdio.h>
#include <cs50.h>
int main (void)
{
    string Resposta = get_string("qual é o seu nome?" "\n");
    printf("Olá, %s!\n", Resposta);
}