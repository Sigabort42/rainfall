#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	p()
{
	char		s[76];
	void		*eip;
	
	fflush(stdout);
	gets(s);
	eip = (void*)s[80];
	if (((unsigned int)eip & 0xb0000000) == 0xb0000000)
	{
		printf("(%p)\n", eip);
		exit(1);
	}
	else
	{
		puts(s);
		strdup(s);
	}
}

int	main()
{
	p();
	return (0);
}
