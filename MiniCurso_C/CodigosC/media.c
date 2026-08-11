#include <stdio.h>
#include <cs50.h>
int main(void)
{
    int Notas[3];
    Notas [0] = get_int ("Nota 1: ");
    Notas [1] = get_int ("Nota 2: ");
    Notas [2] = get_int ("Nota 3: ");
    float x = (Notas [0] + Notas[1] + Notas [2]);
    float y = x / 3.0;
    printf("Média das notas : %f.\n ", y);
}