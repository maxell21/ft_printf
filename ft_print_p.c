#include "ft_printf.h"

static int	count_len(unsigned long number)
{
	int i;

	i = 1;
	while (number /= 16)
		i++;
	return (i);
}

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
	int		len;
	int fl;

	fl = 0;
	ptr = va_arg(args, void*);
	len = count_len((unsigned long)ptr);
	wi = ag_str->width;
	if (wi != 0 && ag_str->negative == 0 && !ag_str->zero)
		print_void(' ', wi - (len + 2));
	else if (wi != 0 && ag_str->zero)
	{
		write(1, "0x", 2);
		print_void('0', wi - (len + 2));
		fl = 1;
	}
	!fl ? write(1, "0x", 2) : 0;
	ft_puthex((unsigned long)ptr);
	if (wi != 0 && ag_str->negative == 1)
		print_void((ag_str->zero == 1 ? '0' : ' '), wi - len);
	return (wi > (len + 2) ? wi : len + 2);
}
