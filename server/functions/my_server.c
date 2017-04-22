/*
** my_server.c for my_slack in /home/nada/Documents/ETNA/devc/slack/my_slack/server_nada
**
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
**
** Started on  Fri Apr 21 13:35:57 2017 MESRATI Nada
** Last update Sat Apr 22 18:25:56 2017 BILLAUD Jean
*/

#include "../headers/server.h"

int			my_server(t_env *e)
{
  t_user		*tmp;

  FD_ZERO(&e->fd_read);
  FD_ZERO(&e->fd_write);
  e->fd_max = 0;
  tmp = e->list;
  while (tmp != NULL)
    {
      if (tmp->type != FD_FREE)
	{
	  FD_SET(tmp->fd, &e->fd_read);
	  FD_SET(tmp->fd, &e->fd_write);
	  e->fd_max = tmp->fd;
	}
      tmp = tmp->next;
    }
  if (select(e->fd_max + 1,
	     &e->fd_read, &e->fd_write, NULL, NULL) == -1)
    return (0);
  tmp = e->list;
  while (tmp != NULL)
    {
      if (FD_ISSET(tmp->fd, &e->fd_read))
	tmp->fptr_read(e, tmp->fd);
      tmp = tmp->next;
    }
  return (1);
}
