/*
Files to turn in : ft_range.c
Allowed functions : malloc

• Create a function ft_range which returns an array ofints. This int array should
contain all values between min and max.
• Min included - max excluded.
• Here’s how it should be prototyped :
• If min´value is greater or equal to max’s value, a null pointer should be returned.

• Crie uma função ft_range que retorna um array de ints. Este array int deve
conter todos os valores entre min e max.
• Min incluído - max excluído.
• Veja como deve ser prototipado:
• Se min´value for maior ou igual ao valor de max, um ponteiro nulo deve ser retornado.

int *ft_range(int min, int max);
*/


//array de inteiros que vai de min até max - 1, 
//alocando dinamicamente a memória necessária para armazenar esses valores.
// recebe dois inteiros min e max
//Retorna um ponteiro para um array de inteiros (int *).

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	size;
	int	i;

	i = 0;
    //Verifica se o intervalo é válido:
	if (min >= max)
		return (NULL);
	size = max - min;
    //Calcula o tamanho do array: por exemplo, de 3 até 10 → tamanho = 7.
    //malloc para alocar dinamicamente o array.
    //Se a alocação falhar (arr vira NULL), retorna NULL.
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
    //Preenche o array começando de min até max - 1.
    //Exemplo: min = 3, max = 10 → array = [3, 4, 5, 6, 7, 8, 9].
	while (i < size)
	{
		arr[i] = min + i;
		i++;
	}
    //Retorna o ponteiro para o início do array.
	return (arr);
}
/*int main(void) 
{
    int min = 3;
    int max = 10;
    int *range;
    int i;
    int size;

    range = ft_range(min, max);

    if (range == NULL) {
        printf("Failed.\n");
        return 1;
    }

    size = max - min;
    for (i = 0; i < size; i++) {
        printf("%d ", range[i]);
    }
    printf("\n");

    return 0;
}*/

