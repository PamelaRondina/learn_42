# Projeto libft.h
## Funções - Parte 1 (mandatórias)

| Funções Parte 1 | Assinatura                                                           | Retorno                           | O que faz                                                       |
| --------------- | -------------------------------------------------------------------- | --------------------------------- | --------------------------------------------------------------- |
| `ft_isalpha`    | `int ft_isalpha(int c);`                                             | 1 (se letra), 0 (caso contrário)  | Verifica se `c` é uma letra (A-Z ou a-z)                        |
| `ft_isdigit`    | `int ft_isdigit(int c);`                                             | 1 (se dígito), 0 (caso contrário) | Verifica se `c` é um número de 0 a 9                            |
| `ft_isalnum`    | `int ft_isalnum(int c);`                                             | 1 ou 0                            | Verifica se `c` é letra ou número                               |
| `ft_isascii`    | `int ft_isascii(int c);`                                             | 1 ou 0                            | Verifica se `c` está entre 0 e 127 (tabela ASCII)               |
| `ft_isprint`    | `int ft_isprint(int c);`                                             | 1 ou 0                            | Verifica se `c` é imprimível (entre ' ' e '~')                  |
| `ft_strlen`     | `size_t ft_strlen(const char *s);`                                   | Número de caracteres              | Retorna o tamanho da string (sem o `\0`)                        |
| `ft_memset`     | `void *ft_memset(void *s, int c, size_t n);`                         | Ponteiro para `s`                 | Preenche os `n` primeiros bytes de `s` com o valor `c`          |
| `ft_bzero`      | `void ft_bzero(void *s, size_t n);`                                  | Nenhum (void)                     | Zera os `n` primeiros bytes da memória                          |
| `ft_memcpy`     | `void *ft_memcpy(void *dest, const void *src, size_t n);`            | Ponteiro para `dest`              | Copia `n` bytes de `src` para `dest` (sem tratar sobreposição)  |
| `ft_memmove`    | `void *ft_memmove(void *dest, const void *src, size_t n);`           | Ponteiro para `dest`              | Copia `n` bytes tratando sobreposição                           |
| `ft_strlcpy`    | `size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);`     | Tamanho da `src`                  | Copia string com limite de buffer e adiciona `\0` no final      |
| `ft_strlcat`    | `size_t ft_strlcat(char *dst, const char *src, size_t dstsize);`     | Tamanho total pretendido          | Concatena strings com limite de buffer e adiciona `\0` no final |
| `ft_toupper`    | `int ft_toupper(int c);`                                             | Maiúscula ou o próprio `c`        | Converte para maiúscula se `c` for minúsculo                    |
| `ft_tolower`    | `int ft_tolower(int c);`                                             | Minúscula ou o próprio `c`        | Converte para minúscula se `c` for maiúsculo                    |
| `ft_strchr`     | `char *ft_strchr(const char *s, int c);`                             | Ponteiro para 1ª ocorrência       | Procura a primeira ocorrência de `c` na string                  |
| `ft_strrchr`    | `char *ft_strrchr(const char *s, int c);`                            | Ponteiro para última ocorrência   | Procura a última ocorrência de `c` na string                    |
| `ft_strncmp`    | `int ft_strncmp(const char *s1, const char *s2, size_t n);`          | Diferença entre os bytes          | Compara até `n` caracteres entre duas strings                   |
| `ft_memchr`     | `void *ft_memchr(const void *s, int c, size_t n);`                   | Ponteiro para o byte encontrado   | Procura o byte `c` nos `n` primeiros bytes                      |
| `ft_memcmp`     | `int ft_memcmp(const void *s1, const void *s2, size_t n);`           | Diferença entre os bytes          | Compara os `n` primeiros bytes de duas regiões de memória       |
| `ft_strnstr`    | `char *ft_strnstr(const char *big, const char *little, size_t len);` | Ponteiro para início de `little`  | Procura substring `little` dentro de `big`, limitada por `len`  |
| `ft_atoi`       | `int ft_atoi(const char *str);`                                      | Número inteiro (`int`)            | Converte uma string para número inteiro                         |
| `ft_calloc`     | `void *ft_calloc(size_t nmemb, size_t size);`                        | Ponteiro para memória alocada     | Aloca memória zerada para `nmemb * size` bytes                  |
| `ft_strdup`     | `char *ft_strdup(const char *s);`                                    | Ponteiro para nova string         | Duplica a string usando malloc                                  |

