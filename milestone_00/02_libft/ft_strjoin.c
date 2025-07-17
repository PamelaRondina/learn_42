#include "libft.h"

//juntar duas strings e uma

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	size_t	size_len;
	char	*new_string;

	//verificar se os ponteiros sao vazios
	if (!s1 || !s2)
		return (NULL);

	//tamanho de s1 e s2
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	size_len = (size_s1 + size_s2);

	//alocar memoria
	new_string = malloc((size_len + 1) * sizeof(char));
	if(!new_string)
		return(NULL);

	//copiar s1 para a nova string
	ft_memcpy(new_string, s1, size_s1);
	//copiar s2 logo depois de s1
	// 4 é a posicoa que inicia a copia.
	ft_memcpy(new_string + size_s1, s2, size_s2);
		
	//ajustar para a achar a ultima posiçao
	//new_string[size_s1 + size_s2] = '\0';
	// Adiciona o terminador nulo ao final da nova string
	new_string[size_len] = '\0';
	
	return(new_string);
}
/*
int main()
{
	char *str1 = "";
	char *str2 = "456";
	char *new;

	new = ft_strjoin(str1, str2);

	printf("%s\n", new);
	printf("%zu", ft_strlen(new));

	free(new);
}
*/

// //juntar duas strings e uma
// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	size_s1;
// 	size_t	size_s2;
// 	size_t	size_len;
// 	char *new_string;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	size_s1 = ft_strlen(s1);
// 	size_s2 = ft_strlen(s2);
// 	size_len = (size_s1 + size_s2);
// 	new_string = malloc((size_len + 1) * sizeof(char));
// 	if(!new_string)
// 		return(NULL);
// 	ft_memcpy(new_string, s1, size_s1);
// 	ft_memcpy(new_string + size_s1, s2, size_s2);
// 	new_string[size_len] = '\0';
// 	return(new_string);
// }