#include "../inc/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char buffer[1024];
	int ret;

	(void)argc;
	(void)argv;
	while ((ret = read(1, buffer, 1000)))
		;
	return (0);
}