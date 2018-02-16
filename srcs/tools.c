#include "jeu.h"

void	clear()
{
#ifdef OSisWindows
	system("cls");
#else
	system("clear");
#endif
}

char    *ft_get_line()
{
	int 	a;
	char	*ret;
	char	*buf;

	a = 20;
	ret = NULL;
	buf = (char[21]){0};
	while (a == 20)
	{
		if ((a = read(0, buf, 20)) == -1)
		{
			printf("\nread error\n");
			exit(3);
		}
		ft_bzero(buf + a, 21 - a);
		if (!ret)
			ret = ft_strdup(buf);
		else
			ret = ft_strjoin(ret, buf);
	}
	ret[ft_strlen(ret) - 1] = 0;
	for (a = 0 ; buf[a]; ++a)
		buf[a] = tolower(buf[a]);
	return (ret);
}

void	ft_pass()
{
	int		a;
	int		b;
	char	buf[21];

	buf[20] = 0;
	while (1)
	{
		b = 0;
		if (-1 == (a = read(0, buf, 20)))
		{
			printf("\nread error\n");
			exit(3);
		}
		ft_bzero(buf + a, 20 - a);
		while (b <= a)
		{
			if (buf[b++] == '\n')
				return ;
		}
	}
}
