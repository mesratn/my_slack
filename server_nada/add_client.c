/*
** add_client.c for my_slack in /home/nada/Documents/ETNA/devc/slack/my_slack/server_nada
**
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
**
** Started on  Fri Apr 21 13:33:39 2017 MESRATI Nada
** Last update Fri Apr 21 22:16:03 2017 BILLAUD Jean
*/

#include "server.h"

void			server_read(t_env *e, int s)
{
  int			cs;
  struct sockaddr_in	client_sin;
  socklen_t		*client_sin_len;

  cs = accept(s, (struct sockaddr *)&client_sin,
	      (socklen_t *)&client_sin_len);
  if (cs == -1)
    return ;
  my_putstr("New client connected\n");
  add_elem_fd(&e->list, cs, FD_CLIENT, client_read);
  my_putstr_fd(cs, "Welcome to my slack\n");
  my_putstr_fd(cs, "List channels with /list (/l) and /join it\n");
  my_putstr_fd(cs, "to start discussing !!\n");
}

void			add_client(t_env *e)
{
  int			s;
  struct sockaddr_in	sin;
  int			pos;
  char			*name;

  pos = 1;
  if ((s = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    return ;
  sin.sin_family = AF_INET;
  sin.sin_port = htons(e->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) == -1)
    return ;
  if (listen(s, 42) == -1)
    return ;
  add_elem_fd(&e->list, s, FD_SERVER, server_read);
  my_put_nbr(e->list->type);
  if ((name = malloc(sizeof(char) * 2)) == NULL)
    return ;
  while (pos <= 9)
    {
      name[0] = pos + '0';
      name[1] = '\0';
      add_elem_chan(&e->chan, my_strdup(name));
      pos++;
    }
}

