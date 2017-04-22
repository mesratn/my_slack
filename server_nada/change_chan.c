#include "server.h"

void		change_chan(t_chan *list, char *name_chan, int fd)
{
  t_chan	*tmp;
  t_node	*node;

  tmp = list;
  while (tmp)
    {
      if (my_strcmp(tmp->name, name_chan))
	{
	  node = tmp->first;
	  while (node)
	    {
	      if (node->user->fd == fd && node->user->type == FD_CLIENT)
		move_node_from_chan(node)
	      node = node->next;
	    }
	}
      tmp = tmp->next;
    }
}
