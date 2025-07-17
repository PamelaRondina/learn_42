/*

ANALISAR C05!!

Create an iterated function that returns a number. This number is the result of a
factorial operation based on the number given as a parameter.
• If there’s an error, the function should return 0.
• Here’s how it should be prototyped :
int ft_iterative_factorial(int nb);
• Your function must return its result in less than two seconds.

Crie uma função iterada que retorne um número. Este número é o resultado de uma
operação fatorial com base no número fornecido como parâmetro.

• Se houver um erro, a função deve retornar 0.

• Veja como ela deve ser prototipada:
int ft_iterative_factorial(int nb);

• Sua função deve retornar seu resultado em menos de dois segundos.

*/

int	ft_iterative_factorial(int nb)
{
	int	result;
	int	i;

	result = 1;
	i = 2;
	if (nb < 0)
		return (0);
	if (nb > 12)
		return (0);
	while (i <= nb)
	{
		result *= i;
		i++;
	}
	return (result);
}

/* 

#include <stdio.h>

int	main(void)
{
	int n;
	int f;

	n = 4;
	f = ft_iterative_factorial(n);
	printf("fatorial do número %d é: %d\n", n, f);
} */

/*
- A função calcula o fatorial de um número **nb** de forma iterativa. 
    4!  = 4 × 3 × 2 × 1
        = 12 × 2 = 24

- inicializado como 2, que será usado para iterar de 2 até nb.
    O valor inicial de result já é 1, e multiplicar por 1 não muda nada.

- 'if (nb < 0)' Se nb for menor que 0, a função retorna 0 (erro).
    Isso trata o caso de números negativos, pois o fatorial não é definido para números negativos.

- 


*/