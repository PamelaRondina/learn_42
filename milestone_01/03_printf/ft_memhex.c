#include "ft_printf.h"

//print %p 'converte um ponteiro para string hexadecimal
int	ft_putmemory(size_t nb)
{
	int			count;
	const char	*hex = "0123456789abcdef";

	count = 0;
	if (nb >= 16)
		count += ft_putmemory(nb / 16);
	count += ft_putchar(hex[nb % 16]);
	return (count);
}

//print %p = 0x
int	ft_put0x(void *ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	count += ft_putstr("0x");
	count += ft_putmemory((size_t)ptr);
	return (count);
}

//print x e X
int	ft_puthex(unsigned int nb, char c)
{
	const char	*hex_x;
	const char	*hex_xx;
	int			count;

	hex_x = "0123456789abcdef";
	hex_xx = "0123456789ABCDEF";
	count = 0;
	if (nb >= 16)
		count += ft_puthex(nb / 16, c);
	if (c == 'x')
		count += ft_putchar(hex_x[nb % 16]);
	else if (c == 'X')
		count += ft_putchar(hex_xx[nb % 16]);
	return (count);
}