/*
** my_join.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack/server_nada
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sat Apr 22 10:35:56 2017 BILLAUD Jean
** Last update Sat Apr 22 12:28:06 2017 BILLAUD Jean
*/

#include "server.h"

int		my_join(t_env *e, char **cmd, int fd)
{
  t_chan	*tmp;
  t_user	*u;

  u = get_current_user(e->list, fd);
  tmp = e->chan;
  if (tablen(cmd) != 2)
    {
      my_putstr_fd(fd, "/join : error arguments.\n");
      return (0);
    }
  else
    {
      while (tmp)
	{
	  if (!my_strcmp(tmp->name, cmd[1]))
	    {
	      if (u->state == WAITING)
		{
		  add_user_to_chan(tmp, u);
		  return (1);
		}
	      else if (u->state == CONNECTED)
		{
		  move_user_to_chan(e->chan, tmp, cmd[1], u);
		  return (1);
		}
	      else
		return (0);
	    }
	  tmp = tmp->next;
	}
      my_putstr_fd(fd, "/join : error chan doesn't exist.\n");
      return (0);
    }
}
