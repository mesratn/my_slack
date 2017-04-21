#include "server.h"

void		change_chan(t_chan *list, char *name_chan, int fd)
{
  t_chan	*tmp;
  t_user	*user;

  tmp = list;
  while (tmp)
    {
      if (my_strcmp(tmp->name, name_chan))
	{
	  user = tmp->user;
	  while (user)
	    {
	      if (user->fd == fd && user->type == FD_CLIENT)
		user->type = FD_FREE;
	      user = user->next;
	    }
	}
      tmp = tmp->next;
    }
}
