#include "libft.h"

// char para int
int ft_atoi(const char *nptr)
{
   int  i;
   int  pn;
   int  num;

   i = 0;
   num = 0;
   pn = 1;
    if ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
        i++;
    while (nptr[i] == '-' || nptr[i] == '+')
    {
        if (nptr[i] == '-')
            pn = pn * -1;
        i++;
    }
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        num = (num * 10) + (nptr[i] - '0');
        i++;
    }
    return (num * pn);
}
/*
int main()
{
    char a[] = "    ---+--+123ab567";
    char b[] = "123";
    
    printf("%d\n", ft_atoi(b));
    printf("%d\n", atoi(b));
}
    */
