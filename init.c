#include "autoCompletion.h"

char	**init_type()
{
  char	**tab;
  int   i;
  char  **point;

  i = 0;
  if ((tab = malloc(1024 * sizeof(char*))) == NULL)
    {
      printf("\Error in Malloc()\n");
      return (NULL);
    }
  while (i <= 1024)
    tab[i++] = malloc(1024 * sizeof(char));
  if (tab == NULL)
    printf("n\Error\n");
  tab[0] = "allée";
  tab[1] = "avenue";
  tab[2] = "boulevard";
  tab[3] = "chemin";
  tab[4] = "impasse";
  tab[5] = "place";
  tab[6] = "quai";
  tab[7] = "rue";
  tab[8] = "square";
  tab[9] = NULL;
  return (tab);
}
