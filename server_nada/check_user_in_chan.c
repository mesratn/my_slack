#include "server.h"

int		check_user_in_chan(t_user *user, int fd)
{
  t_user	*tmp;

  tmp = user;
  while (tmp)
    {
      if (tmp->fd == fd && tmp->type == FD_CLIENT)
	{
	  my_putstr_fd(fd, "/join : error you already exist in this chan.\n");
	  return (1);
	}
      else if (tmp->fd == fd)
	{
	  tmp->type = FD_CLIENT;
	  return (1);
	}
      tmp = tmp->next;
    }
  return (0);
}
