#include "server.h"

int		check_fd(t_user **list, int fd)
{
  t_user	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->fd == fd)
	{
	  tmp->type = FD_CLIENT;
	  return (1);
	}
      tmp = tmp->next;
    }
  return (0);
}

void		add_elem_fd(t_user **list, int fd, int type, vfptr fptr_read)
{
  t_user	*new;
  t_user	*tmp;

  if (check_fd(list, fd))
    return ;
  if ((new = malloc(sizeof(*new))) == NULL)
    return ;
  new->login = NULL;
  new->fd = fd;
  new->type = type;
  new->state = WAITING;
  new->fptr_read = fptr_read;
  new->login = NULL;
  new->next = NULL;
  if (*list == NULL)
      *list = new;
  else
    {
      tmp = *list;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
    }
}

void		add_elem_chan(t_chan **list, char *name)
{
  t_chan	*new;
  t_chan	*tmp;

  if ((new = malloc(sizeof(*new))) == NULL)
    return ;
  if (name == NULL)
    return ;
  new->name = name;
  new->next = NULL;
  new->user = NULL;
  if (*list == NULL)
    *list = new;
  else
    {
      tmp = *list;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
    }
}

void		add_user_to_chans(t_chan **chan, t_user	*user)
{
  t_node	*node;
  
}
