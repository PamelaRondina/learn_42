#include "libft.h"

//Procura o byte 'c' nos 'n' primeiros bytes, uma area da memoria
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr_s;

	ptr_s = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr_s[i] == (unsigned char)c)
			return ((void *)ptr_s + i);
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
    char test[] = {10, 20, 30, 40, 50};
   	char *result = ft_memchr(test, 30, 5);
	
	if (result)
    	printf("Valor encontrado: %p, %d\n", result, *result);  

		// Agora sim, mostra o endereço correto|
	else
    printf("Valor não encontrado!\n");

	printf("Endereço de memoria:  %p, %d\n", &test[2], test[2]);
}*/
// int main()
// {
// 	memchr(NULL, 'a', 3); // Vai tentar acessar memória inválida
// 	//s == NULL && n > 0!
// }
