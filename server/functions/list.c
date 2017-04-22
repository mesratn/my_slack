/*
** list.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack/server
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sat Apr 22 18:06:53 2017 BILLAUD Jean
** Last update Sat Apr 22 19:07:25 2017 BILLAUD Jean
*/

#include 	"../headers/server.h"

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
