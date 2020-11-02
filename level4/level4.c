#include <stdio.h>
#include <stdlib.h>

int		m;

void		p(char *s)
{
		printf(s);
}

void		n()
{
	char	s[520];

	fgets(s, 2, stdin);
	p(s);
	if(m == 0x1025544)
		system("/bin/cat /home/user/level5/.pass");
}


int		main()
{
		n();
		return (0);
}
