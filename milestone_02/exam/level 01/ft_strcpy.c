/*
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).
Reproduzir o comportamento da função strcpy

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);
*/

char    *ft_strcpy(char *s1, char *s2)
{
    unsigned i = 0;

    while(s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = 0;
    return (s1);
}
#include <stdio.h>

int main (void)
{
    char a[] = "";
    char b[] = "bb";

    ft_strcpy(a, b);
    printf("%s", a);
}