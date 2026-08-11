#include <stdio.h>
#include <cs50.h>
int main (void)
{
    int x;
    do
    {
        x = get_int("População inicial: ");
    }
    while(x < 9);
    int y;
    do
    {
        y = get_int("População final: ");
    }
    while(y < x);
    int anos = 0;
    do
    {
         float w =  x / 3;
         float z =  x / 4;
         x =  x + (int) w - (int) z;
         anos = anos + 1;
    }
 while (x < y);
 printf("Número de anos até a população final: %i.\n", anos);
}