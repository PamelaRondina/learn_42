/*
• Create a function ft_div_mod prototyped like this :

• This function divides parameters a by b and stores the result in the int pointed by
div. It also stores the remainder of the division of a by b in the int pointed by mod.

• Crie uma função ft_div_mod prototipada como esta:

• Esta função divide os parâmetros a por b e armazena o resultado no int apontado por div. Ela também armazena o restante da divisão de a por b no int apontado por mod.

void ft_div_mod(int a, int b, int *div, int *mod);
*/

void ft_div_mod(int a, int b, int *div, int *mod)
{
    *div = a / b;
    *mod = a % b;
}

/*
include <stdio.h>
int main(void)
{
    int a;
    int b;
    int div;
    int mod;

    a = 10;
    b = 5;

    ft_div_mod(a, b, &div, &mod);
    printf("a: %d, b: %d, divisao: %d\n", a, b, div);
    printf("a: %d, b: %d, resto: %d\n", a, b, mod);
    return (0);
}
*/