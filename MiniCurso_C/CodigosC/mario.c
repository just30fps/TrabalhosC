#include <stdio.h>
#include <cs50.h>
void printspace(int y);
void printhash(int z);
int main (void)
{
    int altura, linha, coluna;
    int x;
    do
    {
        altura = get_int("Digite a altura da pirâmide: ");
    }
        while( altura < 1 || altura > 8);
        for (linha = 0; linha < altura; linha++)
    {
        for (coluna = 0; coluna <= linha; coluna++)
        {
            printf("#");
        }
        printf("\n");
}
}

