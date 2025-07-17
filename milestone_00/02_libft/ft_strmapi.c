#include "libft.h"

// Funcao que transforma, cria uma NOVA STRING baseada nos retornos.
// Pode alterar, transformar, ou mudar completamente os caracteres!
//Não altera a original. (Só cria nova.)

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				size_s;
	unsigned int	i;
	char			*new_string;

	if (!s || !f)
		return (NULL);
	size_s = ft_strlen(s);
	new_string = malloc((size_s + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
/*
//Para que a funcao funcione precisa ter outra funcao com o mesmo parametro
char ft_test_toupper(unsigned int i, char c)
{
    (void)i; //ignorar o indice
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

char ft_test2(unsigned int i, char c)
{
    if (c % 2 == 0)
    {
        if (c >= 'a' && c <= 'z')
            return (c -32);
    }
    return (c);
}


int main(void)
{
    char *s = "continue a nadar";
    char *result;

    result = ft_strmapi(s, ft_test2);
    printf("%s", result);

    free(result);
}
*/
