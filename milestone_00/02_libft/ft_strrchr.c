#include "libft.h"

// devolve * para o ultimo char encontrado
char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			ch;
	char			*last;

	ch = (unsigned char) c;
	i = 0;
	last = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			last = ((char *) &s[i]);
		i++;
	}
	if (s[i] == '\0' && ch == '\0')
		last = ((char *) &s[i]);
	return (last);
}
/*
int main(void)
{
     char teste[] = "Nadar e Nadar...";
     printf("%s\n", ft_strrchr(teste, 'z'));
     printf("%s\n", strrchr(teste, 'z'));
}*/