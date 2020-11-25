#include <stdio.h>

int	main()
{
	char	s1[66];
	char	s2[65];
	FILE	*fd;
	
	fd = fopen("/home/user/end/.pass", "r");
	bzero(s1, 33);
	if (!fd)
		return (-1);
	if (ac != 2)
		return (-1);
	fread(s1 ,1 ,66 , fd);
	s1[atoi(av[1])] = '\0';
	fread(s2 ,1 ,65 , fd);
	fclose(fd);
	if (!strcmp(s1, av[1]))
		execl("/bin/sh" ,"sh" , 0);
	else
		puts(s1);
	return (0);
}
