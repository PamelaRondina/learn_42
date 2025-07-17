/*
Create a function that returns the square root of a number (if it exists), or 0 if the
square root is an irrational number.

• Here’s how it should be prototyped :
int ft_sqrt(int nb);

• Your function must return its result in less than two seconds.

int ft_sqrt(int nb);


Crie uma função que retorne a raiz quadrada de um número (se existir), ou 0 se a raiz quadrada for um número irracional.
• Veja como deve ser prototipado:

int ft_sqrt(int nb);

• Sua função deve retornar seu resultado em menos de dois segundos.

*/

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		return (0);
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

/* 
#include <stdio.h>

int	main(void)
{
	int n = 144;
	int result = ft_sqrt(n);
	printf("a raiz quadrada de %d é: %d", n, result);
} */