#include <stdio.h>
#include <unistd.h>
#include <string.h>

void	p(char *s1, char *s2)
{
	char	str[4104];
	
	puts(s2);
	read(0, str, 4096);
	*strchr(str, 0xa) = '\0';
	strncpy(s1, str, 20);
}

void	pp(char *s)
{
	char	loc1[20];
	char	loc2[20];

	p(loc1, " - ");
	p(loc2, " - ");

	strcpy(s, loc1);
	s[strlen(s)] = 32;
	strcat(s, loc2);
}

int	main()
{
	char	locs[42];

	pp(locs);
	puts(locs);
	return (0);
}
