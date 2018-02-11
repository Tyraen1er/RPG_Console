#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

size_t		ft_strlen(const char *str)
{
	int a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

char	*ft_strdup(const char *str)
{
	int		a;
	char	*dup;

	a = 0;
	while (str[a] != '\0')
		a++;
	dup = (char *)malloc(sizeof(char) * (a + 1));
	if (dup == NULL)
		return (NULL);
	a = 0;
	while (str[a] != '\0')
	{
		dup[a] = str[a];
		a++;
	}
	dup[a] = '\0';
	return (dup);
}

void	ft_bzero(void *tab, size_t n)
{
	while (n--)
		((char *)tab)[n] = 0;
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	a;

	if (src == dst)
		return (dst);
	else if (src < dst)
	{
		a = len - 1;
		while (a + 1 > 0)
		{
			((char *)dst)[a] = ((char *)src)[a];
			a--;
		}
	}
	else
	{
		a = 0;
		while (a < len)
		{
			((char *)dst)[a] = ((char *)src)[a];
			a++;
		}
	}
	return (dst);
}

char	*ft_strndup(const char *str, size_t n)
{
	char	*dup;

	dup = (char *)malloc(++n);
	if (dup == NULL)
		return (NULL);
    dup[--n] = 0;
	while (n--)
		dup[n] = str[n];
	return (dup);
}

void	*ft_memalloc(size_t sze)
{
	void	*spc;

	if (!(spc = malloc(sze)))
		return (NULL);
	while (sze--)
		((char *)spc)[sze] = 0;
	return (spc);
}

void	ft_memdel(void **ap)
{
	if (ap && *ap)
		free(*ap);
	*ap = NULL;
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	int		a;
	int		b;
	char	*ret;

	a = 0;
	b = 0;
	if (!str1 || !str2)
		return (NULL);
	while (str1[a] != '\0')
		a++;
	while (str2[b] != '\0')
		b++;
	if (!(ret = (char *)malloc(a + b + 1)))
		return (NULL);
	a = -1;
	b = -1;
	while (str1[++a] != '\0')
		ret[a] = ((char *)str1)[a];
	while (str2[++b] != '\0')
		ret[a++] = ((char *)str2)[b];
	ret[a] = '\0';
	return (ret);
}

void	*ft_realloc(void *str, size_t len_str, int add_bytes,
		size_t reading_speed)
{
	int		a;
	void	*new;

	if (!str)
		return (NULL);
	a = -1;
	if (0 < len_str + add_bytes &&
			!(new = ft_memalloc((len_str + add_bytes) * reading_speed)))
	{
		ft_memdel(&str);
		return (NULL);
	}
	if (0 <= add_bytes)
	{
		while (++a < (int)len_str)
			((char *)new)[a] = ((char *)str)[a];
	}
	else
		while (++a < ((int)len_str + add_bytes))
			((char *)new)[a] = ((char *)str)[a];
	ft_memdel(&str);
	return (new);
}

char    *ft_get_line(char *buf)
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
    ret[ft_strlen(ret) - 1] = 0;
    return(ret);
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
	char    *tmp;
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
		tmp = ft_strdup(ft_get_line(buf));
		if (!(strcmp(tmp, "guerrier")))
			b = 1;
		else if (!(strcmp(tmp, "mage")))
			b = 2;
		else if (!(strcmp(tmp, "voleur")))
			b = 3;
		else
			printf("Navré,je ne sais pas ce que c est. Choisissez autre chose.\nQuelle sera votre classe ?\nguerrier - mage - voleur\n\n");
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
	printf("\nPour ma part, vous pouvez m'appeler Elvelik, je suis une sorte de magicien\nqui a une facheuse tendance a se mêler de tout ce qui ne me regarde pas.\nEt je suis le seul au monde a pouvoir vous parler !\n");
	ft_pass();
	printf("\nOn pourrait presque dire que je suis une des divinités de ce monde...");
	ft_pass();
	printf("Trêve de bavardage j'ai à faire, bienvenue à Ilenaï. Tu n'as qu'à\ndécouvrir un peu cet univers par toi même jusqu'à notre prochaine rencontre !\n");
	ft_pass();
	printf("\n\nVous vous réveillez en sueur dans une taverne de bois et de pierre.\nVous appercevez le TENANCIER accoudé au bar en train de laver un verre au coté d'une FEMME armurée et très équipée qui vous tourne le dos.\nUn HOMME sur votre droite semble ennuyé face des documents ressemblant à de la comptabilité.\nVous êtes vous même assis à une table avec une chope contenantun liquide inconnu à la main. Pour finir vous sentez un courant d'air frais venir de la porte derrière vous.\nQue faites vous ?\n(Entrez un seul mot-clé)\n");
	ft_pass();
	printf("\nDesole ceci est la fin du jeu pour le moment. N'hesitez pas\na faire chier Manu pour qu'il le continue !\n");
	return(0);
}
