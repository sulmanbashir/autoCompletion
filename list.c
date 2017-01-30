#include "autoCompletion.h"

char    *add_ville(char **str)
{
  int   i = 0;
  int   k = 0;
  int   j = 1;

  while (str[i] != NULL)
    {
      while (str[i][k] != '\0')
        k++;
      if (str[i][k-1] == ',' || str[i][k] == '\n')
        {
          while (j != i + 1)
            {
              str[0] = strcat(str[0], " ");
              str[0] = strcat(str[0], str[j]);
              j++;
            }
          j = 0;
        }
      k = 0;
      i++;
    }
  return (str[0]);
}

char    *add_numvoie(char **str)
{
  int   i = 0;
  int   k = 0;
  int   j = 1;

  while (str[i] != NULL)
    {
      while (str[i][k] != '\0')
        k++;
      if (str[i][k-1] == ',')
        str[1] = str[i+1];
      k = 0;
      i++;
    }
  return (str[1]);
}

char    *add_type(char **str)
{
  int   i = 0;
  int   k = 0;
  char  *type = malloc(sizeof(char) * 1024);

  while (str[i] != NULL)
    {
      while (str[i][k] != '\0')
        k++;
      if (str[i][k-1] == ',')
        type = str[i + 2];
      k = 0;
      i++;
    }
  return (type);
}

char    *add_nom(char **str, char **typevoie)
{
  int   i = 0;
  int   k = 0;
  int   j = 0;
  char  *nom = malloc(sizeof(char) * 1024);

  while (str[i] != NULL)
    {
      while (typevoie[j] != NULL)
        {
          if (strcmp(typevoie[j], str[i]) == 0)
            {
              k = i+1;
              while (str[k] != NULL)
                {
                  nom = strcat(nom, " ");
                  nom = strcat(nom, str[k]);
                  k++;
		}
            }
          k = 0;
          j++;
        }
      j = 0;
      i++;
    }
  return (nom);
}

void    view(llist liste)
{
  element *i = liste;
  
  while (i != NULL)
    {
      printf("%s %s %s %s\n", i->ville, i->num, i->type, i->nomvoie);
      i = i->nxt;
    }
}

void    view2(llist_proba probab)
{  
  proba *i = probab;

  while (i != NULL)
    {
      printf("%c = %d\n", i->c, i->n);
      i = i->nxt;

    }
}
