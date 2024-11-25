#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int ft_printf(const char *format, ...);
int print_format(char specifier, va_list ap);
int ft_print_char(int  c);
int ft_print_str(char *str);
int ft_print_nbr(int n);
int ft_print_pt(void *ptr);
int ft_print_unsigned(unsigned int n);
int ft_print_hex(unsigned int num, int uppercase);

#endif