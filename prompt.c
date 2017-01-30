#include "autoCompletion.h"

int	first_step(char c, llist liste)
{
  element	*i = liste;

  while (i != NULL)
    {
      if (c >= 97 && c <= 122)
	c = c - 32;
      if (c == i->ville[0])
	printf("{%c%c} ", i->ville[0], i->ville[1]);
      i = i->nxt;
    }
  printf("\n");
}

char	*read_buffer()
{
  char	*buffer;
  int	size;
  
  if ((buffer = malloc(sizeof(char) * 1024)) == NULL)
    {
      printf("\nError in Malloc() for the buffer\n");
      return (0);
    }
  size = read(0, buffer, 1024);
  buffer[size -1] = '\0';
  return (buffer);
}

int	second_step(char c, char d, llist liste)
{
  element       *i = liste;
  int	j = 0;

  while (i != NULL)
    {
      if (c >= 97 && c <= 122)
	c = c - 32;
      if (c == i->ville[0] && d == i->ville[1])
	{
	  while (i->nomvoie[j] == ' ')
	    j++;
	  printf("{%s %c} ", i->ville, i->nomvoie[j]);
	  j = 0;
	}
      i = i->nxt;
    }
  printf("\n");
}

int     third_step(char c, char d,char e, llist liste)
{
  element       *i = liste;
  int   j = 0;

  while (i != NULL)
    {
      if (c >= 97 && c <= 122)
        c = c - 32;
      if (c == i->ville[0] && d == i->ville[1])
        {
          while (d != i->nomvoie[j])
            j++;
          if (d == i->nomvoie[j])
            printf("{%s %c} ", i->ville, i->nomvoie[j]);
          j = 0;
        }
      i = i->nxt;
    }
  printf("\n");
}

int	gps(char *str, llist liste)
{
  element	*i = liste;
  char	*test = malloc(sizeof(char) * 10);
  int	j;
  char	c;
  char	d;
  char	e;

  c = str[0];
  first_step(c, liste);
  str = read_buffer();
  d = str[0];
  second_step(c, d,  liste);
  str = read_buffer();
  e = str[0];
  // third_step(c, d, e, liste);
}

int	start(llist liste, llist_proba liste_proba)
{
  int	j;
  char	*buffer;
  int	size;

  if ((buffer = malloc(sizeof(char) * 1024)) == NULL)
    {
      printf("\nError in Malloc() for the buffer\n");
      return (0);
    }
  first_suggestion(liste_proba);
  //  while (42)
  //{
      size = read(0, buffer, 1024);
      buffer[size -1] = '\0';
      gps(buffer, liste);
      //      printf("%s\n", buffer);
      //j++;
      //}
}
