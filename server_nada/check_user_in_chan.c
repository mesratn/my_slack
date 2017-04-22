#include "server.h"

int		check_user_in_chan(t_node *node, int fd)
{
  t_node	*tmp;

  tmp = node;
  while (tmp)
    {
      if (tmp->user->fd == fd && tmp->user->type == FD_CLIENT
	  && tmp->user->state = CONNECTED)
	{
	  my_putstr_fd(fd, "/join : error you already exist in this chan.\n");
	  return (1);
	}
      else if (tmp->user->fd == fd)
	{
	  tmp->user->type = FD_CLIENT;
	  tmp->user->sate = CONNECTED;
	  return (1);
	}
      tmp = tmp->next;
    }
  return (0);
}
