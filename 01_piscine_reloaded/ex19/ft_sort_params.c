/*
Files to turn in : ft_sort_params.c
Allowed functions : ft_putchar

We’re dealing with a program here, you should therefore have a function main in
your .c file.
• Create a program that displays its given arguments sorted by ascii order.
• It should display all arguments, except for argv[0].
• All arguments have to have their own line.

Estamos lidando com um programa aqui, portanto você deve ter uma função main em
seu arquivo .c.
• Crie um programa que exiba seus argumentos fornecidos classificados por ordem ascii.
• Ele deve exibir todos os argumentos, exceto argv[0].
• Todos os argumentos devem ter sua própria linha.
*/

#include <unistd.h>

// imprime caracter
void    ft_putchar(char c)
{
    write(1, &c, 1);
}

///imprime uma string

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

// altera a ordem
void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

//compara o tamanho de duas strins pela tabela ASCII
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && (*s1 || *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

// Função para ordenar os argumentos na ordem ASCII (bubble sort)


// argc (int i): Conta quantos argumentos foram passados para o programa, incluindo o nome do programa, vai iniciar com 1, pois 0 é o nome do programa (./a.out)
// argv (int j): É um array de strings (vetor de vetores de char) com os argumentos.

//int i --> laço de controle loop externo
//int j --> laço de comparação interna

// i: Controla as passadas do algoritmo. Ele começa de 1 e vai até argc - 1
//j: Controla as comparações entre elementos adjacentes. Ele percorre o vetor de argv e compara elementos na posição j e j + 1.

//A comparação no Bubble Sort é sempre entre pares: argv[j] e argv[j + 1]

//argv[1] até argv[argc - 1] → são os argumentos passados, ultima posicao!
//argv[argc] == NULL,

//Função	                    O que ela troca?	    Exemplo prático
//ft_swap(char *a, char *b)	    Letras (char)	        'A' ↔ 'B'
//ft_swap(char **a, char **b)	Strings (ponteiros)	    "Olá" ↔ "Mundo"

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = 1;
        while(j < argc -1)
        {
            if (ft_strcmp(argv[j], argv[j + 1]) > 0)
                ft_swap(&argv[j], &argv[j + 1]);
            j++;
        }
        i++;
    } 

     // Imprimir os argumentos ordenados, pulando argv[0] (nome do programa)
	j = 1;
	while (j < argc)
	{
		ft_putstr(argv[j]);
		ft_putstr("\n");
		j++;
	}
	return (0);
}
