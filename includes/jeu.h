#ifndef JEU_H
# define JEU_H

#include "libft.h"

#define GUERRIER 1
#define VOLEUR 2
#define MAGE 3

typedef struct	s_quest
{
	int				*(*valide)();
	struct s_quest	*nextQuest;
}					t_quest;

typedef struct	s_stat
{
	int			force;
	int			dexterite;
	int			volonte;
	int			charisme;
	int			sagesse;
}				t_stat;

typedef struct	s_personnage
{
	char		name[21];
	int			classe;
	int			sexe;
	t_stat		stat;
	t_quest		*journal;
}				t_personnage;

void			clear();
char			*ft_get_line();
void			ft_pass();

#endif
