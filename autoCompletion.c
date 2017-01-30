#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "autoCompletion.h"

char	**read_file(char *file)
{
  int	fileread;
  int	in;
  char	buffer[10000];
  char	**stock;
  
  in = open(file, O_RDONLY);
  if (in == - 1)
    {
      printf("Argument invalide\n");
      exit(EXIT_FAILURE);
    }
  fileread = read(in, buffer, sizeof(buffer));
  stock = save_dico(buffer);

  return (stock);
}

char	**separate(char *stock)
{
  char	**cut;

  cut = cut_addr(stock);
  return (cut);
}

llist	add(llist liste, char **str)
{
  element* new = malloc(sizeof(element));
  char	**typevoie;
  char	*ville;
  char	*num;
  char	*type;
  char	*nom;

  typevoie = init_type();
  ville = add_ville(str);
  num = add_numvoie(str);
  type = add_type(str);
  nom = add_nom(str, typevoie);
  new->ville = ville;
  new->num = num;
  new->type = type;
  new->nomvoie = nom;
  new->nxt = liste;
  return (new);
}

int	main(int ac, char **av)
{
  llist	liste = NULL;
  llist_proba	liste_proba = NULL;
  char	**stock;
  char	**cut;
  int	i = 0;

  stock = read_file(av[1]);
  while (stock[i] != NULL)
    {
      cut = separate(stock[i]);
      liste = add(liste, cut);
      i++;
    }
  liste_proba = run(liste, liste_proba);
  start(liste, liste_proba);
  //first_suggestion(liste_proba);
  //  view2(liste_proba);
  //view(liste);
}
