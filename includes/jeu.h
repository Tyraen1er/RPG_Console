#ifndef JEU_H
# define JEU_H

# include "libft.h"

# define GUERRIER 1
# define VOLEUR 2
# define MAGE 3

typedef struct		s_quete
{
	int				id;
	int				(*etat)();
	struct s_quest	*nextQuest;
}					t_quete;

typedef struct	s_stat
{
	int			force;
	int			dexterite;
	int			volonte;
	int			charisme;
	int			sagesse;
}				t_stat;

typedef struct	s_perso
{
	char		name[21];
	int			classe;
	int			sexe;
	t_stat		stat;
	t_quete		*journal;
	int			chapitre;
}				t_perso;

void			clear();
char			*ft_get_line();
void			ft_pass();
void			chapitre_0(t_perso *joueur);
void			chapitre_1(t_perso *joueur);


// QUETES
int		principal_1();

#endif
