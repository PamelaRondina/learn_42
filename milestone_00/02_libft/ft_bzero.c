
#include "libft.h"

// Zera os n primeiros bytes da memória (=menset)
void	ft_bzero(void *s, size_t n)
{
	unsigned char 	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
int	main()
{
	char teste[18] = "Continue a nadar!";
	int i;

	i = 0;
	printf("Antes do ft_bzero: %s\n", teste);
	
	ft_bzero(teste, 2); //00ntinue a nadar!
	
	while (i < 18)
	{
		if (teste[i] == '\0')
			printf("0");
		else
			printf("%c", teste[i]);
		i++;
	}
	printf("\n");

	bzero(teste, 2);

	return(0);
}*/