| Funções Parte 2 | Assinatura                                                        | Retorno                  | O que faz                                                                |
| --------------- | ----------------------------------------------------------------- | ------------------------ | ------------------------------------------------------------------------ |
| `ft_substr`     | `char *ft_substr(char const *s, unsigned int start, size_t len);` | Nova string (substring)  | Cria uma substring a partir da posição `start`, com até `len` caracteres |
| `ft_strjoin`    | `char *ft_strjoin(char const *s1, char const *s2);`               | String concatenada       | Juntar duas strings numa nova alocada (com malloc)                        |
| `ft_strtrim`    | `char *ft_strtrim(char const *s1, char const *set);`              | String nova sem os `set` | Remove caracteres do `set` do início e fim de `s1`                       |
| `ft_split`      | `char **ft_split(char const *s, char c);`                         | Vetor de strings         | Divide `s` em várias strings separadas pelo caractere `c`                |
| `ft_itoa`       | `char *ft_itoa(int n);`                                           | String do número         | Converte um número inteiro (`int`) para string                           |
| `ft_strmapi`    | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));` | Nova string modificada   | Aplica função `f` a cada caractere da string, retornando nova string     |
| `ft_striteri`   | `void ft_striteri(char *s, void (*f)(unsigned int, char*));`      | Nada (`void`)            | Aplica `f` a cada caractere da string, modificando ela diretamente       |
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd);`                             | Nada (`void`)            | Escreve o caractere `c` no file descriptor `fd`                          |
| `ft_putstr_fd`  | `void ft_putstr_fd(char *s, int fd);`                             | Nada (`void`)            | Escreve a string `s` no file descriptor `fd`                             |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd);`                            | Nada (`void`)            | Escreve `s` seguido de `\n` no file descriptor `fd`                      |
| `ft_putnbr_fd`  | `void ft_putnbr_fd(int n, int fd);`                               | Nada (`void`)            | Escreve o número `n` no file descriptor `fd`                             |


| Funções Bonus     | Assinatura                                                                 | Retorno       | O que faz                                                                   |
| ----------------- | -------------------------------------------------------------------------- | ------------- | --------------------------------------------------------------------------- |
| `ft_lstnew`       | `t_list *ft_lstnew(void *content);`                                        | Novo nó       | Cria novo nó com o `content`                                                |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new);`                         | Nada (`void`) | Adiciona `new` no início da lista `lst`                                     |
| `ft_lstsize`      | `int ft_lstsize(t_list *lst);`                                             | Número de nós | Retorna quantos nós existem na lista                                        |
| `ft_lstlast`      | `t_list *ft_lstlast(t_list *lst);`                                         | Último nó     | Retorna o último nó da lista                                                |
| `ft_lstadd_back`  | `void ft_lstadd_back(t_list **lst, t_list *new);`                          | Nada (`void`) | Adiciona `new` no final da lista `lst`                                      |
| `ft_lstdelone`    | `void ft_lstdelone(t_list *lst, void (*del)(void *));`                     | Nada (`void`) | Libera o nó `lst` usando a função `del` para o conteúdo                     |
| `ft_lstclear`     | `void ft_lstclear(t_list **lst, void (*del)(void *));`                     | Nada (`void`) | Libera todos os nós da lista                                                |
| `ft_lstiter`      | `void ft_lstiter(t_list *lst, void (*f)(void *));`                         | Nada (`void`) | Aplica a função `f` em todos os conteúdos da lista                          |
| `ft_lstmap`       | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));` | Nova lista    | Cria nova lista com `f` aplicada a cada `content`, usando `del` se der erro |


**Funções com Ponteiros**

> char (*f)(unsigned int, char)

| Parte                | Significado                                                                |
| -------------------- | -------------------------------------------------------------------------- |
| char                 | O tipo de retorno da função: ela devolve um char.                          |
| (*f)                 | f é um ponteiro para função.                                               |
| (unsigned int, char) | A função recebe dois parâmetros: primeiro um unsigned int, depois um char. |

**File Descriptor | Arquivos abertos**

lsof --> liste todos os arquivos em processo (abertos)
/proc --> processos abertos/em andamento
ls --> listar todos os arquivos | numeros sao diretorios de processos (PID)
--cd (qualquer numero)
cat cmdline --> visualizar o comando utilizado pelo programa
cd fd ls --> listar os files descriptor 
ls -l (qualquer numero) --> dados do arquivo


"AJUSTAR!!"
/*

void	ft_print_list(t_list *lst)
{
	t_list *ptr;
	int		i;

	i = 0;
	ptr = lst;
	while (ptr)
	{
		printf("%s ->", (char *)ptr->content);
		ptr = ptr->next;
		i++;
	}
	printf("\nsize: %d", i);
	printf("\n");
}

void	del_list(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	while (ptr)
	{
		lst = lst->next;
		free(ptr);
		ptr = lst;
	}
}

int main(int argc, char **argv)
{
	int	i;
	t_list	*lst;
	t_list	*node;

	i = 1;
	lst = NULL;
	if (argc == 1)
		return (1);
	while (i < argc)
	{
		node = ft_lstnew(argv[i]);
		ft_lstadd_front(&lst, node);
		i++;

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new; 
}

void	ft_print_list(t_list *lst)
{
	t_list *ptr;
	int		i;

	i = 0;
	ptr = lst;
	while (ptr)
	{
		printf("%s ->", (char *)ptr->content);
		ptr = ptr->next;
		i++;
	}
	printf("\nsize: %d", i);
	printf("\n");
}

void	del_list(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	}
	ft_print_list(lst);
	del_list(lst);
}

//(TUDO REPRESENTA UMA NODE!!)
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;



void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new; 
}








	//(*banana).content; == banana->content; (ptr)
	//teste.next			acessar a variavel na struct (.)
	//node == struct 
*/

----------------------
**Revisao**

5. Nível Médio — Strings que mudam conteúdo ou navegam substrings
Essas funções envolvem manipulação de strings um pouco mais complexas.

Funções	Objetivo	Dica/Importante saber
ft_strnstr	Encontra substring em string com limite	Parar no primeiro match, respeitar tamanho n
ft_strdup	Duplica uma string alocando memória	Usa malloc + strcpy
ft_atoi	Converte string para número	Lida com espaços, sinais, overflow

6. Nível Médio — Alocação de Memória
Fundamentais para funções mais avançadas da Parte 2.

Funções	Objetivo	Dica/Importante saber
ft_calloc	Aloca e zera memória	Multiplica nmemb * size

7. Nível Médio–Alto — Funções com Alocação + Manipulação
Agora começa a real lógica combinatória: você usa tudo aprendido em strings e ponteiros + alocação dinâmica.

Funções	Objetivo	Dica/Importante saber
ft_substr	Recorta uma parte da string	Proteja os casos de start > strlen
ft_strjoin	Junta duas strings	Malloc do tamanho total + 1
ft_strtrim	Remove caracteres extras do início/fim	Usa strchr-like nas pontas
ft_split	Divide string em array de strings	Usar count + malloc + strcpy
ft_itoa	Inteiro para string	Cuida de sinal e alocação
ft_strmapi	Aplica função a cada caractere (com índice)	Retorna nova string
ft_striteri	Igual ao anterior, mas altera original	Usa ponteiro para modificar

8. Nível Fácil — Escrita em File Descriptor
Funções de escrita direta, normalmente fáceis.

Funções	Objetivo	Dica/Importante saber
ft_putchar_fd	Escreve caractere no FD	Usa write(fd, &c, 1)
ft_putstr_fd	Escreve string no FD	Usa write(fd, str, strlen(str))
ft_putendl_fd	Escreve string com \n no FD	Igual ao anterior, mas com write extra
ft_putnbr_fd	Escreve número no FD	Usa recursão ou divisão

9. Nível Alto — Funções Bônus (Listas Encadeadas)
Essas exigem entendimento de ponteiros, structs, e alocação dinâmica.

Funções	Objetivo	Dica/Importante saber
ft_lstnew	Cria novo nó	Struct com content + next
ft_lstadd_front	Adiciona novo nó no início	Manipula ponteiros
ft_lstadd_back	Adiciona no final	Navega até next == NULL
ft_lstdelone	Libera um nó	Usa del() para content
ft_lstclear	Libera toda a lista	While + delone
ft_lstiter	Aplica função a todos os nós	Só lê, não altera
ft_lstmap	Aplica função e gera nova lista	Cuidado com leaks
ft_lstsize	Conta elementos	Loop até NULL
ft_lstlast	Retorna último nó	Quando next == NULL

| Errors                          | Texto                           |
| ------------------------------- | ------------------------------- |
| *** stack smashing detected *** | Escreve além do limite do array |
| IOT instruction (core dumped)   | Programa crashou                |

**Valgrind**
> valgrind --leak-check=full ./a.out
> fsanitize=adress (compilar)



teste main
# include "libft.h"

int main(void)
{
	char *c = "-- Oi, tudo bem? --";
	char *teste1;
	size_t len_s;

	//imprimir o tamanho da string c
	len_s = printf("%zu\n", ft_strlen(c)); //19

	//localizar o primeiro by O de c
	printf("%s\n", ft_strchr(c, 'O')); //Oi, tudo bem? --

	//cortar as extremindade -
	teste1 = ft_strtrim(c, "-");

	//string nova sem as extremidades
	printf("%s\n", teste1);

	//tamanho novo
	printf("%zu\n", ft_strlen(teste1));
}