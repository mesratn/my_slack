/*
** show_all_users.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack/server
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sat Apr 22 18:08:16 2017 BILLAUD Jean
** Last update Sat Apr 22 18:26:18 2017 BILLAUD Jean
*/

#include "../headers/server.h"

void		show_all_user(t_chan *list)
{
  t_chan	*tmp;
  t_node	*tmp_user;

  tmp = list;
  while (tmp)
    {
      my_putstr("chan ");
      my_putstr(tmp->name);
      my_putstr(" :\n");
      tmp_user = tmp->first;
      while (tmp_user)
	{
	  if (tmp_user->user->type != FD_FREE)
	    {
	      if (tmp_user->user->login)
		{
		  my_putstr("-  fd -> ");
		  my_putnbr_fd(1, tmp_user->user->fd);
		  my_putstr(" : nickname -> ");
		  my_putstr(tmp_user->user->login);
		  my_putstr(" \n\n");
		}
	      else
		{
		  my_putstr("-  fd -> ");
		  my_putnbr_fd(1, tmp_user->user->fd);
                  my_putstr(" : nickname -> unknown \n\n");
		}
	    }
	  tmp_user = tmp_user->next;
	}
      tmp = tmp->next;
    }
}
