/*
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
*/
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
    int i = 0;
    int pn = 1;
    int num = 0;

    //caminhar pelos caracteres
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '-')
    {
        pn = - 1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        num = (num * 10) + (str[i] - '0');
        i++;
    }
    return (num * pn);
}

int main()
{
    char a[] = "    ---+--+123ab567";
    char b[] = "123";
    
    printf("%d\n", ft_atoi(b));
    printf("%d\n", atoi(b));
}