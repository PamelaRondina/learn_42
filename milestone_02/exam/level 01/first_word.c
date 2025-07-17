/*
Write a program that takes a string and displays its first word, followed by a newline.
Escreva um programa que pegue uma string e exiba sua primeira palavra, seguida de Uma nova linha.

A word is a section of string delimited by spaces/tabs or by the start/end of the string
Uma palavra é uma seção de string delimitada por espaços/guia ou pelo início/fim da corda.

If the number of parameters is not 1, or if there are no words, simply display a newline.
Se o número de parâmetros não for 1, ou se não houver palavras, basta exibir Uma nova linha.

FEITO TESTE | OK

$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$

$> ./first_word "a" "b" | cat -e
$

$> ./first_word "   " | cat -e
$

$> ./first_word "FOR PONY" | cat -e
FOR$

$> ./first_word "this        ...    is sparta, then again, maybe    not" | cat -e
this$

$>*/

#include <unistd.h>

int main (int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        while (argv[1][i] == 32)
            i++;
        while (argv[1][i] != 32 && argv[1][i])
            write(1, &argv[1][i++], 1);
    }
    write(1, "\n", 1);
}