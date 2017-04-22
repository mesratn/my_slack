#include "server.h"

void		show_list(t_user *list, int fd)
{
  t_user	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putstr_fd(fd, "fd -> ");
      my_putnbr_fd(fd, tmp->fd);
      my_putstr_fd(fd, "\n");
      tmp = tmp->next;
    }
}

void		show_list_chan(t_chan *list, int fd)
{
  t_chan	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putstr_fd(fd, tmp->name);
      my_putstr_fd(fd, "\n");
      tmp = tmp->next;
    }
}
