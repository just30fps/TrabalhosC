#include <stdio.h>
#include <cs50.h>
int consigainteiropositivo(void);
int main(void)
{
    int i = consigainteiropositivo();
    printf("o inteiro positivo escolhido foi: %i.\n", i);
}
int consigainteiropositivo(void)
{
    int n;
    do
    {
        n = get_int("Dê-me um inteiro positivo: ");
    }
    while (n < 1);
    return n;
}