#include <stdio.h>
#include <cs50.h>
int main (void)
{
    char Resposta = get_char ("você concorda?\n");
    if (Resposta == 's' || Resposta == 'S')
    {
        printf("você concordou\n");
    }
    else if (Resposta == 'n' || Resposta == 'N')
{
    printf("você não concordou\n");
}
}

