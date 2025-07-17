
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
int	main()
{
	int a = '!';
	int b = 127;

	printf("%d\t", ft_isprint(a));
	printf("%d\n", isprint(a));
	printf("%d\t", ft_isprint(b));
	printf("%d\n", isprint(b));
}
*/