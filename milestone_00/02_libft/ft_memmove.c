
#include "libft.h"

//pode copiar de tras pra frente e de frente pra tras
//Copia n bytes tratando sobreposição
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			i;

	if (dest == src)
		return (dest);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if (ptr_dest > ptr_src)
	{
		i = n;
		while (i > 0)
		{
			ptr_dest[i - 1] = ptr_src[i -1];
			i--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
/*
int	main()
{
	int source1[5] = {1, 2, 3, 4, 5};
	int source2[5] = {1, 2, 3, 4, 5};
	int source3[5] = {1, 2, 3, 4, 5};
	int len = 5;
	int i = 0;

	printf("Antes da funcao\n"); // 1 2 3 4 5 
	for (i = 0; i < len; i++)
		printf("%d\t", source1[i]);

	printf("\nUsando ft_memmove\n"); // 1 2 1 2 3
	ft_memmove(&source2[2], &source2[0], 3 * sizeof(int)); //int nao char
	for (i = 0; i < len; i++)
		printf("%d\t", source2[i]);

	printf("\nUsando memmove\n"); // 1 2 1 2 3
	ft_memmove(&source3[2], &source3[0], 3 * sizeof(int));
	for (i = 0; i < len; i++)
		printf("%d\t", source3[i]);
}
*/
// int main()
// {
// 	char str[] = "aaa";

// 	printf("%s\n", (char *)memmove(str, str, 1)); //aaa (entra no 1 if)
// }



