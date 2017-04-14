/*
** structures.h for my_slack in /home/naej/ETNA/my_slack/server/headers
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Wed Apr 12 21:07:53 2017 BILLAUD Jean
** Last update Fri Apr 14 08:59:25 2017 BILLAUD Jean
*/

#ifndef __SERVER_H_
#define __SERVER_H_

typedef struct		s_user
{
  char			*login;
  struct sockaddr_in	*cli_addr;
}			t_user;

typedef struct 		s_channel
{
  char			*name;
  t_user		*first;
  t_user		*last;
}			t_channel;

typedef struct		s_env
{
  t_channel		*first;
  t_channel		*last;
}			t_env;

#endif
