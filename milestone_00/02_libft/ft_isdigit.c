
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return(1);
	return(0);
}
/*
int main(void)
{
	int a = 0;
	int b = 48;
	int c = '0';

	printf("%d\t", ft_isdigit(a));
	printf("%d\n", isdigit(a));
	printf("%d\t", ft_isdigit(b));
	printf("%d\n", isdigit(b));
	printf("%d\t", ft_isdigit(c));
	printf("%d\n", isdigit(c));
}*/
