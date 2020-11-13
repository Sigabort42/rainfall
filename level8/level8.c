#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*service;
char	*auth;

int	main()
{
	char		s[32];
	int		i;
	unsigned int	dl; //	uint8_t
	unsigned int	al; //	uint8_t

	while (1)
	{
		s[0] = 0;
		printf("%p, %p \n", auth, service);
		fgets(s , 128, stdin);
		if (s[0] == 0)
		{
			s[0] = 0;
			return (0);
		}
		i = 0;
		char *v = "auth ";
		while (s[i] == v[i] && i < 5)
			i++;
		dl = s[i] > v[i];
		al = s[i] < v[i];
		if (!al)
		{
			i = 0;
			auth = malloc(4);
			auth = 0;
			while (s[i])
				i++;
			if (i <= 30)
				strncpy(auth, s, 6);
		}
		i = 0;
		char *r = "reset";
		while (s[i] == r[i] && i <= 5)
			i++;
		dl = s[i] > r[i];
		al = s[i] < r[i];
		if (!al)
			free(auth);
		i = 0;
		char *b = "service";
		while (s[i] == b[i] && i <= 6)
			i++;
		dl = s[i] > b[i];
		al = s[i] < b[i];
		if (!al)
			service = strdup(s);
		i = 0;
		char *l = "login";
		while (s[i] == l[i] && i <= 5)
			i++;
		dl = s[i] > l[i];
		al = s[i] < l[i];
		if (!al)
		{
			if (!auth[32])
				system("/bin/sh");
			else
				fwrite("Password:\n", 1, 10, stdout);
		}
	}
	
	return (0);
}
