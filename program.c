#include "autoCompletion.h"

char	*probaM(llist liste)
{
  element *i = liste;
  int	k = 0;
  char	*test = malloc(sizeof(char) * 1024);
  while (i != NULL)
    {
      test[k] = i->ville[0];
      i = i->nxt;
      k++;
    }
  return (test);
}

char	*probaM2(llist liste)
{
  element	*n = liste;
  int	j = 0;
  int	k = 0;
  char	*test2 = malloc(sizeof(char) * 1024);
  
  while (n != NULL)
    {
      while (n->ville[j] != '\0')
        {
          if (n->ville[j] == ' ')
            {
              test2[k] = n->ville[j+1];
              k++;
            }
          j++;
        }
      j = 0;
      n = n->nxt;
    }
  return (test2);
}

llist_proba	add_proba(char c, int n, llist_proba liste_proba)
{
  proba	*new = malloc(sizeof(proba));
  proba	*position = NULL;
  proba	*i = liste_proba;

  if (new == NULL)
    exit (EXIT_FAILURE);
  new->c = c;
  new->n = n;
  while (i != NULL && i->n < n)
    {
      position = i;
      i = i->nxt;
    }
  new->nxt = i;
  if (position != NULL)
    position->nxt = new;
  else
    liste_proba = new;
  //  return (new);
}

llist_proba	probability(char *str, llist_proba liste_proba)
{
  int	i = 0;
  int	j = 0;
  int	n = 0;
  char	c;
  
  while (str[i] != '\0')
    {
      while (i != j)
	i++;
      while (str[j] == str[i])
	{
	  c = str[i];
	  j++;
	  n++;
	}
      liste_proba = add_proba(c, n, liste_proba);
      n = 0;
      i++;
    }
  return (liste_proba);
}

char    *order(char *str)
{
  int   i = 0;
  int   j = 0;
  int   previous = 0;
  int   count = strlen(str);

  while (i < count)
    {
      previous = str[i];
      j = i;
      while (str[j-1] > previous)
        {
          str[j] = str[j - 1];
          j--;
        }
      str[j] = previous;
      i++;
    }
  return (str);
}

char	*trie_alpha(llist liste)
{
  char	*test;
  char	*test2;
  char	*all;
  int	count;
  int	i = 0;
  int	j = 0;
  char	*tab;

  test = probaM(liste);
  test2 = probaM2(liste);
  all = strcat(test, test2);
  count = strlen(all);
  tab[count];
  while (tab[i] != count)
    {
      tab[i] = all[i];
      i++;
    }
  tab = order(tab);
  return (tab);
}

llist_proba	first_suggestion(llist_proba liste)
{
  proba	*i = liste;
  char	test[100];
  int x = 0;
  int	j = 0;

  while (i != NULL)
    {
      test[x] = i->c;
      i = i->nxt;
      x++;
    }
  while (x != 1)
    {
      if (test[x] == '\0')
	x--;
      if (j == 5)
	test[x] = '\0';
      if (test[x] >= 65 && test[x] <= 90)
	test[x] = test[x] + 32;
      else
	test[x] = test[x];
      printf("{%c} ", test[x]);
      x--;
      j++;
    }
  printf("\n");
}

llist_proba	run(llist liste, llist_proba liste_proba)
{
  char	*str = malloc(sizeof(char) *1024);

  str = trie_alpha(liste);
  liste_proba = probability(str, liste_proba);
  return (liste_proba);
}
