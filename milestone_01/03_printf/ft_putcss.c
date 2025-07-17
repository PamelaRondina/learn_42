#include "ft_printf.h"

//print %c
int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

//print %s
int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

//print size printf (para testes)
int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}