
#include "libft.h"

//Converte um numero inteiro (positivo ou negativo) em string

//Cacular tamanho para a string
static int ft_size_int(long n)
{
    int size;

    if (n < 0) //adicionar uma posicao caso seja negativo (para adicionar -)
    {
        size++;
        n *= -1; //passado o numero para positivo
    }    
    while (n > 0)
    {
        size++;
        n /= 10; //a cada divisao elimina um numero da direita 123 --> 12 --> 1
    }
	return (size);
}

static long ft_test_number(long n)
{
    long nbr;
    
    nbr = n;
    if (nbr < 0)
        nbr = -nbr; 
    return (nbr);
}

char *ft_itoa(int n)
{
    int     size_str;   // tamanho da string
    int     i;          // index apoio para para o final '\0' 
    long    nbr;        // 'n', convertida para long
    char    *new_string;  // Ponteiro para a string, sera retornada no final que sera retornada

    size_str = 0;
    i = 0;

    //- MANTER Verificar se o numero é 0 e devolver um malloc(0) 
    if (n == 0)
        return ft_strdup("0");
    
    nbr = ft_test_number(n);
    size_str = ft_size_int(n);
   
    //Alocar memoria
    new_string = malloc((size_str + 1) * sizeof(char));
    if (!new_string)
        return(NULL);
    
    //Preencher a string de trás para frente:
    //pssando o valor de size para i para auxiliar na posicao do '\0'
    i = size_str;

    while (nbr != 0)
    {
        new_string[--size_str] = (nbr % 10) + '0'; //salva o valor da direita para esquerda 123 --> 3 --> 2 --> 1
        nbr /= 10;
    }

    //tratar o sinal 
    //(se for negativo, a primeira posicao ganha -)
    if (n < 0)
        new_string[0] = '-';
    
    //7) Adicionar o '\0'
    new_string[i] = '\0';

    //8) Retornar a strinf
    return (new_string);
}

int main(void)
{
    int numbers[] = {0, 1, -1, 42, -42, 2147483647, -2147483648};
    int i = 0;
    char *result;

    while (i < 7)
    {
        result = ft_itoa(numbers[i]);
        if (result)
        {
            printf("ft_itoa(%d) = %s\n", numbers[i], result);
            free(result);
        }
        else
            printf("Erro ao converter %d\n", numbers[i]);
        i++;
    }
    return 0;
}
// int main()
// {
//     int i = 0;

//     printf("%s: itoa", ft_itoa(i));
// }