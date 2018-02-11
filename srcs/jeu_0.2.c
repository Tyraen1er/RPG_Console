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
				return ;
		}
	}
}

int	main()
{
	char			*tmp;
	t_personnage	player;

	player.classe = 0;
	ft_bzero(player.name, 21);
	clear();

	printf("Bonjour et bienvenue dans mon jeu ! Avant toute chose il vous faut savoir\nque vous faites passer les dialogues avec la touche entree.\n");
	ft_pass();
	printf("Bien joue ! Vous comprenez vite !\n");
	ft_pass();
	printf("A present, sachez que vous vous trouvez dans un RPG. Autrement dit :\nun jeu de role. Afin de jouer il vous faut choisir un personnage.\nVous avez le choix entre :\n");
	ft_pass();
	printf("\nLe courageux guerrier a la force sans egale.\n\nLe puissant mage aux connaissances ocultes.\n\nLe mysterieux voleur aux ruses multiples.\n\n");
	ft_pass();

	printf("Veuillez ecrire la classe qui vous interesse : guerrier, mage ou voleur\n");
	while (!player.classe)
	{
		tmp = ft_get_line();
		if ((strstr(tmp, "guerrier")))
			player.classe = GUERRIER;
		else if ((strstr(tmp, "voleur")))
			player.classe = VOLEUR;
		else if ((strstr(tmp, "mage")))
			player.classe = MAGE;
		else
			printf("Navré,je ne sais pas ce que c est. Choisissez autre chose.\nQuelle sera votre classe ?\nguerrier - mage - voleur\n\n");
		ft_memdel((void*)&tmp);
	}
	printf("\nAinsi tu as choisi la ");
	if (player.classe == GUERRIER)
		printf("fiere voie des guerriers !\n");
	if (player.classe == MAGE)
		printf("voie des arcanes !\n");
	if (player.classe == VOLEUR)
		printf("voie des gens de l'ombre !\n");
	ft_pass();
	printf("Maintenant que nous avons determine ta classe, il nous faut savoir comment tu\nt'appelles ! Quel est donc ton nom ?\n");

	tmp = ft_get_line();
	while (!strlen(tmp) || 20 < strlen(tmp))
	{
		if (20 < strlen(tmp))
			printf("\nVotre nom ne doit pas exceder une taille de 20 caracteres.\nQuel sera donc votre nom ?\n");
		else
			printf("\nDesole d'insister mais je tiens à connaitre votre nom ! Quel sera t-il ?\n");
		ft_memdel((void*)&tmp);
		tmp = ft_get_line();
	}
	strcpy(player.name, tmp);
	ft_memdel((void*)&tmp);
	printf("Ravi de vous connaitre %s !\n", player.name);
	ft_pass();

	printf("Pour ma part, vous pouvez m'appeler Elvelik, je suis une sorte de magicien\nqui a une facheuse tendance a se mêler de tout ce qui ne me regarde pas.\nEt je suis le seul au monde a pouvoir vous parler !\n");
	ft_pass();
	printf("...\n");
	ft_pass();
	printf("On pourrait presque dire que je suis une des divinités de ce monde...\n");
	ft_pass();
	printf("Trêve de bavardage j'ai à faire, bienvenue à Ilenaï. Tu n'as qu'à\ndécouvrir un peu cet univers par toi même jusqu'à notre prochaine rencontre !\n");
	ft_pass();
	printf("|------------------------------------------------|\n\nVous vous réveillez en sueur dans une taverne de bois et de pierre.\nVous appercevez le TENANCIER accoudé au bar en train de laver un verre au coté\nd'une FEMME armurée et très équipée qui vous tourne le dos. Un HOMME sur votre\ndroite semble ennuyé face des documents ressemblant à de la comptabilité.\nVous êtes vous même assis à une table avec une chope contenantun liquide\ninconnu à la main. Pour finir vous sentez un courant d'air frais venir de la\nporte derrière vous. Que faites vous ?\n(Entrez un seul mot-clé)\n");
	tmp = ft_get_line();
	if ((strstr(tmp, "tenancier")))
		printf("Il dit qu'il t'emmerde.\n");
	else
		printf("J'aimerais boire ma biere sans avoir à te parler...\n");
	ft_pass();
	ft_memdel((void*)&tmp);
	printf("Desole ceci est la fin du jeu pour le moment. N'hesitez pas\na faire chier Manu pour qu'il le continue !\n");
	return (0);
}
