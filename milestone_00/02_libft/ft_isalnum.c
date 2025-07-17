
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') 
		|| (c >= 'A' && c <= 'Z') 
		|| (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
int	main(void)
{
	int a = '\n';
	int b = 'A';

	printf("%d\t", ft_isalnum(a));
	printf("%d\n", isalnum(a));
	printf("%d\t", ft_isalnum(b));
	printf("%d\n", isalnum(b));
}*/

