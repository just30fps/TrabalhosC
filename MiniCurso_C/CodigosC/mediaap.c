#include <stdio.h>
#include <cs50.h>
const int TOTAL = 3;
float TiraMedia(int N, int n[]);
int main(void)
{
    int Notas[TOTAL];
    for (int i = 0; i < TOTAL; i++)
    {
        Notas[i] = get_int("Nota %i: ", i + 1);
    }
    printf("Média: %f\n", TiraMedia(TOTAL, Notas));
}
float TiraMedia(int N, int n[])
{
    int Soma = 0;
    for (int i = 0; i < N; i++)
    {
        Soma = Soma + n[i];
    }
    return Soma / (float) N;
}