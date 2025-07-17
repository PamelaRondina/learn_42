
#include "libft.h"

//src para buffer de dest, com um limite de tamanho (size), add \0
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	i;

	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}
/*
int	main()
{
	const char source[10] = "";
	char dest[] = "oi";

	printf("ft_strlcpy: %zu\n", ft_strlcpy(dest, source, sizeof(source));
	printf("dest: %s\n", dest);

	// printf("strlcpy: %zu\n", strlcpy(dest, source, 5));
	// printf("dest: %s\n", dest);
}
*/
/*
int main()
{
	char src[] = "123456789";
	char dst[5];

	size_t r = strlcpy(dst, src, sizeof(dst));

	printf("Retorno: %zu\n", r);
	printf("dst: '%s'\n", dst);
}*/