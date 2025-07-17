/*
Files to turn in : ft_print_params.c
Allowed functions : ft_putchar

• We’re dealing with a program here, you should therefore have a function main in your .c file.
• Create a program that displays its given arguments.

Estamos lidando com um programa aqui, portanto você deve ter uma função main no seu arquivo .c.
• Crie um programa que exiba seus argumentos fornecidos.

• Example :
$>./a.out test1 test2 test3
test1
test2
test3
$>
*/


#include <unistd.h>

void	ft_putchar(char c);

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);
}

/*
void	ft_putchar(char c);
 {
	write(1, &c, 1);
} 
*/

/*
-------------------

//biclioteca utilizada para a funçao write
#include <unistd.h>

//prototipo da funcao para imprimir um char
void	ft_putchar(char c);

// argc (int i): Conta quantos argumentos foram passados para o programa, incluindo o nome do programa, vai iniciar com 1, pois 0 é o nome do programa (./a.out)
// argv (int j): É um array de strings (vetor de vetores de char) com os argumentos.

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);
}

/*
void	ft_putchar(char c);
 {
	write(1, &c, 1);
} 
*/

*/