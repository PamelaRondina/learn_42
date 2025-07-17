# Get_Next_Line 
> Projeto inicializado em 20/05/2025.

### Subject

Function name | get_next_line
|-|-
Prototype | char *get_next_line(int fd);
Turn in files | get_next_line.c, get_next_line_utils.c, get_next_line.h
Parameters | fd: The file descriptor to read from
Return value | Read line: correct behavior NULL: there is nothing else to read, or an error occurred
External functs. | read, malloc, free
Description | Write a function that returns a line read from a file descriptor

- Repeated calls (e.g., using a loop) to your get_next_line() function should let
you read the text file pointed to by the file descriptor, one line at a time.
- Chamadas repetidas (por exemplo, usando um loop) para sua função get_next_line() devem permitir que você leia o arquivo de texto apontado pelo descritor de arquivo, uma linha por vez.

- Your function should return the line that was read.
If there is nothing left to read or if an error occurs, it should return NULL.
- Sua função deve retornar a linha que foi lida.
Se não houver mais nada para ler ou se ocorrer um erro, ela deve retornar NULL.

- Make sure that your function works as expected both when reading a file and when
reading from the standard input.
- Certifique-se de que sua função funcione conforme o esperado tanto ao ler um arquivo quanto ao ler a entrada padrão.

- Please note that the returned line should include the terminating \n character,
except when the end of the file is reached and the file does not end with a \n
character.
- Observe que a linha retornada deve incluir o caractere de terminação \n,
exceto quando o fim do arquivo for alcançado e o arquivo não terminar com um caractere \n.

- Your header file get_next_line.h must at least contain the prototype of the
get_next_line() function.
- Seu arquivo de cabeçalho get_next_line.h deve conter pelo menos o protótipo da função get_next_line().

- Add all the helper functions you need in the get_next_line_utils.c file
- Adicione todas as funções auxiliares necessárias no arquivo get_next_line_utils.c

- Because you will have to read files in get_next_line(), add this option to your
compiler call: -D BUFFER_SIZE=n
It will define the buffer size for read().
The buffer size value will be adjusted by your peer evaluators and the Moulinette
to test your code.
- Como você terá que ler arquivos em get_next_line(), adicione esta opção à sua
chamada do compilador: -D BUFFER_SIZE=n
Ele definirá o tamanho do buffer para read().
O valor do tamanho do buffer será ajustado pelos seus avaliadores pares e pelo Moulinette para testar seu código.

> We must be able to compile this project with and without the -D BUFFER_SIZE flag in addition to the usual flags. You may choose any default value you prefer.
> Precisamos ser capazes de compilar este projeto com e sem a flag -D BUFFER_SIZE, além das flags usuais. Você pode escolher qualquer valor padrão de sua preferência.

- You will compile your code as follows (a buffer size of 42 is used as an example):
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
- Você compilará seu código da seguinte forma (um tamanho de buffer de 42 é usado como exemplo): cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

- get_next_line() exhibits undefined behavior if the file associated with the file
descriptor is modified after the last call, while read() has not yet reached the end
of the file.
- get_next_line() exibe comportamento indefinido se o arquivo associado ao descritor
de arquivo for modificado após a última chamada, enquanto read() ainda não atingiu o final do arquivo.

- get_next_line() also exhibits undefined behavior when reading a binary file. How-
ever, you can implement a logical way to handle this behavior if you want to.
- get_next_line() também exibe comportamento indefinido ao ler um arquivo binário. No entanto, você pode implementar uma maneira lógica de lidar com esse comportamento, se desejar.

> Does your function still work if the BUFFER_SIZE value is 9999? If it is 1? 10000000? Do you know why?
> Sua função ainda funciona se o valor de BUFFER_SIZE for 9999? É 1? 10000000? Sabe por quê?

- Read as little data as possible each time get_next_line() is called. 
- Leia o mínimo de dados possível sempre que get_next_line() for chamado.

- If a newline character is encountered, return the current line immediately.
- Se um caractere de quebra de linha for encontrado, retorne a linha atual imediatamente.

- Don’t read the whole file and then process each line.
- Não leia o arquivo inteiro e depois processe cada linha.


Forbidden! | Proibido!
• You are not allowed to use your libft in this project.
• Você não tem permissão para usar sua libft neste projeto.

• lseek() is forbidden. 

• Global variables are forbidden.

Function name | ****
|-|-
get_next_line.c | funcao principal do projeto
get_next_line_h | header
get_next_line_utils.c | funcoes auxiliares


## Objetivo:
- Trabalhar com variaveis estaticas;
Funcao capaz de ler um arquivo ou entrada padrao (stdin), linha por linha, sem perder nada! 
- Manipular buffers
- Lidar com arquivos (open, read, close)
- Guardar dados entre chamadas
- TRabalhar cm memoria dinamica (e evitar vazamentos)
- Pensar em desempenho, seguranca e modularidade

Logica Principal:
1) ler do arquivo (fd) em pedacos, usando um buffer **(BUFFER_SIZE)**
2) guardar os dados lidos em uma string acumuladora, ate encontrar um \n
3) Assim que encontrar uma linha completa, retorna a linha
4) Guarda o que sobrou na proxima chamada da funcao.

- Se não houver mais nada para ler ou se ocorrer um erro, ela deve retornar NULL.
- Adicione todas as funções auxiliares necessárias no arquivo get_next_line_utils.c

---------------------------

Double free | LIberar memoria que ja foi liberada



ler BUFFER_SIZE, mas você deve testá-lo com valores altos e baixos.

Testar com Valgrind e Francinette

francinette -tm 2000

valgrind --leak-check=full --show-leak-kinds=all -s --track-origins=yes

Cada vez que o read() é chamado, ele só deve ler BUFFER_SIZE. Não 0, 1, qualquer outra coisa

declared BUFFER_SIZE into .h

gnltester | gnl Tripouille tester 


read (fd, BUFFER, BUFFER_SIZE)

verificar protecoes malloc e dar free

Ao usar o read(), o size_t nbyte sempre tem que ser buffer_size?

[input - output](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/)

[post: setting variable to NULL after free](https://stackoverflow.com/questions/1025589/setting-variable-to-null-after-free)

[todo el mundo deveria ver este video](https://www.youtube.com/watch?v=CFRhGnuXG-4)



# ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 
#endif

# include <stddef.h>
# include <stdlib.h>

char	*get_next_line(int fd);

#endif

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	
}

// abril | maio

// 23/05. OK
// 610.94

// maio 

//cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c

