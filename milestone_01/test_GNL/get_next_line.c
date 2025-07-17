#include "get_next_line_teste.h"

//conta o numero de caracteres ate o '\0'
size_t	ft_strlen(const char *str)
{
	size_t	count;

	if (!str)			//retorna 0 se str for NULL
		return (0);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

//concatena s1 com parte de s2 ate \n (inclusive), aloca e retorna nova string
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size_len;
	char	*new_string;
	int 	i;
	int		j;
	
	if (!s2)
		return (NULL);
	size_len = (ft_strlen(s1) + ft_strlen(s2));
	new_string = malloc((size_len + 1) * sizeof(char));	
	if (!new_string)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		new_string[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] && s2[j] != '\n')
		new_string[i++] = s2[j++];
	if (s2[j] == '\n')
		new_string[i++] = '\n';
	new_string[i] = '\0';
	free(s1);						//evita memory leak
	return (new_string);
}

//percorre buffer caracter por caracter
//retorna 1 (se achou \n - [linha completa]) ou 0 (se nao achou nada)
//corta o que ja usamos e guarda o que sobra 

//se encontra, move tudo o que vem depois do \n pro comeco do buffer
//zera o resto para nao ter lixo

//zera os caracteres lidos da linha anterior
//move o que sobrou apos o \n pro comeco do buffer
int	ft_clean_buffer(char *buffer)
{
	int	i;
	int	j;
	int	found_new_s1;

	i = 0;
	j = 0;
	found_new_s1 = 0;
	while (buffer[i])
	{
		if (found_new_s1 == 1)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			found_new_s1 = 1;
		buffer[i] = 0;
		i++;
	}
	return (found_new_s1);
}



//Quando sucesso, a funcao retorna um ponteiro para a string (linha) lida
//Recebe um 'file descriptor', o arquivo aberto, via open na main

//recebe um fd (file descriptor) e retorna a proxima linha, incluindo o \n, 
// ou NULL quando: i) acabar o arquivo, ii) houver erro na leitura.
char	*get_next_line(int fd)
{
	//'static' mantem  o conteudo do 'buffer' entre as chamadas da funcao
	//mantem o conteudo que sobrou da ultima leitura
	static char	buffer[BUFFER_SIZE];
	//o ponteiro que monta a linha final, inicialmente NULL e aumenta com ft_strjoin.
	//vai costurando os pedacos de texto lido no line, ate construir uma linha inteira
	char		*line;

	//protecao!
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	//inicio da linha vazia, a cada iteracao recebe um pedaco de buffer
	//NULL para garantir que a string comece vazia e nao receba lixo de memoria
	line = NULL;

	//condicao que faz com que continue juntando os pedacos ate formar uma linha completa!
	//enquanto buffer[i] != '\0' ou read() ainda tem + dados para ler do arquivo
	//le ate count bytes do arquivo fd e oloca no buff
		//fd: o arquivo
		//buffer: o endereco da variavel onde os dados serao armazenados
		//BUFFER_SIZE: a quantidade MAXIMA de bytes qye sera lida
	while (*buffer || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		//costura a linha: junta o que ja tinhamos em 'line' com o conteudo atual de buffer
		
		//strjoin == copia line | copia de buffer ate \n | se houver \n ele tambem copia, 
		//retorna a nova string (e libera a antiga com free(line)
		line = ft_strjoin(line, buffer);

		//varre o buffer: encontra o \n |  move tudo o que vem DEPOIS do \n pro inicio de buffer | zera o resto
		// se \n foi encontrado, a linha esta pronta | sai do loop com break
		if (ft_clean_buffer(buffer))
		//se 
			break ;
	}
	//devolve a linha que foi montada
	return (line);
}

#include <stdio.h>  //printf
#include <fcntl.h> //open
int main ()
{
	int fd;

	fd = open("oi.txt", O_RDONLY);
	char *s1;

	if (fd < 0)
	{
		printf("Error");
		return (1);
	}

	s1 = get_next_line(fd);
	while (s1 != NULL)
	{
		printf("%s", s1);
		free(s1);
		s1 = get_next_line(fd);
	}
	printf("FIM DA LEITURA!\n");
	close(fd);
	return (0);

}