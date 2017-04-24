/*
** cmd_exit_func.c for  in /Volumes/SD/ETNA/slack/my_slack/server/functions
** 
** Made by DEBELLEIX Jérémy
** Login   <debell_j@etna-alternance.net>
** 
** Started on  Mon Apr 24 18:35:05 2017 DEBELLEIX Jérémy
** Last update Mon Apr 24 18:51:30 2017 DEBELLEIX Jérémy
*/

#include        "../headers/server.h"

int             my_exit(t_env *e, char **cmd, int fd)
{
  t_chan        *tmp;

  tmp = e->chan;
  if (tablen(cmd) == 1)
    {
      while (tmp)
        {
          disconnect_chan(tmp->first, tmp, fd);
          tmp = tmp->next;
        }
    }
  my_putstr_fd(fd, "disconnected.\n");
  my_disconnect(e, fd);
  return (0);
}

int             disconnect_chan(t_node *n, t_chan *c, int fd)
{
  t_node        *tmp;

  tmp = n;
  while (tmp)
    {
      if (tmp->user->fd == fd)
        {
          tmp->user->state = WAITING;
          move_node_from_chan(c, tmp);
          free_node(tmp);
          my_putstr_fd(fd, "You leave the chan ");
          my_putstr_fd(fd, c->name);
          my_putstr_fd(fd, " \n");
          return (0);
        }
      tmp = tmp->next;
    }
  return (0);
}

int             my_quit(t_env *e, char **cmd, int fd)
{
  t_chan        *tmp;

  tmp = e->chan;
  if (tablen(cmd) != 1)
    {
      my_putstr_fd(fd, "/quit : error too much arguments.\n");
      return (0);
    }
  while (tmp)
    {
      disconnect_chan(tmp->first, tmp, fd);
      tmp = tmp->next;
    }
  return (0);
}
