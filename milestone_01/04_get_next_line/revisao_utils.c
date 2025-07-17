#include "get_next_line_teste.h"

// conta o numero de caracteres ate o '\0'
size_t	ft_strlen(const char *str)
{
	size_t	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

// concatena line_get com parte de buffer_get ate \n (inclusive), aloca e
// //retorna nova string
// strjoin == copia line | copia de buffer ate \n |
// se houver \n ele tambem copia,
// retorna a nova string (e libera a antiga com free(line)

char	*ft_strjoin(char *line_get, char *buffer_get)
{
	size_t	size_len;
	char	*new_string;
	int		i;
	int		j;

	if (!buffer_get)
		return (NULL);
	size_len = (ft_strlen(line_get) + ft_strlen(buffer_get));
	new_string = malloc((size_len + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	i = 0;
	while (line_get && line_get[i])
	{
		new_string[i] = line_get[i];
		i++;
	}
	j = 0;
	while (buffer_get[j] && buffer_get[j] != '\n')
		new_string[i++] = buffer_get[j++];
	if (buffer_get[j] == '\n')
		new_string[i++] = '\n';
	new_string[i] = '\0';
	free(line_get);
	return (new_string);
}

// percorre buffer caracter por caracter
// retorna 1 (se achou \n - [linha completa]) ou 0 (se nao achou nada)
// corta o que ja usamos e guarda o que sobra
// se encontra, move tudo o que vem depois do \n pro comeco do buffer
// zera o resto para nao ter lixo
// zera os caracteres lidos da linha anterior
// move o que sobrou apos o \n pro comeco do buffer
// limpar um buffer apos encontrar o \n, mantendo apenas o que vem depois dele
int	ft_clean_buffer(char *buffer)
{
	int	i_read;
	int	j_write;
	int	new_line_get;

	i_read = 0;
	j_write = 0;
	new_line_get = 0;
	while (buffer[i_read])
	{
		if (new_line_get == 1)
			buffer[j_write++] = buffer[i_read];
		if (buffer[i_read] == '\n')
			new_line_get = 1;
		buffer[i_read++] = 0;
	}
	return (new_line_get);
}

//funcao que oprocessa o buffer
int	ft_process_buffer(char **line, char *buffer)
{
	*line = ft_strjoin(*line, buffer);
	if (ft_clean_buffer(buffer))
		return (1);
	return (0);
}