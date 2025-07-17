#include "libft.h"

//Converte para maiúscula se c for minúsculo
int	ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
			c -= 32;
	return (c);
}
// int main(void)
// {
// 	int i, j;

// 	i = 'a';
// 	j = 'a';
// 	printf("%d\t", ft_toupper(i));
// 	printf("%d\t", toupper(i));

// }