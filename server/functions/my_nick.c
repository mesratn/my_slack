/*
** my_nick.c for  in /Volumes/SD/ETNA/slack/my_slack/server/functions
** 
** Made by DEBELLEIX Jérémy
** Login   <debell_j@etna-alternance.net>
** 
** Started on  Mon Apr 24 18:48:28 2017 DEBELLEIX Jérémy
** Last update Mon Apr 24 18:49:23 2017 DEBELLEIX Jérémy
*/

#include        "../headers/server.h"

int   my_nick(t_env *e, char **cmd, int fd)
{
  t_user  *user;

  user = get_current_user(e->list, fd);
  if (cmd[2])
      my_putstr_fd(fd, "/nick : error, too much arguments.\n");
  else if (cmd[1])
      user->login = my_strdup(cmd[1]);
  else
    my_putstr_fd(fd, "/nick : error, argument missed.\n");
  return (0);
}
