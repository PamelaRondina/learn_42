/*
• Reproduce the behavior of the function strcmp (man strcmp).
• Here’s how it should be prototyped :

• Reproduza o comportamento da função strcmp (man strcmp).
• Veja como deve ser prototipado:
int ft_strcmp(char *s1, char *s2);

C03 - EX00
*/

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && (*s1 || *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/*

int main(void)
{
    char s1[] = "ABC";
    char s2[] = "ABC";

    printf("%d\n", ft_strcmp(s1, s2));
}
*/

/* 

comparar se s1 e s2 e identificar =(iqual) >(greater) ou <(less).
a comparacao é feita a partir dos valores da ASCII

#include <string.h>

int	main(int argc, char *argv[])
{
	argc = 2;
	printf("sys: %d\n", strcmp(argv[1], argv[2]));
	printf("mine: %d\n", ft_strcmp(argv[1], argv[2]));
} */