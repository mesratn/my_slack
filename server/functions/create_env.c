/*
** create_env.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack/server_nada
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Fri Apr 21 21:25:51 2017 BILLAUD Jean
** Last update Sat Apr 22 23:58:43 2017 BILLAUD Jean
*/

#include "../headers/server.h"

t_env	*create_env(int p)
{
  t_env	*e;

  e = NULL;
  if((e = malloc(sizeof	(*e))) == NULL)
    return NULL;
  e->port = p;
  e->list = NULL;
  e->chan = NULL;
  return (e);
}

void	init_channel(t_env *e)
{
  add_elem_chan(&e->chan, my_strdup("general"));
  add_elem_chan(&e->chan, my_strdup("bibliotheque"));
  add_elem_chan(&e->chan, my_strdup("musique"));
}
