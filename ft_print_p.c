#include "ft_printf.h"

void	ft_puthex(unsigned long n)
{
	if (n > 15)
	{
		ft_puthex((n / 16));
		ft_puthex((n % 16));
	}
	else if (n < 10)
	{
		ft_putchar(n + '0');
	}
	else
	{
		if (n == 10)
			ft_putchar('a');
		if (n == 11)
			ft_putchar('b');
		if (n == 12)
			ft_putchar('c');
		if (n == 13)
			ft_putchar('d');
		if (n == 14)
			ft_putchar('e');
		if (n == 15)
			ft_putchar('f');
	}
}

int			print_pointer(va_list args, t_parse *ag_str)
{
	void	*ptr;
	int		wi;

	ptr = va_arg(args, void*);
	wi = ag_str->width;
	if (wi != 0 && ag_str->negative == 0)
		print_void(' ', wi - 14);
	write(1, "0x", 2);
	ft_puthex((unsigned long)ptr);
	if (wi != 0 && ag_str->negative == 1)
		print_void(' ', wi - 14);
	return (wi > 14 ? wi : 14);
}