

#include "include/ft_printf.h"

//especificar o formato, sendo localizado entra na funcao
int	ft_found(char c, va_list args) //utiliza o caractere que vem depois de % e a lista de variaveis apos o str
{
	if (c == 'c')									//a posicao 'e == c?
		return (ft_putchar(va_arg(args, int)));		//le o proximo argumento da lista como se fosse um int (vira por por "integer promotion".)
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (ft_put0x(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), c));
	return (ft_putchar('%'));							//le %
}

//retorna a quantidade de caracteres impressos
int	ft_printf(const char *format, ...)
{
	va_list	args;			// estrutura para acessar os argumentos
	int		i; 				//index da string
	int		count_caracter;	//contagem dos caracteres (o retorno da funcao)

	if (!str || write(1, 0, 0) == -1) //printf retorna 3 erros 1) Se str = NULL || 2) Quando nao consegue imprimir no STDOUT
		return (-1);
	i = 0;					//index primeira posicao
	count_caracter = 0;		//inicio da contagem dos caracteres
	va_start(args, str);	//inicio da verificacao dos argumentos
	while(format[i])			//enquanto nao estamos no fim da string
	{
		if (format[i] == '%') //se a posicao da string for == %
		{
			i++;
			if (format[i] == '\0')
				return (va_end(args), -1); //se a ultima posição for % retorna erro (assim como a printf)
			else			// e o proximo argumento
				count_caracter += ft_found(format[i], args);
			i++;					//vai aumentar o valor da count_caracter e pegar a proxima posicao como argumento
									//aumenta a posicao para o proximo caracter apos o argumento
		}
		else
			count_caracter += ft_putchar(format[i++]); //caso nao %, apenas imprime!
	}	
	va_end(args);
	return (count_caracter);   //a funcao imprime no terminal, mas o que ela retorna de fato 'e a quantidade de caracteres que foram impressos
}

