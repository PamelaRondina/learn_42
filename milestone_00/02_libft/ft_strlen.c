
#include "libft.h"

//Retorna o tamanho da string (sem o \0)
size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (s[count] != '\0')	
		count++;
	return (count);
}
/*
int	main(void)
{
	const char test[] = "Swim hard, dream big...";

	printf("%lu\t", ft_strlen(test));
	printf("%lu\n", strlen(test));
}*/

