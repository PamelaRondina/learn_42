/*
• Reproduce the behavior of the function strlen (man strlen).
• Here’s how it should be prototyped :

• Reproduza o comportamento da função strlen (man strlen).
• Veja como deve ser prototipado:

int ft_strlen(char *str);

*/

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/* int	main(void)
{
	char *str = "Continue a nadar...";

	printf("%d\n", ft_strlen(str));
} */