#include "../include/ft_printf.h"

//print %d %i
int	ft_putnbr(int nb)
{
	long	nb_l;
	int		count;

	nb_l = nb;
	count = 0;
	if (nb_l < 0)
	{
		count += ft_putchar('-');
		nb_l = -nb_l;
	}
	if (nb_l > 9)
	{
		count += ft_putnbr(nb_l / 10);
		count += ft_putnbr(nb_l % 10);
	}
	else
		count += ft_putchar(nb_l + '0');
	return (count);
}

//print %u
int	ft_putnbr_unsigned(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
		count += ft_putchar(nb + '0');
	return (count);
}
