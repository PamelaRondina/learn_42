#include "libft.h"

//Divide `s` em array de strings separadas pelo caractere `c

//Receber a string s e contar quantas 'letras' possui
//Palavra = sequência de caracteres que não são o c, separados por c.
//s = "--oi--tudo--bem--", total palavras 3;
static size_t	ft_count(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])		//whilw nao estamos no fim da string, continue
	{
		while (s[i] == c) //caracter igual, continua a caminhar na string 
			i++;
		if (s[i]) //depois de pular o caracter, verifica se tem algo
			count++; //incrementa word
		while (s[i] && s[i] != c) //avança ate encontrar o proximo caracter
			i++;
	}
	return (count);
}

//alocar memoria para cada palavra 
//se falahar, libera todos os anteriores
static int	ft_malloc_great(char **words, int position, size_t len)
{
	int	i;

	i = 0; //percorrer e liberar a string se der erro.
	words[position] = malloc(len); //aloca espaco para a string na posicao atual
	if (words[position] == NULL) //se falhar
	{
		while (i < position) //libera todas as alocacoes anteriores
			free(words[i++]);
		free(words); //libera o proprio array de ponteiros
		return (1); //sinaliza erro
	}
	return (0); //sinaliza sucesso
}
//preenche o array com as palavras separadas
//returna 0 se malloc correr bem, caso contrario, retorna 1
//percorre s, extrai cada palavra, aloca memoria e copia
static int	ft_fill(char **words, const char *s, char c)
{
	size_t	len; //conta o tamanho da palavra atual
	int		i; //indice do array, onde a proxima palavra sera colocada

	i = 0;
	while (*s)
	{
		len = 0; //len volta a 0
		while (*s == c && *s) //percorre o caracter
			++s;
		while (*s != c && *s) //conta o tamanho da palavra
		{
			++len;
			++s;
		}
		if (len > 0) //se achou a palavra, tenta copiar
		{
			if (ft_malloc_great(words, i, len + 1)) //aloca espaco (+1 para '\0'
				return (1);
			//s - len, aponta para o inicio de s (pq s ja foi incrementado len vezes durante o loop)
			ft_strlcpy(words[i], s - len, len + 1); //copia a palavra para o novo espaco
			++i;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	size_s;  //tamanho de string que recebo
	char	**words; // o array com cada string

	if (!s) //verifica se a string existe
		return (NULL);

	size_s = ft_count(s, c); // conta quantas palavras existem!
	words = malloc((size_s + 1) * sizeof(char *)); //alocar memoria, um array de ptr para cada palavra
	if (!words)
		return (NULL);
	if (ft_fill(words, s, c)) //copiar toda a string na posicao correta
		return (NULL);
	words[size_s] = NULL;
	return (words);
}

// int main (void)
// {
//     char *s = "oi tudo bem ";
    
//     char **teste = ft_split(s, ' ');

//     while (*teste)
//         printf("%s\n", *teste++);
// }

/*

FT_COUNT COM S[i]
static size_t  ft_count(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0; //contar as palabras
	i = 0; // index para percorrer a string
	while (s[i])
	{
		while (s[i] == c) // caminha o index se encontrar caracter
			i++;
		if (s[i] != c && s[i] != '\0') // se encontrar uma palavra, aumenta count
		{
			count++;
			while (s[i] && s[i] != c) // se nao encontrar caracter, avança index!
				i++;
		}
	}
	return (count);
}
*/

//s = "--oi--tudo--bem--", total palavras 3;
// static size_t	ft_count(const char *s, char c)
// {
// 	size_t	i;
// 	size_t	count;

// 	i = 0;
// 	count = 0;
// 	while (s[i])		
// 	{
// 		while (s[i] == c) 
// 			i++;
// 		if (s[i]) 
// 			count++; 
// 		while (s[i] && s[i] != c) 
// 			i++;
// 	}
// 	return (count);
// }

//alocar memoria para cada palavra 
//se falahar, libera todos os anteriores
// static int	ft_malloc_great(char **word, int position, size_t len)
// {
// 	int	i;

// 	i = 0;
// 	word[position] = malloc(len);
// 	if (word[position] == NULL)
// 	{
// 		while (i < position) 
// 			free(word[i++]);
// 		free(word); 
// 		return (1);
// 	}
// 	return (0);
// }

//preenche o array com as palavras separadas
//returna 0 se malloc correr bem, caso contrario, retorna 1
//percorre s, extrai cada palavra, aloca memoria e copia
// static int	ft_fill(char **words, const char *s, char c)
// {
// 	size_t	len;
// 	int		i;

// 	i = 0;
// 	while (*s)
// 	{
// 		len = 0;
// 		while (*s == c && *s)
// 			++s;
// 		while (*s != c && *s)
// 		{
// 			++len;
// 			++s;
// 		}
// 		if (len > 0)
// 		{
// 			if (ft_malloc_great(words, i, len + 1))
// 				return (1);
// 			ft_strlcpy(words[i], s - len, len + 1);
// 			++i;
// 		}
// 	}
// 	return (0);
// }


//Divide `s` em array de strings separadas pelo caractere `c

char **ft_split(char const *s, char c);

void print_split(char **result)
{
	int i = 0;
	if (!result)
	{
		printf("Resultado: NULL\n");
		return;
	}
	while (result[i])
	{
		printf("Palavra %d: \"%s\"\n", i, result[i]);
		i++;
	}
}

//  TESTE 1: String comum
// Esperado: ["ola", "mundo"]
void test1() {
	printf("\nTeste 1:\n");
	char **res = ft_split("ola mundo", ' ');
	print_split(res);
}

//  TESTE 2: Vários separadores juntos
// Esperado: ["eu", "amo", "c"]
void test2() {
	printf("\nTeste 2:\n");
	char **res = ft_split("eu  amo   c", ' ');
	print_split(res);
}

//  TESTE 3: Começa e termina com delimitador
// Esperado: ["oi", "tudo", "bem"]
void test3() {
	printf("\nTeste 3:\n");
	char **res = ft_split("  oi tudo bem  ", ' ');
	print_split(res);
}

//  TESTE 4: Apenas delimitadores
// Esperado: []
void test4() {
	printf("\nTeste 4:\n");
	char **res = ft_split("     ", ' ');
	print_split(res);
}

// TESTE 5: String vazia
// Esperado: []
void test5() {
	printf("\nTeste 5:\n");
	char **res = ft_split("", ' ');
	print_split(res);
}

//  TESTE 6: NULL como entrada
// Esperado: NULL
void test6() {
	printf("\nTeste 6:\n");
	char **res = ft_split(NULL, ' ');
	print_split(res);
}

//  TESTE 7: Outro delimitador
// Esperado: ["banana", "abacate", "melancia"]
void test7() {
	printf("\nTeste 7:\n");
	char **res = ft_split("banana,abacate,melancia", ',');
	print_split(res);
}

int main(void)
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	return (0);

	//ADICIONAR FREE EM CADA TESTE!!!!
}