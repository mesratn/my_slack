/*
** create_env.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack/server_nada
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Fri Apr 21 21:25:51 2017 BILLAUD Jean
** Last update Fri Apr 21 21:35:09 2017 BILLAUD Jean
*/

#include "server.h"

t_env	*create_env(int p)
{
  t_env	*e;

  e = NULL;
  if((e = malloc(sizeof(*e))) == NULL)
    return NULL;
  e->port = p;
  e->list = NULL;
  e->chan = NULL;
  return (e);
}
