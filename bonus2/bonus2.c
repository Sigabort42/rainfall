#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	lang = 0;

void	greetuser(char *s1)
{
	char	msg[72];
	
	if (lang == 1)
		strcpy(msg, "Hyvää päivää ");
	else if (lang == 2)
		strcpy(msg[0], "Goedemiddag! ");
	else if (!lang)
		strcpy(msg[0], "Hello ");
	strcat(msg, s1);
	puts(msg);
}

int	main(int ac, char **av)
{
	char	s1[40];
	char	s2[32];
	char	*l;
	
	if (ac != 3)
		return (1);
	strncpy(s1 , av[1], 40);
	strncpy(s2, av[2], 32);
	l = getenv("LANG");
	if (l)
	{
		if (!memcmp(l ,"fi" , 2))
			lang = 1;
		else if (!memcmp(l ,"nl" , 2))
			lang = 2;
	}
	greetuser(s1);
	return (0);
}
