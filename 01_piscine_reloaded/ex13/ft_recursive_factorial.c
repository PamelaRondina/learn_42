/*
• Create a recursive function that returns the factorial of the number given as a parameter.
• If there’s an error, the function should return 0.
• Here’s how it should be prototyped :

• Crie uma função recursiva que retorne o fatorial do número dado como um parâmetro.
• Se houver um erro, a função deve retornar 0.
• Veja como deve ser prototipado:

int ft_recursive_factorial(int nb);

*/

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	if (nb > 12)
		return (0);
	return (nb * ft_recursive_factorial(nb - 1));
}

/* 
#include <stdio.h>

int	main(void)
{
	int n = 4;
	int f = ft_recursive_factorial(n);
	printf("Fatorial de %d é: %d\n", n, f);

	return (0);
} */