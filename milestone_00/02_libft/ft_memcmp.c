#include "libft.h"

//Compara os n primeiros bytes de duas regiões de memória

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;
	size_t			i;

	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr_s1[i] != ptr_s2[i])
			return (ptr_s1[i] - ptr_s2[i]);
		i++;
	}
	return (0);
}

/*
int main(void) {
    // Teste 1: Comparando dois buffers idênticos
    char test1[] = {1, 2, 3, 4, 5};
    char test2[] = {1, 2, 3, 4, 5};
    
    printf("Teste 1: Buffers idênticos\n");
    printf("Resultado original: %d\n", memcmp(test1, test2, 5));
    printf("Resultado minha versão: %d\n\n", ft_memcmp(test1, test2, 5));

    // Teste 2: Comparando buffers diferentes no 3º byte
    char test3[] = {1, 2, 0, 4, 5};
    
    printf("Teste 2: Buffers diferentes (terceiro byte)\n");
    printf("Resultado original: %d\n", memcmp(test1, test3, 5));
    printf("Resultado minha versão: %d\n\n", ft_memcmp(test1, test3, 5));

    // Teste 3: Comparando com diferentes tamanhos de comparação
    printf("Teste 3: Comparando apenas os dois primeiros bytes\n");
    printf("Resultado original: %d\n", memcmp(test1, test3, 2));
    printf("Resultado minha versão: %d\n\n", ft_memcmp(test1, test3, 2));
    
    // Teste 4: Comparando buffers com o mesmo conteúdo mas diferentes tamanhos
    char test4[] = {1, 2, 3, 4};
    printf("Teste 4: Buffers com diferentes tamanhos (buf1 e buf4)\n");
    printf("Resultado original: %d\n", memcmp(test1, test4, 4));
    printf("Resultado minha versão: %d\n\n", ft_memcmp(test1, test4, 4));

    return (0);
}*/
