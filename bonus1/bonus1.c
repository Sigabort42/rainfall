#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	char	s[40];
	int	r;

	r = atoi(av[1]);
	if (r <= 9)
	{
		r = r * 4 + 0;
		memcpy(s , av[2], r);
		if (r == 0x574f4c46)
			execl("/bin/sh", "sh", 0);
	}
	else
		return (1);
	return (0);
}
