#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
    string caracteres = get_string("Antes:");
    printf("Depois:");
    for (int i = 0, n = strlen(caracteres); i < n; i++)
    {
        if (islower(caracteres[i]))
        {
            printf ("%c", toupper(caracteres[i]));
        }
        else
        {
            printf("%c", caracteres[i]);
        }
    }
    printf ("\n");
}