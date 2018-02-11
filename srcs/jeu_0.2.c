#include "jeu.h"

int		ft_str_search_word(const char *word, const char *sentance)
{
	size_t	a;

	if (!word || !sentance)
		return (-1);
	a = 0;
	while (a < ft_strlen(sentance))
	{
		if (sentance[a] == word[0] && !(strcmp(word, &(sentance[a]))))
			return(a);
        ++a;
	}
	return (-1);
}

char    *ft_get_line(char *buf)
{
    char	a;
    char	*ret;

    a = 20;
    ret = NULL;
    while (a == 20)
    {
        if ((a = read(0, buf, 20)) == -1)
        {
            printf("\nread error\n");
			exit(3);
        }
        ft_bzero(buf + a, 20 - a);
        if (!ret)
            ret = ft_strdup(buf);
        else
            ret = ft_strjoin(ret, buf);
    }
    ret[ft_strlen(ret) - 1] = 0;
    return (ret);
 }

void	ft_pass(void)
{
    int     a;
    int     b;
    char    buf[21];

    buf[20] = 0;
    b = 0;
	while (b != 50)
	{
		if (-1 == (a = read(0, buf, 20)))
		{
			printf("\nread error\n");
			exit(3);
		}
		ft_bzero(buf + a, 20 - a);
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
        printf("error\n");
        exit(3);
    }
    ft_bzero(&buf[a - 1], 20 - a);
    if (!strcmp(buf, word))
        return (1);
    return (0);
}

int	main()
{
	int		a;
	int		b;
	char	buf[21];
	t_personnage	joueur;
	char    *tmp;
	char	*name;
	char	*classe;

    (void)joueur;
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
			joueur.classe = GUERRIER;
		else if (!(strcmp(tmp, "voleur")))
			joueur.classe = VOLEUR;
		else if (!(strcmp(tmp, "mage")))
			joueur.classe = MAGE;
		else
			printf("Navré,je ne sais pas ce que c est. Choisissez autre chose.\nQuelle sera votre classe ?\nguerrier - mage - voleur\n\n");
	}
	classe = ft_strdup(buf);
	printf("%s", classe);
	printf("%s", "\nAinsi tu as choisi la ");
	if (b == GUERRIER)
		printf("%s", "fiere voie des guerriers !\n");
	if (b == MAGE)
		printf("%s", "voie des arcanes !\n");
	if (b == VOLEUR)
		printf("%s", "voie des gens de l'ombre !\n");
	ft_pass();
	name = NULL;
	printf("%s", "Maintenant que nous avons determine ta classe, il nous faut savoir comment tu t'appelles !\nQuel est donc ton nom ?\n");

	a = 1;
	while (a == 1)
	{
		if ((a = read(0, buf, 20)) == -1)
		{
			printf("%s", "error\n");
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
				printf("%s", "error\n");
				exit(3);
			}
		}
		if ((a = read(0, buf, 20)) == -1)
		{
			printf("%s", "error\n");
			exit(3);
		}
		while (a == 1)
		{
			if ((a = read(0, buf, 20)) == -1)
			{
				printf("%s", "error\n");
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
	return (0);
}
