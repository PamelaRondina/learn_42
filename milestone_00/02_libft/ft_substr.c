
#include "libft.h"

//Cria uma substring a partir da posição start (0), com até len caracteres
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size_s;
	size_t	i;
	char	*new_string;

	i = 0;
		//Verificacao de entrada
	if (!s) 
		return (NULL);
	
		//tamanho da string original
	size_s = ft_strlen(s);

		// Se o local que quero comecar a copiar [START] for >= ao tamanho da minha string Original 
		// ft_strdup: recebe uma string e duplica para a mesma, com malloc. Preenche com vazio
	if (start >= size_s)
		return (ft_strdup(""));
			
	//aqui que faz a copia!
	// While (a posicao do local que quero copiar (START[i] < tamanho da string) && (0 (i) < o tamanho que quero copiar), 
	//va para a proxia posicao, caminha pela string principal [s] ate achar o local que encerarra a copia
	// nisso I sera crementado
	//[i] utilizado para saber o final da string para incluir o '\0'

	//Verificacao para descobrir se o len esta correto!
	while ((start + i < size_s) && (i < len))
		i++;

    //alocar memoria para a nova string
	// + 1 . para receber o NULO '\0'
	new_string = malloc((i + 1) * sizeof(char));
	if (!new_string)
		return (NULL);

    //Copiar os caracteres para a nova string
	// memcpy(dst, src0 tamanho que sera copiado)
	// nem_string = DEST, s + START [ponteiro aponta para a primeira posicao + onde deve iniciar a copia], quantidade que deve ser copiado
	ft_memcpy(new_string, (s + start), i);
	new_string[i] = '\0';
	
	return (new_string);
}
/*
int main(void)
{
    char *original = "0123456789";
    char *sub;

    sub = ft_substr(original, 0, 3); //Retorno: "012"

    if(sub)
    {
        printf("Substring: %s\n", sub);
        free(sub);
    }
    else
        printf("Erro ao criar substring!\n");
	
    return (0);
}
*/

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	size_s;
// 	size_t	i;
// 	char	*new_string;

// 	if (!s)
// 		return (NULL);
// 	size_s = ft_strlen(s);
// 	if (start >= size_s)
// 		return (ft_strdup(""));
// 	i = 0;
// 	while ((start + i < size_s) && (i < len))
// 		i++;
// 	new_string = malloc((i + 1) * sizeof(char));
// 	if (!new_string)
// 		return (NULL);
// 	ft_memcpy(new_string, (s + start), i);
// 	new_string[i] = '\0';
// 	return (new_string);
// }