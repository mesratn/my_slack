#include "server.h"

void	writing(int fd, char *login, char *buf)
{
  my_putstr_fd(fd, login);
  my_putstr_fd(fd, ": ");
  my_putstr_fd(fd, buf);
  my_putstr_fd(fd, "\n");
}

void		send_msg_in_chan(t_env *e, int fd, char * buf)
{
  t_user	*user;
  t_chan	*current_chan;
  t_user	*current_user;

  current_chan = get_current_chan(e->chan, fd);
  user = (current_chan == NULL) ? NULL : current_chan->user;
  current_user = (!user) ? NULL : get_current_user(user, fd);
  if (!current_chan)
    my_putstr_fd(fd, "send msg: error join a chan before.\n");
  while (user)
    {
      if (FD_ISSET(user->fd, &e->fd_write) && fd != user->fd &&
	  user->type == FD_CLIENT)
	{
	  if (current_user != NULL && current_user->login)
	    writing(user->fd, current_user->login, buf);
	  else if (current_user != NULL)
	    writing(user->fd, "unknown", buf);
	}
      user = user->next;
    }
}
