#include "libft.h"

//busca uma substring*(little) dentro de uma string (big), com um limite de comparacao de n caracteres
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == 0)
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while ((i + j) < len && big[i + j] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
    char b[] = "abcde123";
    char l[] = "de1";

    printf("%s", ft_strnstr(b, l, 6));
}*/

/*
int main(void)
{
    const char *big = "abcde";
    const char *little = "cd";

    char *res = ft_strnstr(big, little, 5);

    if (res)
        printf("Encontrado: %s\n", res);
    else
        printf("Não encontrado!\n");

    return 0;
}*/