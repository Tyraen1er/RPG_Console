#ifndef JEU_H
# define JEU_H

#include "libft.h"

#define GUERRIER 1
#define VOLEUR 2
#define MAGE 3

typedef struct  s_stat
{
    int         force;
    int         dexterite;
    int         volonte;
    int         charisme;
    int         sagesse;
}               t_stat;

typedef struct  s_personnage
{
    char        *name;
    int         classe;
    int         sexe;
    t_stat      stat;
}               t_personnage;

#endif
