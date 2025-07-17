/*
Files to turn in : ft_strdup.c
Allowed functions : malloc

• Reproduce the behavior of the function strdup (man strdup).
• Here’s how it should be prototyped :

• Reproduza o comportamento da função strdup (man strdup).
• Veja como deve ser prototipado:

char *ft_strdup(char *src);

*/

//#include <stdlib.h>: alocação de memória com malloc

#include <stdlib.h>

// função recebe como argumento um ponteiro para uma string (src) e retorna um novo ponteiro para uma cópia dessa string, alocada dinamicamente.

char *ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*dup;

    //Descobrir o tamanho da string original
    //len conta quantos caracteres existem na string.
	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
    //Alocar memória para a cópia
	dup = (char *)malloc(sizeof(char) * (len + 1));
    //malloc aloca espaço para len + 1 caracteres do tipo char.
    //O +1 é para o caractere nulo ('\0'), que precisa ser incluído no final da nova string.
    //dup agora é um ponteiro para o espaço de memória alocado.

    //Verificar se a alocação deu certo
	if (!dup)
		return (NULL);
    //Se malloc falhar, ele retorna NULL. Nesse caso, a função também retorna NULL para indicar erro.
	
    //Copiar os caracteres
    //Copia caractere por caractere da string original (src) para a nova string (dup).
    //Depois do loop, adiciona manualmente o '\0', NULL é importante para ser validado!!
    while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
    //Retornar a cópia: retorna o ponteiro da nova string criada dinamicamente.
	return (dup);
}

/*#include <stdio.h>
int	main(void)
{
	char test[] = "Continue a nadar...";
	char *copy;

	copy = ft_strdup(test);

	printf("Teste: %s\n", test);
	printf("Cópia: %s\n", copy);

	return (0);
}*/