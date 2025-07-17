#include "libft.h"

//e garante que toda essa memoria esteja zerada, zera todos os bytes alocados
//Aloca e zera memória e multiplica nmemb * size
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!nmemb || !size)
		return (malloc(0)); //comportamento da funcao original. devolve 0 ou NULL

		//OVERFLOW - estamos multiplicando dois size_t, se o resultado for:
		// nmemb * size . INT_MAX, entao dara OVERFLOW!
		// retorna NULL pq se der um numero maior do que se pode alocar memoria!
		
	if (nmemb > ((size_t) -1) / size)
		return (NULL);

		//alocacao de memoria (ex: 5 elementos * 4 bytes = 20 bytes)
		//malloc aloca os bytes,a memoria vem com lixo,valores aleatorios da RAM
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NUL//Aloca memória zerada para nmemb * size bytes
			//e garante que toda essa memoria esteja zerada, zera todos os bytes alocadosL);
		//zerar a memoria alocada, utilizando funcao bzero
	ft_bzero(ptr, (nmemb * size));
		//retornar o ponteiro
	return (ptr);
}
/*
int main()
{
	size_t n = 10;
	int *arr = calloc(n, sizeof(int)); //10 elementos * 4 (tamanaho de int)
	size_t	i = 0;

	while (i < n)
	{
		printf("elemento[%zu]= %d\n", i, arr[i]); //zu - size_t
		i++;
	}
	
	free(arr);
}
*/

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	void	*ptr;

// 	if (!nmemb || !size)
// 		return (malloc(0));
// 	if (nmemb > ((size_t) -1) / size)
// 		return (NULL);
// 	ptr = malloc(nmemb * size);
// 	if (!ptr)
// 		return (NULL);
// 	ft_bzero(ptr, (nmemb * size));
// 	return (ptr);
// }