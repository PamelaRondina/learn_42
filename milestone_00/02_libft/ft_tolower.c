#include "libft.h"

//Converte para minúscula se c for maiúsculo
int	ft_tolower(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		c += 32;
	return (c);
}
// int main(void)
// {
// 	int i, j;
// 	i = 'A';
// 	j = 'A';
// 	printf("%d\t", ft_tolower(i));
// 	printf("%d\t", tolower(i));
// }