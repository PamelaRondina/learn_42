
#include "libft.h"

//Copia n bytes de src para dest (sem tratar sobreposição)
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			i;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}

// memcpy é indefinido com NULL, mesmo se n == 0
/*
int main ()
{
	char dest[10];

	//ft_memcpy(NULL, "abc", 3); // Erro: tentando escrever em NULL
	//memcpy(NULL, "abc", 3); 	//compila com warning

	//ft_memcpy(dest, NULL, 3);   // Erro: tentando ler de NULL
	//memcpy(dest, NULL, 3);      //compila com warning

	ft_memcpy(dest, "abc", 0);   
	memcpy(dest, "abc", 0);      

}
/*
/*	
 int	main(void)
{
	char src[] = "Nadar";
	char dest1[10];
	char dest2[10];

	ft_memcpy(dest1, src, 0);
	memcpy(dest2, src, 0);

	//dest1[5] = '\0';
	//dest2[5] = '\0';

	printf("my memcpy -> |%s|\n", dest1);
	printf("memcpy    -> |%s|\n", dest2);

	return (0);
}
*/