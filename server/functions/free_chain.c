/*
** free_chain.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sat Apr 22 20:18:58 2017 BILLAUD Jean
** Last update Sun Apr 23 15:13:12 2017 BILLAUD Jean
*/

#include "../headers/server.h"

void		free_all_users(t_env *e)
{
  t_user	*u;

  u = e->list;
  while (u)
    {
      e->list = u->next;
      free_user(u);
      u = e->list;
    }
}

void		free_all_chan(t_env *e)
{
  t_chan	*c;
  
  c = e->chan;
  while (c)
    {
      free_all_node(c);
      e->chan = c->next;
      free_chan(c);
      c = e->chan;
    }
}

void		free_all_node(t_chan *c)
{
  t_node	*n;

  n = c->first;
  while (n)
    {
      c->first = n->next;
      free_node(n);
      n = c->first;
    }
}
