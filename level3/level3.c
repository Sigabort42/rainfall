#include <stdio.h>
#include <stdlib.h>

int	m;

void	v()
{
	char	s[520];
	int	r;
	
	fgets(s, 512, stdin);
	r = printf(s);
	if (m == 64)
	{
		fwrite("Wait what?!\n", 1, 12, stdout);
		system("/bin/sh");
	}
}

int	main()
{
	v();
	return (0);
}
