#include "server.h"

t_chan		*get_current_chan(t_chan *list, int fd)
{
  t_chan	*tmp;
  t_user	*user;

  tmp = list;
  while (tmp)
    {
      user = tmp->user;
      while (user)
	{
	  if (user->fd == fd && user->type == FD_CLIENT)
	    return (tmp);
	  user = user->next;
	}
      tmp = tmp->next;
    }
  return (NULL);
}

t_user		*get_current_user(t_user *list, int fd)
{
  t_user	*tmp;

  tmp = list;
  while (tmp)
    {
      if (tmp->fd == fd && tmp->type == FD_CLIENT)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}
