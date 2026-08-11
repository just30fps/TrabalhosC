#include <stdio.h>
#include <cs50.h>
#include <string.h>
int main (void)
{
    string caracteres = get_string("Entrada: ");
    printf("Saída:\n");
    int n = strlen(caracteres);
    for (int i = 0; i < n; i++)
    {
        printf("%c\n", caracteres[i]);
    }
}