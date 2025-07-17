
#include "libft.h"

// devolve * para o primeiro char encontrado
char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			ch;

	ch = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
		return ((char *)&s[i]);
		i++;
	}
	if (s[i] == '\0' && ch == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*
int main(void)
{
    char teste[] = "";
    
    printf("%s ->\n", ft_strchr(teste, '\0'));
    printf("%s ->\n", strchr(teste, '\0'));
}*/
