# include "libft.h"

//comparar ate n caracteres entre duas strings, diferença entre os bytes
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
int main()
{
printf("banana' e 'banal' com n = 4: %d\n", ft_strncmp("banana", "banal", 4));  // 0
printf("banana' e 'banal' com n = 5: %d\n", ft_strncmp("banana", "banal", 5));  // 2
printf("abacate' e 'abelha' com n = 3: %d\n", ft_strncmp("abacate", "abelha", 3));  // -4
printf("abacate' e 'abelha' com n = 4: %d\n", ft_strncmp("abacate", "abelha", 4));  // -4
printf("\n\n");
printf("banana' e 'banal' com n = 4: %d\n", strncmp("banana", "banal", 4));  // 0
printf("banana' e 'banal' com n = 5: %d\n", strncmp("banana", "banal", 5));  // 2
printf("abacate' e 'abelha' com n = 3: %d\n", strncmp("abacate", "abelha", 3));  // -4
printf("abacate' e 'abelha' com n = 4: %d\n", strncmp("abacate", "abelha", 4));  // -4
}
*/