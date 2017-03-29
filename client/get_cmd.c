/*
** get_cmd.c for my_slack in /Users/nada/Documents/ETNA/TIC-DVC3/my_slack/client
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Tue Mar 28 17:19:35 2017 MESRATI Nada
** Last update Wed Mar 29 16:23:58 2017 MESRATI Nada
*/
#include "client.h"

/** 
 ** Cette fonction sert à se connecter au serveur avec la commande /server [address]:[port]
 **/
int			get_cmd()
{
  char			buff[BUFF_SIZE];
  char			**tmp;
  char			**tmp2;
  int			i;
  int			r;

  r = 1;
  while (r)
    {
      i = read(0, buff, BUFF_SIZE);
      if (i > 0)
	{
	  buff[i] = '\0';
	  tmp = my_str_to_wordtab(buff, ' ');
	  if (tablen(tmp) == 2 && my_strcmp(tmp[0], "/server") == 0)
	    {
	      tmp2 = my_str_to_wordtab(tmp[1], ':');
	      if ((i = my_connect(tmp2)) != -1)
		return (i);
	    }
	  else
	    my_putstr("Usage: /server [address]:[port]\n");
	}
      else
	r = 0;
    }
  return (0);
}
