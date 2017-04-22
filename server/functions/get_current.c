/*
** get_current.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack/server
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sat Apr 22 18:06:45 2017 BILLAUD Jean
** Last update Sat Apr 22 19:07:25 2017 BILLAUD Jean
*/

#include 	"../headers/server.h"

t_chan		*get_current_chan(t_chan *list, int fd)
{
  t_chan	*tmp;
  t_node	*node;

  tmp = list;
  while (tmp)
    {
      node = tmp->first;
      while (node)
	{
	  if (node->user->fd == fd && node->user->type == FD_CLIENT)
	    return (tmp);
	  node = node->next;
	}
      tmp = tmp->next;
    }
  return (NULL);
}

t_user		*get_current_user(t_user *list, int fd)
{
  t_user	*tmp;

  tmp = list;
  while (tmp)
    {
      if (tmp->fd == fd && tmp->type == FD_CLIENT)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

t_node		*get_user_node(t_chan *list, int fd)
{
  t_chan	*tmp;
  t_node	*node;
  
  tmp = list;
  while (tmp)
  {
    node = tmp->first;
    while (node)
      {
	if (node->user->fd == fd)
	  return (node);
	node = node->next;
      }
    tmp = tmp->next;
  }
  return (NULL);
}

t_user		*get_current_user_in_chan(t_chan *c, int fd)
{
  t_node	*node;
  
  node = c->first;
  while (node)
    {
      if (node->user->fd == fd)
	return (node->user);
      node = node->next;
    }
  return (NULL);
}
