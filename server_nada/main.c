/*
** main.c for my_slack in /home/nada/Documents/ETNA/devc/slack/my_slack/server_nada
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Fri Apr 21 13:29:26 2017 MESRATI Nada
** Last update Fri Apr 21 13:33:22 2017 MESRATI Nada
*/

#include "server.h"

int	main(int argc, char **argv)
{
  t_env	e;
  if (argc != 2 || my_getnbr(argv[1]) < 1025)
    {
      my_putstr("Usage : ./server_bin [port > 1025]\n\n");
      return (0);
    }
  e.port = my_getnbr(argv[1]);
  e.list = NULL;
  e.chan = NULL;
  add_client(&e);
  while (my_server(&e));
  return (0);
}
