#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>	// varidiac list
# include <unistd.h> 	
# include <stdio.h>		

int	ft_putchar(int c);						//c
int	ft_strlen(const char *str);				//
int	ft_putstr(char *str);					//s
int	ft_putnbr(int nb);						//d e i
int	ft_putnbr_unsigned(unsigned int nb);	//u
int	ft_putmemory(size_t nb);				//p
int	ft_put0x(void *ptr);					//oX
int	ft_puthex(unsigned int nb, char c);		//x X
int	ft_printf(const char *format, ...);

#endif

