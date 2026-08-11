#include <stdio.h>
#include <cs50.h>
#include <string.h>
const int CHAVE = 1 ;
int main (void)
{
    string texto = get_string("Texto Simples (plaintext): ");
    printf("Texto Cifrado (ciphertext): ");
    for (int i = 0, n = strlen(texto); i < n; i++)
    {
        if (texto[i] >= 'a' && texto[i] <= 'z')
        {
            printf ("%c", texto[i] + CHAVE);
        }
        else if (texto[i] >= 'A' && texto[i] <= 'Z')
        {
            printf ("%c", texto[i] + CHAVE);
        }
        else
        {
            printf ("%c", texto[i]);
        }
    }
    printf ("\n");
}
