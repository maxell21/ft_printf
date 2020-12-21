#include "ft_printf.h"

int main()
{
 	// printf("original - %d\n", printf("%-*.*d", 123));
	// printf("my print - %d\n",
	// printf("orig = |%-3.2s|\n", "texttext");
	// ft_printf("mine = |%-3.2s|\n", "texttext");
	// ft_printf("mine = |%.5s|\n", "texttext");
	// char *ptr = "abc";
	// ft_printf("|%-100p|\n", a);
	// printf("|%-100p|\n", a);

	int a = printf("%.7s\n", "hello");
	int len = ft_printf("%.7s\n", "hello");
	printf("orig = %d, mine = %d\n", a, len);
	// printf("original = %s, %s\n", "abc", "def");
	return 0;
}
