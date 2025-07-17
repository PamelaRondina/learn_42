/*
Files to turn in : ft_abs.h
Allowed functions : None

• Create a macro ABS which replaces its argument by it absolute value :

#define ABS(Value)

You are asked to do something that is normally banned by the Norm, that will be the only time we autorize it.

Crie uma macro ABS que substitua seu argumento por seu valor absoluto:

#define ABS(Value)

Você é solicitado a fazer algo que normalmente é proibido pela Norma, essa será a única vez que autorizaremos isso.

*/

/*cabeçalho (header file), define uma macro ABS, para calcular o valor de um número 

#ifndef FT_ABS_H: é uma diretiva de pré-processador que significa "se não estiver definido".
O comando verificar se a macro FT_ABS_H já foi definida anteriormente. Caso não tenha sido definida, o código dentro do bloco (até o #endif) será processado. 
Se a macro já tiver sido definida, o código será ignorado!
Essa técnica é usada para evitar a inclusão múltipla do mesmo cabeçalho, o que pode causar erros de definição duplicada.

# define FT_ABS_H:
Caso o código entre no bloco do #ifndef, a macro FT_ABS_H é definida.
Aqui defino o nome FT_ABS_H para o arquivo de cabeçalho, 
garantindo que o código do arquivo seja incluído apenas uma vez durante a compilação. 
Isso evita que o conteúdo do arquivo de cabeçalho seja processado várias vezes!!

# define ABS(Value) ((Value) * ((Value) >= 0) - (Value) * ((Value) < 0)) 
define a macro ABS, que calcula o valor absoluto de um número. 
Esta linha define o macro ABS, que calcula o valor absoluto de Value
A macro usa uma expressão aritmética para determinar se o número é positivo ou negativo.

Passo 1: Comparações
O que está acontecendo dentro do ABS(Value) são duas comparações, e o valor de cada comparação será tratado como um número inteiro:

((Value) >= 0) → Esse é um teste lógico. Se Value for maior ou igual a 0, a expressão será verdadeira, ou seja, 1. Se Value for menor que 0, será falsa, ou seja, 0.

((Value) < 0) → Esse é outro teste lógico. Se Value for menor que 0, a expressão será verdadeira, ou seja, 1. Se Value for maior ou igual a 0, será falsa, ou seja, 0.
*/

#ifndef FT_ABS_H
# define FT_ABS_H

# define ABS(Value) ((Value) * ((Value) >= 0) - (Value) * ((Value) < 0))

#endif // FT_ABS_H