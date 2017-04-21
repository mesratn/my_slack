#include "server.h"

void		my_disconnect(t_env *e, int fd)
{
  t_user	*tmp;
  t_chan	*current_chan;
  t_user	*tmp_user;

  tmp = e->list;
  close(fd);
  my_putstr("Connection closed\n");
  while (tmp->fd != fd && tmp != NULL)
    tmp = tmp->next;
  if (tmp != NULL && tmp->fd == fd)
    tmp->type = FD_FREE;
  current_chan = get_current_chan(e->chan, fd);
  if (current_chan != NULL)
    {
      tmp_user = current_chan->user;
      while (tmp_user)
	{
	  if (tmp_user->fd == fd && tmp_user->type == FD_CLIENT)
	    {
	      tmp_user->type = FD_FREE;
	      tmp_user->login = NULL;
	    }
	  tmp_user = tmp_user->next;
	}
    }
}
