#include "libft.h"

//Duplica a string usando malloc
char	*ft_strdup(const char *src)
{
	int		size;
	int		i;
	char	*dup;

	size = ft_strlen(src);
	dup = malloc((size_src + 1) * sizeof(char));
	if (!dup)
		return(NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
int	main(void)
{
	char test[] = "Continue a nadar...";
	char *copy_original;
	char *copy_minhaft;

	copy_original = strdup(test);
	
	printf("Teste: %s\n", test);
	printf("Cópia: %s\n", copy_original);
	printf("\n");

	copy_minhaft = ft_strdup(test);

	printf("Teste: %s\n", test);
	printf("Cópia: %s\n", copy_minhaft);

	free(copy_original);
	free(copy_minhaft);

	return (0);
}*/