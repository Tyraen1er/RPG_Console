#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char    *get_line(char *buf)
{
    char a;
    char *ret;

    a = 20;
    ret = NULL;
    while (a == 20)
    {
        if ((a = read(0, buf, 20)) == -1)
        {
            printf("\nread error\n");
			exit(3);
        }
        ft_bzero(&buf[a], 20 - a);
        if (!ret)
            ret = ft_strdup(buf);
        else
            ret = ft_strjoin(ret, buf);
    }
 }

void	ft_pass(void)
{
    char a;
    char b;
    char buf[21];

    buf[20] = 0;
    b = 0;
	while (b != 50)
	{
		if (-1 == (a = read(0, buf, 20)))
		{
			printf("\nread error\n");
			exit(3);
		}
		ft_bzero(&buf[a], 20 - a);
		while (b <= a)
		{
		    if (buf[b++] == '\n')
                b = 50;
		}
    }
}

   int	ft_words(char *word, char *buf)
{
    int a;

    if (-1 == (a = read(0, buf, 20)))
    {
        printf("error");
        exit(3);
    }
    ft_bzero(&buf[a - 1], 20 - a);
    if (!strcmp(buf, word))
        return (1);
    return(0);
}

int	main()
{
	int		a;
	int		b;
	char	buf[21];
	char	*name;
	char	*classe;

	buf[20] = '\0';
	   printf("%s", "Bonjour et bienvenue dans mon jeu ! Avant toute chose il vous faut\nsavoir que vous faites passer les dialogues avec la touche entree.\n");
	   ft_pass();
	   printf("%s", "Bien joue ! Vous comprenez vite !\n");
	   ft_pass();
	   printf("%s", "A present, sachez que vous vous trouvez dans un RPG. Autrement dit :\nun jeu de role. Afin de jouer il vous faut choisir un personnage.\nVous avez le choix entre :\n");
	   ft_pass();
	   printf("%s", "\nLe courageux guerrier a la force sans egale.\n\nLe puissant mage aux connaissances ocultes.\n\nLe mysterieux voleur aux ruses multiples.\n\n");
	   ft_pass();
	a = 0;
	b = 0;
	printf("%s", "Veuillez ecrire la classe qui vous interesse : guerrier, mage ou voleur\n");

	ft_bzero(buf, 20);
	a = 1;
	while (b == 0)
	{
		while (a == 1)
		{
			if ((a = read(0, buf, 20)) == -1)
			{
				printf("%s", "error");
				exit(3);
			}
		}
		ft_bzero(&buf[a - 1], 20 - a);
		if (!(strcmp(buf, "guerrier")))
			b = 1;
		else if (!(strcmp(buf, "mage")))
			b = 2;
		else if (!(strcmp(buf, "voleur")))
			b = 3;
		else
		{
			while (20 == (a = read(0, buf, 20)))
			{
				if (a == -1)
				{
					printf("%s", "error");
					exit(3);
				}
			}
			if ((a = read(0, buf, 20)) == -1)
			{
				printf("%s", "error");
				exit(3);
			}
			ft_bzero(&buf[a], 20);
			printf("Navré,je ne sais pas ce que c est. Choisissez autre chose.\nQuelle sera votre classe ?\nguerrier - mage - voleur\n");
		}
	}
	classe = ft_strdup(buf);
	printf("%s", classe);
	printf("%s", "\nAinsi tu as choisi la ");
	if (b == 1)
		printf("%s", "fiere voie des guerriers !\n");
	if (b == 2)
		printf("%s", "voie des arcanes !\n");
	if (b == 3)
		printf("%s", "voie des gens de l'ombre !\n");
	ft_pass();
	free(name);
	name = NULL;
	printf("%s", "Maintenant que nous avons determine ta classe, il nous faut savoir comment tu t'appelles !\nQuel est donc ton nom ?\n");

	a = 1;
	while (a == 1)
	{
		if ((a = read(0, buf, 20)) == -1)
		{
			printf("%s", "error");
			exit(3);
		}
	}
	while (a == 20)
	{
		printf("\nVotre nom ne doit pas exceder une taille de 20 caracteres. Quel sera donc votre nom ?\n");
		while (20 == (a = read(0, buf, 20)))
		{
			if (a == -1)
			{
				printf("%s", "error");
				exit(3);
			}
		}
		if ((a = read(0, buf, 20)) == -1)
		{
			printf("%s", "error");
			exit(3);
		}
		while (a == 1)
		{
			if ((a = read(0, buf, 20)) == -1)
			{
				printf("%s", "error");
				exit(3);
			}
		}
	}
	name = ft_strndup(buf, a - 1);
	printf("Ravi de vous connaitre %s !\n", name);
	ft_pass();
	printf("%s", "\nDesole ceci est la fin du jeu pour le moment. N'hesitez pas\nfaire chier Manu pour qu'il le continue !\n");
	return(0);
}
