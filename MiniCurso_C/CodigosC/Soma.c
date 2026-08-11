#include <stdio.h>
#include <cs50.h>
int main (void)
{
    int x = get_int("digite um numero x: ");
    int y = get_int("digite um numero y: ");
    printf("a soma de x com y igual à %i.\n", x + y);
}