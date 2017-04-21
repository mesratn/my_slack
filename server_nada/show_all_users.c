#include "server.h"

void		show_all_user(t_chan *list)
{
  t_chan	*tmp;
  t_user	*tmp_user;

  tmp = list;
  while (tmp)
    {
      my_putstr("chan ");
      my_putstr(tmp->name);
      my_putstr(" :\n");
      tmp_user = tmp->user;
      while (tmp_user)
	{
	  if (tmp_user->type != FD_FREE)
	    {
	      if (tmp_user->login)
		{
		  my_putstr("-  fd -> ");
		  my_putnbr_fd(1, tmp_user->fd);
		  my_putstr(" : nickname -> ");
		  my_putstr(tmp_user->login);
		  my_putstr(" \n\n");
		}
	      else
		{
		  my_putstr("-  fd -> ");
		  my_putnbr_fd(1, tmp_user->fd);
                  my_putstr(" : nickname -> unknown \n\n");
		}
	    }
	  tmp_user = tmp_user->next;
	}
      tmp = tmp->next;
    }
}
