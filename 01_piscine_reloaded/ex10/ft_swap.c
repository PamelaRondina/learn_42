/*
• Create a function that swaps the value of two integers whose addresses are entered
as parameters.
• Here’s how it should be prototyped :

• Crie uma função que troque o valor de dois inteiros cujos endereços são inseridos
como parâmetros.
• Veja como deve ser prototipado:

void ft_swap(int *a, int *b);

*/

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*
#include <stdio.h>
int main(void)
{
    int x = 9;
    int y = 5;

    printf("Antes do swap, valor de x: %d, valor de y: %d\n", x, y);
    ft_swap(&x, &y);
    printf("Depois do swap, valor de x: %d, valor de y: %d", x, y);
    return (0);
}
*/