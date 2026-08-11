#include <stdio.h>
#include <cs50.h>
int main (void)
{
    float x = get_float("digite um numero x: ");
    float y = get_float("digite um numero y: ");
    float z =  x / y;
    printf("a divisão de x por y é igual a %f.\n", z);
}