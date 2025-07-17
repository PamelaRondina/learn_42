#include "libft.h"

//vai remover todos os caracteres "limite" 
//(os caracteres que você definir) de ambos os lados de uma string.
// //recebe: s1 STRING ORIGINAL | set CARACTERES QUE SERAO REMOVIDOS

char    *ft_strtrim(char const *s1, char const *set)
{
    size_t     start;
    size_t     end;
    char    *new_string;

    if (!s1 || !set)
        return (NULL);

    start = 0;
        // Encontrar o início da nova string (o primeiro caractere de s1 que não está em set)
        // Enquanto ft_strchr(SET, Caractere de s1 estiver em SET), prossiga!
        //Vai apontar para a primeira posicao de S1 que nao tenha o SET
            //Vai apontar onde começa a parte “útil” da string (sem os caracteres indesejados do início).
    while (s1[start] && ft_strchr(set, s1[start]))
        start++;
   
        // Localizar o final da string
    end = ft_strlen(s1);
    while (ft_strrchr(set, s1[end]))
		end--;
        
    // Criar a nova string, alocar memória para ela
    new_string = ft_substr(s1, start, end - start + 1);
    // ???????????????????????
    //Nao preciso verificar se deu erro de alocacao de memoria, pois em ft_substring ja faz isso!
    return (new_string);
}
/*
int main(void)
{
    char *str = "He1 Continue a nadar! 1He";
    char *result = ft_strtrim(str, "e1H"); 
    char *result2 = ft_strtrim(str, "1H");
    char *result3 = ft_strtrim(str, "eH");

    printf("Resultado: %s\n", result); //remove todos: Continue a nadar
    printf("Resultado: %s\n", result2); //rm H começo: e1 Continue a nadar! 1He
    printf("Resultado: %s\n", result3); //rm He | He : 1 Continue a nadar! 1
    
    free(result);
    free(result2);
    free(result3);
}
*/

// char    *ft_strtrim(char const *s1, char const *set)
// {
//     size_t     start;
//     size_t     end;
//     char    *new_string;

//     if (!s1 || !set)
//         return (NULL);
//     start = 0;
//     while (s1[start] && ft_strchr(set, s1[start]))
//         start++;
//     end = ft_strlen(s1);
//     while (ft_strrchr(set, s1[end]))
// 		end--;
//     new_string = ft_substr(s1, start, end - start + 1);
//     return (new_string);
// }
