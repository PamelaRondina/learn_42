#include "libft.h"

//concatenar strings, sendo DST + SRC + \0
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;
	size_t	j;

	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	len_dst = ft_strlen(dst);
	i = len_dst;
	if (size <= i)
		return (len_src + size);
	j = 0;
	while (src[j] && i < size - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (len_dst + len_src);
}
/*
int main(void)
{
    // char buffer[10] = "123";
    // const char *src = "abc";
	// size_t result = ft_strlcat(buffer, src, sizeof(buffer));
	// printf("Result
//copia uma src para buffer de dest, com um limite de tamanho (size)
//garante que (dest) seja sempre nulo-terminado, desde que o tamanho
//seja maior que zero
//apresentar apenas o valor final 
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	i;

	i = 0;
	len_src = 0;
	len_src = ft_strlen(src);
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len_src);
}

// int	main()
// {
// 	const char source[] = "abcdef";
// 	char dest[] = "";

// 	printf("ft_strlcpy: %zu\n", ft_strlcpy(dest, source, 5));
// 	printf("dest: %s\n", dest);
// // deletar
// 	printf("strlcpy: %zu\n", strlcpy(dest, source, 5));
// 	printf("dest: %s\n", dest);
// }ado: %zu\n", result);
    // printf("Buffer final: %s\n", buffer);
	
	// char dest[10] = "1234";
	// const char *src = "abc";
	// size_t result = ft_strlcat(dest, src, 0);
	// printf("%zu\n", result);
	// printf("%s\n", dest);
}
*/