#include "autoCompletion.h"

char    **save_dico(char *buffer)
{
  int   i;
  int   k;
  char  **point;
  int   count;

  i = 0;
  k = 0;
  count = strlen(buffer);
  if ((point = malloc(count * sizeof(char*))) == NULL)
    {
      printf("\Error in Malloc()\n");
      return (NULL);
    }
  while (i <= count)
    point[i++] = malloc(1024 * sizeof(char));
  if (point == NULL)
    printf("n\Error\n");
  save_dico2(point, buffer, i, k);
}

char    **save_dico2(char **point, char *str, int i, int k)
{
  int   j;

  i = 0;
  j = 0;
  while (str[i])
    {
      while ((str[i] == '\n') && str[i] != '\0')
        i++;
      if (str[i] != '\n')
        {
          while (str[i] != '\n' && str[i] != '\0')
            {
              point[j][k] = str[i];
              i++;
              k++;
            }
        }
      point[j][k] = '\0';
      j++;
      k = 0;
    }
  point[j] = NULL;
  return (point);
}
