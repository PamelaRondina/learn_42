/*

• Create a function that takes a pointer to int as a parameter, and sets the value "42"
to that int.

• Here’s how it should be prototyped :

• Crie uma função que receba um ponteiro para int como parâmetro e defina o valor "42"
para esse int.

• Veja como ele deve ser prototipado:

void ft_ft(int *nbr);
*/

void	ft_ft(int *nbr)
{
	*nbr = 42;
}


#include <stdio.h>
int	main(void)
{
	int	n;
	ft_ft(&n);
	printf("%d\n", n);
}