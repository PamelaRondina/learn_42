# include "libft.h"

//DEVE RETORNAR NULL CASO O PONTEIRO S SEJA (!s)??
void    ft_putendl_fd(char *s, int fd)
{
    ft_putstr_fd(s, fd);
    ft_putchar_fd('\n', fd);
}
/*
int main(void)
{
    int fd;
    int bytes;
    char buffer[1];

    ft_putendl_fd("Continue ", 1);

    fd = open("bora.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if(fd == -1)
        return (1);

    ft_putendl_fd("a Nadar", fd);

    fd = open("bora.txt", O_RDONLY);

    if(fd == -1)
        return (1);
    
    bytes = read(fd, buffer, 1);

    while(bytes > 0)
	{
		ft_putchar_fd(buffer[0], 1);
		bytes = read(fd, buffer, 1);
	}

    close(fd);
}
    */