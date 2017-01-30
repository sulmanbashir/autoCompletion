#ifndef _AUTOCOMPLETION_H_
# define _AUTOCOMPLETION_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

//enum typeVoie {allée, rue, boulevard};

typedef struct element element;
struct	element
{
  char	*ville;
  char	*nomvoie;
  char	*num;
  char	*type;
  struct	element *nxt;
};

typedef struct basket basket;
struct	basket
{
  char	*error;
  struct	basket *nxt;
};

typedef struct proba proba;
struct proba
{
  char	c;
  int	n;
  struct	proba *nxt;
};

typedef element* llist;
typedef basket*	llist_basket;
typedef proba* llist_proba;

char	**save_dico(char *buffer);
char	**save_dico2(char **point, char *str, int i, int k);
char	**read_file(char *file);
char	**cut_addr(char *buffer);
char	**cut_addr2(char **point, char *str, int i, int k);
char	**init_ville(char **stock);
char    **init_ville2(char **point, char **str, int i, int k);
int	check_addr(char **stock);
char	**separate(char *stock);
char    **init_type();
char    *add_ville(char **str);
char    *add_numvoie(char **str);
char    *add_type(char **str);
char    *add_nom(char **str, char **typevoie);
char	*probaM(llist liste);
char	*probaM2(llist liste);
char    **stock(char *buffer);
char    **stock2(char **point, char *str, int i, int k);
char	*trie_alpha(llist liste);
char	*trie_alpha2(llist liste);
//llist_proba	probability(char *str, llist_proba listeproba);
llist_proba     run(llist liste, llist_proba liste_proba);
//void	first_suggestion(llist_proba liste);
llist_proba	add_proba(char c, int n, llist_proba liste_proba);
char    *read_buffer();
#endif
