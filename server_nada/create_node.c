/*
** create_node.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sat Apr 22 11:34:14 2017 BILLAUD Jean
** Last update Sat Apr 22 12:18:32 2017 BILLAUD Jean
*/

#include "server.h"

t_node		*create_node(t_user *user)
{
  t_node	*node;

  if((node = malloc(sizeof(*node))) == NULL)
    return NULL;
  node->next = NULL;
  node->prev = NULL;
  node->user = user;
  return (node);
}
