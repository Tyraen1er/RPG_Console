#include "jeu.h"
#include "quetes.c"

void	clear()
{
#ifdef OSisWindows
	system("cls");
#else
	system("clear");
#endif
}

t_quete		*new_quete(int id)
{
	t_quete	*quete;

	quete = (t_quete*)malloc(sizeof(t_quete));
	quete->id = id;
	if (id == 0)
	{
		quete->etat = &principal_1;
	}
	else if (id == 1)
	{
	}
	else if (id == 2)
	{
	}
	else
	{
		printf("Quête non implémentée\n");
		return (NULL);
	}
	return (quete);
}

void	check_quetes(t_perso *joueur)
{
	t_quete	*tmp;

	tmp = joueur->journal;
	while (tmp->nextQuest != NULL)
	{
		tmp->etat();
	}
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
	ft_str_lower(ret);
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
