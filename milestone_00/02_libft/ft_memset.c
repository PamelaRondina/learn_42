
#include "libft.h"

//Preenche os n primeiros bytes de s com o valor c
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int	main()
{
	char *buffer = malloc(10 * sizeof(char));
	if (!buffer)
		return (1);

	printf("Antes do Teste: %s\n", buffer); //um alloc e free mais (printf)
	ft_memset(buffer, 130, 9);
	//memset(buffer, 'A', 9);
	buffer[9] = '\0';

	printf("Depois do Teste: %s\n", buffer);

	free(buffer);
	return (0);
}*/
