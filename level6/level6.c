#include <stdio.h>
#include <stdlib.h>

void	m()
{
	puts("Nope");
}

void	n()
{
	system("/bin/cat /home/user/level7/.pass");
}

int	main()
{
	void	*s;
	void	(*f)();

	s = malloc(64);
	f = malloc(4);
	f = m;
	
	strcpy(s, argv[1]);
	f();
	return (0);
}
