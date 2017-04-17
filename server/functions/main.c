/*
** main.c for my_slack in /home/naej/ETNA/my_slack/server/functions
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Wed Apr 12 21:23:51 2017 BILLAUD Jean
** Last update Mon Apr 17 12:53:58 2017 BILLAUD Jean
*/

#include 	<stdlib.h>
#include 	<stdio.h>
#include	<string.h>
#include 	<unistd.h>
#include 	<netdb.h>
#include	<netinet/in.h>
#include 	<sys/socket.h>
#include 	<arpa/inet.h>
#include	<sys/select.h>
#include	<sys/types.h>
#include        "../headers/structures.h"
#include        "../headers/server.h"

int		main()
{
  int		listener;
  t_env		*env;
  t_channel 	*channel;

  listener = init_server();
  if (listener != 3)
    return (0);
  my_put_nbr(listener);
  my_serv(listener);
  env = create_env();
  channel = create_channel("pipi");
  add_channel_to_env(env, channel);
  my_putstr(env->first->name);
  my_putstr("OK");
  return (0);
}