/*
#include "ft_printf.h"
int main (void)
{
	char *string = NULL;
	char *string1 = "Hi, How Are You?";

	write(1, "---------> Teste 01: texto\n", 27);
	int len =  ft_printf("Hello!\n");					//teste
	ft_printf("%d\n", len);								//contagem tamanho
	write(1, "\n", 1);									//quebra de linha
	int len1 = printf("Hello!\n");						//teste
	printf("%d\n", len1);								//contagem tamanho
	write(1, "\n", 1);									//quebra de linha
	
	write(1, "--------> Teste 02.01: string (null)\n", 37);
	int len2 = ft_printf("%s", string);				//teste
	ft_printf("%d\n", len2);								//contagem tamanho
	write(1, "\n", 1);									//quebra de linha
	int len3 = printf("%s", string);					//teste
	printf("%d\n", len3);								//contagem tamanho
	write(1, "\n", 1);									//quebra de linha

	write(1, "--------> Teste 02.02: string\n", 31);
	int len4 =  ft_printf("%s\n", string1);				//teste
	ft_printf("%d\n", len4);								//contagem tamanho	
	write(1, "\n", 1);									//quebra de linha
	int len5 = printf("%s\n", string1);					//teste
	printf("%d\n", len5);								//contagem tamanho	
	write(1, "\n", 1);									//quebra de linha

	write(1, "--------> Teste 03: '%ca%cb%c%c, 0, 0, 0, 0'\n", 45);
	int len6 = ft_printf("%ca%cb%c%c\n", 0, 0, 0, 0);	//teste
	ft_printf("%d\n", len6);								//contagem tamanho	
	write(1, "\n", 1);									//quebra de linha
	int len7 =  printf("%ca%cb%c%c\n", 0, 0, 0, 0);	//teste
	printf("%d\n", len7);								//contagem tamanho	
	write(1, "\n", 1);									//quebra de linha

	// int i = 10;
	// char *s = "oi";
	// write(1, "--------> Teste 04: '%d%s%', 10, 'oi''\n", 39);
	// int len8 = ft_printf("%d%s%", i, s);				//teste
	// ft_printf("\nResult is: %d\n", len8);				//contagem tamanho	
	// write(1, "\n", 1);								//quebra de linha
	// int len9 = printf("%d%s%", i, s);					//teste
	// printf("\nResult is: %d\n", len9);					//contagem tamanho	
	// write(1, "\n", 1);									//quebra de linha

	write(1, "--------> Teste 05.01: decimal e intereger 'd' 'i'\n", 51);
	int len10 = ft_printf("%d %d %i %i \n", -123, 123, -456, 456); //teste
	ft_printf("%d\n", len10);								//contagem tamanho	
	write(1, "\n", 1);									//quebra de linha
	int len11 = printf("%d %d %i %i \n", -123, 123, -456, 456);				
			//teste
	printf("%d\n", len11);								//contagem tamanho	
	write(1, "\n", 1);									//quebra de linha

	write(1, "--------> Teste 05.02: decimal e intereger 'd' 'i'\n", 51);
	int len12 = ft_printf("%d %d %i %i \n", 2147483646, 123, -456, 456);
	ft_printf("%d\n", len12);								//contagem tamanho	
	write(1, "\n", 1);									//quebra de linha
	int len13 = printf("%d %d %i %i \n", 2147483646, 123, -456, 456);
	printf("%d\n", len13);								//contagem tamanho	
	write(1, "\n", 1);									//quebra de linha
	
	char *str = NULL;
	write(1, "--------> Teste 06: memory 'p'\n", 31);
	int len14 = ft_printf("%p\n", str);					//teste
	ft_printf("%d\n", len14);								//contagem tamanho	
	write(1, "\n", 1);									//quebra de linha
	int len15 = printf("%p\n", str);						//teste
	printf("%d\n", len15);								//contagem tamanho	
	write(1, "\n", 1);									//quebra de linha
	
	write(1, "--------> Teste 07: hex 'x X'\n", 30);
	int len16 = ft_printf("Hex (x) %x | Hex (X) %X\n", 170, 170); //teste
	ft_printf("%d\n", len16);								//contagem tamanho	
	write(1, "\n", 1);									//quebra de linha
	int len17 = printf("Hex (x) %x | Hex (X) %X\n", 170, 170); 
	printf("%d\n", len17);								//contagem tamanho	
	write(1, "\n", 1);									//quebra de linha

	write(1, "--------> Teste 08: U' UNSIGNED_MAX -3 \n", 40);
	int len18 = ft_printf("Unisigned: -3 = %u.\n", -3); //teste
	ft_printf("%d\n", len18);								//contagem tamanho	
	write(1, "\n", 1);									//quebra de linha
	int len19 = printf("Unisigned: -3 = %u.\n", -3); //teste
	printf("%d\n", len19);								//contagem tamanho	
	write(1, "\n", 1);									//quebra de linha

	write(1, "--------> Teste 09: %%'\n\n", 24);
	int len20 = ft_printf("Porcentagem: %% \n"); //teste
	ft_printf("%d\n", len20);								//contagem tamanho	
	write(1, "\n", 1);									//quebra de linha
	int len21 = printf("Porcentagem: %% \n"); //teste
	printf("%d\n", len21);								//contagem tamanho	
	write(1, "\n", 1);									//quebra de linha

	write(1, "--------> Teste 10: INT_MIN'\n", 29);
	int len22 = ft_printf("%d\n", INT_MIN); //teste
	ft_printf("%d\n", len22);								//contagem tamanho	
	write(1, "\n", 1);									//quebra de linha
	int len23 = printf("%d\n", INT_MIN); //teste
	printf("%d\n", len23);								//contagem tamanho	
	write(1, "\n", 1);									//quebra de linha
	
	ft_printf("%x\n", 0);
	printf("%x\n", 0);
	ft_printf("%d\n", -42);
	printf("%d\n", -42);
}
*/