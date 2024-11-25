#include "ft_printf.h"

int ft_print_char(int c)
{
    return write(1, &c, 1);
}

int ft_print_str(char *str)
{
    int len = 0;

    if (!str)
        str = "(null)";
    while (*str)
    {
        len += write(1, str, 1);
        str++;
    }
    return len;
}

int ft_print_nbr(int n)
{
    long nbr;
    char digit;
    int count;

    count = 0;
    nbr = n;
    if (nbr < 0)
    {
        count += write(1, "-", 1);
        nbr = -nbr;
    }
    if (nbr > 9)
        count += ft_print_nbr(nbr / 10);
    digit = (nbr % 10) + '0';
    count += write(1, &digit, 1);
    return count;
}

int ft_print_pt(void *ptr)
{
    unsigned long long address = (unsigned long long)ptr;
    int len = 0;

    len += write(1, "0x", 2);
    len += ft_print_hex(address, 0);
    return len;
}

int ft_print_unsigned(unsigned int n)
{
    char digit;
    int count;

    count = 0;
    if (n > 9)
        count += ft_print_unsigned(n / 10); 
    digit = (n % 10) + '0';
    count += write(1, &digit, 1);
    return count;
}

int ft_print_hex(unsigned int num, int uppercase)
{
    char *base;
    char digit;
    int count;

    count = 0;
    if (uppercase == 1)
        base = "0123456789ABCDEF";
    else
        base = "0123456789abcdef";
    if (num > 15)
        count += ft_print_hex(num / 16, uppercase);
    digit = base[num % 16];
    count += write(1, &digit, 1);
    return count;
}