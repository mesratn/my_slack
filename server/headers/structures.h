/*
** structures.h for my_slack in /home/naej/ETNA/my_slack/server/headers
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Wed Apr 12 21:07:53 2017 BILLAUD Jean
** Last update Wed Apr 12 21:40:18 2017 BILLAUD Jean
*/

#ifndef _SERVER_H_
#define _SERVER_H_

typedef struct	s_env
{
  t_channel	*channel;
}		t_env;

typedef struct	s_user
{
  char		*login;
  sockaddr_in	*cli_addr;
  t_user	*next;
  t_user	*prev;
}		t_user;

typedef struct 	s_channel
{
  char		*name;
  t_user	*user;
}		t_channel;
