/*
** main.c for my_slack in /Users/nada/Documents/ETNA/TIC-DVC3/my_slack/client
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Tue Mar 28 17:18:58 2017 MESRATI Nada
** Last update Tue Apr 11 17:01:17 2017 MESRATI Nada
*/

#include	"client.h"

int		main()
{
  int		s;

  s = get_cmd();
  my_client(s);
  return (0);
}
