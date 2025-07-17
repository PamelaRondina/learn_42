/*

Files to turn in : ft_putstr.c
Allowed functions : ft_putchar

• Create a function that displays a string of characters on the standard output.
• Here’s how it should be prototyped :

• Crie uma função que exiba uma sequência de caracteres na saída padrão.
• Veja como deve ser prototipado:

void ft_putstr(char *str);

*/

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

/*
void	ft_putchar(char c);
{
	write(1, &c, 1);
}

int	main(void)
{
	char	*str = "Continue a nadar...";

	ft_putstr(str);
} 

*/

