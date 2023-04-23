#include "./include/so_long.h"

int	main(int argc, char **argv)
{

	char *message="Hello";
	ft_printf("\033[0;31m%s\033[0m", message);
	return (0);
}
