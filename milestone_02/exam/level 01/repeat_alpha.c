/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/

#include <unistd.h>

int main (int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        while (argv[1][i])
        {
            int j = 0;
            int k = 0;

            if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
            {
                j = argv[1][i] - 96;
                while (j > 0)
                {
                    write(1, &argv[1][i], 1);
                    j--;
                }
            }
            else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
            {
                k = argv[1][i] - 64;
                while (k > 0)
                {
                    write(1, &argv[1][i], 1);
                    k--;
                }
            }
            else if (argv[1][i] >= ' ' && argv[1][i] <= '@')
                write(1, &argv[1][i], 1);                
            i++;
        }
   }
   write(1, "\n", 1);
}