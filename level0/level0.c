#include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

int main(int ac, char **av)
{
	int   r;
	char  *s;
	gid_t gid;
	uid_t euid;
	char  *cmd[2];

	r = atoi(av[1]);
	if (r == 423)
	{
		s = strdup("/bin/sh");
		gid = getegid();
		euid = geteuid();

		setresgid(gid, gid, gid);
		setresuid(euid, euid, euid);


		cmd[1] = 0;
		cmd[0] = "/bin/sh";
		execve(s, cmd, 0);
	}
	else
		fwrite("No !\n", 1, 5, stderr);
	return (0);
}
