
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
int main()
{
	int a = 10;
	int b = 'A';

	printf("%d\t", ft_isalpha(a));
	printf("%d\n", isalpha(a));
	printf("%d\t", ft_isalpha(b));
	printf("%d\n", isalpha(b));
}*/