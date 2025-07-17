#include "libft.h"

// Trannsforma o int e um carracter 
//dependendo do valor de fd.
void    ft_putnbr_fd(int n, int fd)
{
    if (n == -2147483648)
    {
        ft_putchar_fd('-', fd);
        ft_putchar_fd('2', fd);
        ft_putnbr_fd(147483648, fd);
    }
    else if (n < 0)
    {
        ft_putchar_fd('-', fd);
        ft_putnbr_fd(-n, fd);
    }
    else if (n > 9)
    {
        ft_putnbr_fd(n / 10, fd);
        ft_putnbr_fd(n % 10, fd);
    }
    else 
    ft_putchar_fd(n + '0', fd);
}

/*
int main(void)
{
    ft_putnbr_fd(42, 1);
    ft_putchar_fd('\n', 1);
    
    ft_putnbr_fd(-12345, 1);
    ft_putchar_fd('\n', 1);
    
    ft_putnbr_fd(0, 1);
    ft_putchar_fd('\n', 1);
    
    ft_putnbr_fd(2147483647, 1);
    ft_putchar_fd('\n', 1);
    
    ft_putnbr_fd(-2147483648, 1);
    ft_putchar_fd('\n', 1);

    return (0);
}*/