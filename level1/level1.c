#include <stdio.h>
#include <stdlib.h>

void	run()
{
	char	*s = "Good... Wait what?\n";
	fwrite(s, 1, 13, stdout);
	system("/bin/sh");
}

int	main()
{
	char	s[64];

	gets(s);
	return (0);
}
