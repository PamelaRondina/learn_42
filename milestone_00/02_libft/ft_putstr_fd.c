#include "libft.h"

//DEVE RETORNAR NULL CASO O PONTEIRO S SEJA (!s)??
void ft_putstr_fd(char *s, int fd)
{
    write(fd, s, ft_strlen(s));
}
/*
int main ()
{
    int fd;

    int bytes;
    char buffer[1];
    
    //TESTE: 1 Escrever no terminal
    ft_putstr_fd("Continue....!\n", 1);

    //Escrever em um arquivo
    // Teste 2: escrever dentro de um arquivo
        //criar um arquivo chamado "teste.txt" e dentro dele incluir "B"
        //O_CREAT → cria o arquivo se ele não existir. (necessario dar o valor de permissao ex: 0644)
        //O_WRONLY → abre só pra escrita.
        //O_TRUNC → apaga o conteúdo anterior do arquivo, se ele existir.
        //0644 → permissões padrão: dono pode ler e escrever, outros só leem.
    fd = open("teste.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd == -1)
        return (1);

    ft_putstr_fd("Nadar!\n", fd);

    // Teste 3: Ler o conteúdo do arquivo e mostrar no terminal
    //O_RDONLY → le arquivos

    fd = open("teste.txt", O_RDONLY);

    if (fd == -1)
        return (1);


    bytes = read(fd, buffer, 1);

    while(bytes > 0)
	{
		write(1, buffer, 1);
		bytes = read(fd, buffer, 1);
	}

    close(fd);

    return (0);
}*/