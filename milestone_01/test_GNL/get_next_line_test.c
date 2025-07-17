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

//concatena line_get com parte de buffer_get ate \n (inclusive), aloca e retorna nova string
//strjoin == copia line | copia de buffer ate \n | se houver \n ele tambem copia, 
//retorna a nova string (e libera a antiga com free(line)
char	*ft_strjoin(char *line_get, char *buffer_get)
{
	size_t	size_len;		//total de caracteres que sera juntado
	char	*new_string;	//onde vamos guardar o resultado
	int 	i;
	int		j;
	
	if (!buffer_get)											//nao tem o que juntar, erro!
		return (NULL);
	size_len = (ft_strlen(line_get) + ft_strlen(buffer_get));	//calcular o tamanho da nova string
	new_string = malloc((size_len + 1) * sizeof(char));			//alocar memoria, nasce a string final, vazia mas com espao suficiente!
	if (!new_string)											//se erro no malloc, NULL
		return (NULL);
	i = 0;
	while (line_get && line_get[i])								//verifica se nao 'e NULL, e se [i] nao 'e '\0' | 
	{
		new_string[i] = line_get[i];							//Pegar tudo o que estava em line_get e colocar no inicio da new_string
		i++;
	}								
	j = 0;
	while (buffer_get[j] && buffer_get[j] != '\n')				//copia o buffer ate \n
		new_string[i++] = buffer_get[j++];						//a ultima posicao da new_string recebe o buffer
	if (buffer_get[j] == '\n')									//se achar \n, copia ele tambem para a ultima posicao de buffer
		new_string[i++] = '\n';
	new_string[i] = '\0';										//marca o final da string
	free(line_get);												//libera a string anterior qu foi utilizada para montar a new_string, evita memory leak
	return (new_string);
}

//percorre buffer caracter por caracter
//retorna 1 (se achou \n - [linha completa]) ou 0 (se nao achou nada)
//corta o que ja usamos e guarda o que sobra 

//se encontra, move tudo o que vem depois do \n pro comeco do buffer
//zera o resto para nao ter lixo

//zera os caracteres lidos da linha anterior
//move o que sobrou apos o \n pro comeco do buffer

//limpar um buffer apos encontrar o \n, mantendo apenas o que vem depois dele
int	ft_clean_buffer(char *buffer)
{
	int	i_read;													//indice de leitura --> varre o buffer original
	int	j_write;												//indice de escrita --> recnstroi o conteudo restante do buffer
	int	found_new_line;											//analisa se encontramos \n

	i_read = 0;
	j_write = 0;
	found_new_line = 0;
	while (buffer[i_read])										//enquanto houver caracter no buffer
	{
		if (found_new_line == 1)								//1 verificacao: 
			buffer[j_write++] = buffer[i_read];				
		if (buffer[i_read] == '\n')
			found_new_line = 1;
		buffer[i_read++] = 0;
	}
	return (found_new_line);
}



//Quando sucesso, a funcao retorna um ponteiro para a string (linha) lida
//Recebe um 'file descriptor', o arquivo aberto, via open na main

//recebe um fd (file descriptor) e retorna a proxima linha, incluindo o \n, 
// ou NULL quando: i) acabar o arquivo, ii) houver erro na leitura.
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];						//'static' mantem  o conteudo do 'buffer' entre as chamadas da funcao
	char		*line;										//o ponteiro que monta a linha final, inicialmente NULL e aumenta com ft_strjoin.
															//vai costurando os pedacos de texto lido no line, ate construir uma linha inteira
	if (fd < 0 || BUFFER_SIZE <= 0)							//protecao!
		return (NULL);
	
	line = NULL; 											//inicio da linha vazia, a cada iteracao recebe um pedaco de buffer, NULL para nao receber lixo da memoria

	//condicao que faz com que continue juntando os pedacos ate formar uma linha completa!
	//enquanto buffer[i] != '\0' ou read() ainda tem + dados para ler do arquivo
	//le ate count bytes do arquivo fd e coloca no buff
		//fd: o arquivo
		//buffer: o endereco da variavel onde os dados serao armazenados
		//BUFFER_SIZE: a quantidade MAXIMA de bytes qye sera lida
	while (*buffer || read(fd, buffer, BUFFER_SIZE) > 0)	//roda se pelo menos uma das condicoes for verdadeira
	{
		line = ft_strjoin(line, buffer);		
		if (ft_clean_buffer(buffer))						//Se sim, (1) break e ativo, para parar o while
			break ;
	}
	
	return (line);											//devolve a linha que foi montada
}

#include <stdio.h>  //printf
#include <fcntl.h> //open
int main ()
{
	int fd;

	fd = open("oi.txt", O_RDONLY);
	char *str;

	if (fd < 0)
	{
		printf("Error");
		return (1);
	}

	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	printf("FIM DA LEITURA!\n");
	close(fd);
	return (0);

}