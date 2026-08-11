#include <stdio.h>
#include <cs50.h>
int main (void)
{
    string caracteres = get_string("Entrada:");
    printf("Saída: \n");
    for (int i = 0;caracteres[i] != '\0'; i++)
    {
        printf("%c\n", caracteres[i]);
    }
}