
#include "libft.h"

//Escreve um único caractere em um file descriptor.
// usamos o file descriptor:

    //0 → stdin (entrada padrão — teclado)
    //1 → stdout (saída padrão — tela (terminal))
    //2 → stderr (erro padrão — tela)
   

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

/*
int main(void)
{
    int fd;

    // Teste 1: escrever no terminal (stdout -> fd = 1)
    ft_putchar_fd('A', 1);
    ft_putchar_fd('\n', 1);

    // Teste 2: escrever dentro de um arquivo
        //criar um arquivo chamado "saida.txt" e dentro dele incluir "B"
        //O_CREAT → cria o arquivo se ele não existir.
        //O_WRONLY → abre só pra escrita.
        //O_TRUNC → apaga o conteúdo anterior do arquivo, se ele existir.
        //0644 → permissões padrão: dono pode ler e escrever, outros só leem.

    fd = open("saida.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    //se ocorrer tudo bem nos parametros acima, open() retorna um número inteiro positivo
    //que é o descritor do arquivo
    //-1 utilizado por convenção
    if (fd == -1)
		return (1);
 	
        //escrever no arquivo

    ft_putchar_fd('B', fd);
    ft_putchar_fd('\n', fd);

    close(fd);

    return (0);
}
*/