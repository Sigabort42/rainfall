#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char	*c;

void		m()
{
	char	*s1;
	time_t	t;

	s1 = "%s - %d\n";
	t = time(0);
	printf(s1, c, t);
}

int	main()
{
	void	*s1[2];
	void	*s2[2];

	s1[0] = malloc(8);
	s1[0] = 0x1;
	s1[1] = malloc(8); 
	s2[0] = malloc(8);
	s2[0] = 0x2;
	s2[1] = malloc(8);
	strcpy(s1[1], argv[1]);
	strcpy(s2[1], argv[2]);
	fgets(c, 68, fopen("/home/user/level8/.pass", "r"));
	puts("~~");
	return (0);
}
