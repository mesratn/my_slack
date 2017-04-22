#include "server.h"

int		my_join(t_env *e, char **cmd, int fd)
{
  t_chan	*tmp;

  tmp = e->chan;
  if (tablen(cmd) != 2)
    {
      my_putstr_fd(fd, "/join : error arguments.\n");
      return (0);
    }
  else
    while (tmp)
      {
	if (!my_strcmp(tmp->name, cmd[1]))
	  {
	    change_chan(e->chan, cmd[1], fd);
	    if (!check_user_in_chan(tmp->first, fd))
	      {
		add_elem_fd(&tmp->user, fd, FD_CLIENT, client_read);
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
