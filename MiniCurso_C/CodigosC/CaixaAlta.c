#include <stdio.h>
#include <cs50.h>
#include <string.h>
int main(void)
{
    string caracteres = get_string("Antes:");
    printf("Depois:");
    for (int i = 0, n = strlen(caracteres); i < n; i++ )
    {
        if (caracteres[i] >= 'a' && caracteres[i] <= 'z')
        {
            printf ("%c", caracteres[i] - 32);
        }
        else
        {
            printf ("%c", caracteres[i]);
        }
    }
    printf ("\n");
}