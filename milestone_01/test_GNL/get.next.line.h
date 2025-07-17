# ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

# include <stddef.h> //VERIFICAR
# include <stdlib.h> //malloc, free
# include <fcntl.h>	//open
# include <unistd.h> //read, write

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_reset(char *buffer);

// void	*ft_memcpy(void *dest, const void *src, size_t n);
// size_t	ft_strlen(const char *s);
// char	*ft_strjoin(char const *s1, char const *s2);
// size_t	ft_strlen(const char *s);
// int		reset_buffer(char *buffer);
// char 	*extrai_linha(char *str);

#endif