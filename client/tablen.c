
/*
** tablen.c for my_slack in /Users/nada/Documents/ETNA/TIC-DVC3/my_slack/client
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Tue Mar 28 17:02:22 2017 MESRATI Nada
** Last update Mon Apr 24 22:06:42 2017 BILLAUD Jean
*/

/*
** Cette fonction sert à avoir la longeur d'un tableau
*/

int tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
