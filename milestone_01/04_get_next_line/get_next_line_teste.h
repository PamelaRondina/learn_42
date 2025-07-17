//header file

// se nao tiver sido definido, defina! Serve para adicionar o cabecalho apenas 1x no .c
//evita erros de redefinicao, que quebrariam a compilacao!

//isso foi definido?
# ifndef GET_NEXT_LINE_H
//se nao foi incluido ainda...defina que ja incluimos esse header!
# define GET_NEXT_LINE_H

//O tamanho maximo do bloco de dados (bytes) o read() vai tentar ler a cada chamada. 
//-D BUFFER_SIZE=**

//verifica se BUFFER_SIZE ja foi definido
# ifndef BUFFER_SIZE
//se nao foi definido, define o valor padrao como 10 (ou o numero que estara no terminal)
# define BUFFER_SIZE 10
#endif

# include <stdlib.h>	//malloc, free
# include <unistd.h>	//read, write

//retornar uma linha do arquivo a cada chamada
char	*get_next_line(int fd);

//retorna o comprimento de um string (sem contar o \0), usando malloc da ft_strjoin
size_t	ft_strlen(const char *str);

//junta s1 e s2 ate o \n (ou fim da string). Essencialmente para construir a linha final
char	*ft_strjoin(char *s1, char *s2);

//Romeve do buffer o que ja foi lido e move os dados restantes para o comeco
int		ft_clean_buffer(char *buffer);

//finaliza o header
int     ft_process_buffer(char **line, char *buffer);
#endif