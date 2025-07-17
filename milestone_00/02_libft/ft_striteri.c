#include "libft.h"

//Ela não cria uma nova string (diferente de ft_strmapi)
//Ela modifica a string original diretamente!
// Para cada caractere da string s, ela chama uma função f, passando:
    //s: é o ponteiro para a string original que você quer modificar.
    //f: é o ponteiro para uma função que recebe:
    //Um índice (unsigned int) → a posição do caractere na string (0, 1, 2, 3, etc.)
    // Um ponteiro para o caractere (char *) → para poder modificar esse caractere.


void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    unsigned int i;

    // "Return" sem nada em funções void significa simplesmente parar a função e voltar 
    // para quem chamou, sem retornar valor nenhum (sai da função!)
    // Proteção → Evita erro de segmentação (famoso SegFault).
    if (!s || !f)
        return ;

    i = 0;
    while (s[i])
    {
        //ao inves de atribuir
        //s[i] = f(i, s[i]);
        //só chamamos: i [o indice atual] | 
        // O endereço do caractere atual (&s[i]), para que a função possa modificar diretamente a letra.
        f(i, &s[i]);
        i++;
    }
}
/*
//Funcao nao deve retornar nada, semelhante a funcao da atividade
// se nao retorna nada, fazemos conforme abaixo!
static void ft_test_toupper(unsigned int i, char *c)
{
    (void)i; //ignorar o indice
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

int main(void)
{
    char *s = "Continue a Nadar";

    //Cria uma cópia da string, garantindo que ela seja modificável.
    s = ft_strdup(s);

    ft_striteri(s, ft_test_toupper);
    printf("%s\n", s);

    free(s); // Libera a memória alocada

    return (0);
}*/

// void	ft_striteri(char *s, void (*f)(unsigned int, char *))
// {
// 	int	i;

// 	if (!s || !f)
// 		return ;
// 	i = 0;
// 	while (s[i])
// 	{
// 		f(i, &s[i]);
// 		i++;
// 	}
// }