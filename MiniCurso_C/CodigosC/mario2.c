#include <stdio.h>
#include <cs50.h>
void printspace(int y);
void printhash(int z);
int main (void)
{

    int altura;
    do
    {
        altura = get_int("Digite a altura da pirâmide: ");
    }
    while (altura < 1 || altura > 8);



    for (int coluna = 0; coluna < altura; coluna++)

    {
        for (int largura = altura - 1 ; largura > coluna ; largura--)
        {
            printf(" ");
        }
        for (int a = 0; a < coluna; a++)
        {
            printf("#");
        }

        printf("#  ");

        for (int largura = 0; largura < coluna; largura++)
        {
            printf("#");
        }

        printf("#\n");
    }
}