#include "jeu.h"

int	main()
{
	t_perso	joueur[1];
/*
	int		fd;

//	SYSTEME SAUVEGARDE POTENTIEL

	if (-1 == (fd = open("save.rpg", O_RDWR | O_CREAT , 0777)))
	{
		printf("coucou il y a une erreur avec open\n");
		return (0);
	}
	printf("le fd = %d\n", fd);
	sleep(3);
*/
	ft_bzero(joueur->name, 21);
	clear();

	chapitre_0(joueur);
	chapitre_1(joueur);
	printf("Désolé ceci est la fin du jeu pour le moment. N'hésitez pas\nà faire chier Manu pour qu'il le continue !\n");
	return (0);
}

void	chapitre_0(t_perso *joueur)
{
	char			*tmp;

	joueur->chapitre = 0;
	printf("Bonjour et bienvenue dans mon jeu ! Avant toute chose il vous faut savoir\nque vous faites passer les dialogues avec la touche entrée.\n");
	ft_pass();
	printf("Bien joué ! Vous comprenez vite !\n");
	ft_pass();
	printf("A présent, sachez que vous vous trouvez dans un RPG. Autrement dit :\nun jeu de rôle. Afin de jouer il vous faut choisir un personnage.\nVous avez le choix entre :\n");
	ft_pass();
	printf("\nLe courageux guerrier a la force sans égale.\n\nLe puissant mage aux connaissances ocultes.\n\n");
	ft_pass();
	
	printf("Veuillez écrire la classe qui vous intéresse : Guerrier ou Mage\n");
	joueur->classe = 0;
	while (!joueur->classe)
	{
		tmp = ft_get_line();
		if ((strstr(tmp, "guerrier")))
			joueur->classe = GUERRIER;
		else if ((strstr(tmp, "mage")))
			joueur->classe = MAGE;
		else
			printf("Navré,je ne sais pas ce que c est. Choisissez autre chose.\nQuelle sera votre classe ?\nGuerrier - Mage\n\n");
		ft_memdel((void*)&tmp);
	}
	printf("\nAinsi tu as choisi la ");
	if (joueur->classe == GUERRIER)
		printf("fière voie des guerriers !\n");
	if (joueur->classe == MAGE)
		printf("voie des arcanes !\n");
	ft_pass();

	printf("Voulez vous jouer un homme ou une femme ?\n");
	joueur->sexe = 0;
	while (!joueur->sexe)
	{
		tmp = ft_get_line();
		if ((strstr(tmp, "homme")))
			joueur->sexe = HOMME;
		else if ((strstr(tmp, "femme")))
			joueur->sexe = FEMME;
		else
			printf("Il vous faut prendre un de ces deux choix. Homme ou Femme ?\n\n");
		ft_memdel((void*)&tmp);
	}
	printf("Tu es donc un%s. Maintenant que nous avons déterminé ta classe et ton genre, il nous faut savoir\ncomment tu t'appelles ! Quel est donc ton nom ?\n", (joueur->sexe == HOMME) ? " homme" : "e femme");

	tmp = ft_get_line();
	while (!strlen(tmp) || 20 < strlen(tmp))
	{
		if (20 < strlen(tmp))
			printf("\nVotre nom ne doit pas excéder une taille de 20 caractères.\nQuel sera donc votre nom ?\n");
		else
			printf("\nDésolé d'insister mais je tiens à connaitre votre nom ! Quel sera t-il ?\n");
		ft_memdel((void*)&tmp);
		tmp = ft_get_line();
	}
	*tmp = toupper(*tmp);
	strcpy(joueur->name, tmp);
	ft_memdel((void*)&tmp);
	printf("Ravi de vous connaitre %s !\n", joueur->name);
	ft_pass();

	printf("Pour ma part, vous pouvez m'appeler Elvelik, je suis une sorte de magicien\nqui a une facheuse tendance a se mêler de tout ce qui ne le regarde pas.\nEt je suis le seul au monde a pouvoir vous parler actuellement !\n");
	ft_pass();
	printf("...\n");
	ft_pass();
	printf("On pourrait presque dire que je suis une des divinités de ce monde...\n");
	ft_pass();
	printf("Trêve de bavardage j'ai à faire, bienvenue à Ilenaï. Laisse moi juste le temps\nde te redonner un corps physique... Et voilà ! Tu n'as qu'à\ndécouvrir un peu cet univers par toi même jusqu'à notre prochaine rencontre !\n");
	ft_pass();
}

void	chapitre_1(t_perso *joueur)
{
	char			*tmp;

	joueur->chapitre = 1;
	tmp = NULL;
	(void)joueur;
	printf("|-------------------------------------------------------------------------------|\n\nVous vous réveillez en sueur dans une taverne de bois et de pierre.\nVous appercevez le TENANCIER accoudé au bar en train de laver un verre au coté\nd'une FEMME armurée et très équipée qui vous tourne le dos. Un HOMME sur votre\ndroite semble ennuyé face des documents ressemblant à de la comptabilité.\nVous êtes vous même assis à une table avec une chope contenant un liquide\ninconnu à la main. Pour finir vous sentez un courant d'air frais venir de la\nPORTE derrière vous. Que faites vous ?\n(Entrez un seul mot-clé qui sont les mots en majuscules.)\n");
	while (!tmp)
	{
		tmp = ft_get_line();
		if ((strstr(tmp, "tenancier")))
			printf("Il dit qu'il t'emmerde.\n");
		else if ((strstr(tmp, "femme")) || (strstr(tmp, "homme")))
			printf("J'aimerais boire ma biere sans avoir à te parler...\n");
		else if (strstr(tmp, "porte"))
			printf("La porte d'entrée de la taverne est ouverte en continue pour inviter les\npassants à entrer. En l'empreintant vous vous trouvez momentanément ébloui.\n");
		else
		{
			printf("Oui, que fais-tu ?\n");
			ft_memdel((void*)&tmp);
		}
	}
	ft_pass();
	ft_memdel((void*)&tmp);
}
