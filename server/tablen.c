#include "server.h"

int	tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
