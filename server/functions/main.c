/*
** main.c for my_slack in /home/naej/ETNA/my_slack/server/functions
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Wed Apr 12 21:23:51 2017 BILLAUD Jean
** Last update Fri Apr 14 17:12:32 2017 BILLAUD Jean
*/

#include 	<stdlib.h>
#include 	<stdio.h>
#include 	<unistd.h>
#include 	<netdb.h>
#include 	<sys/socket.h>
#include 	<arpa/inet.h>
#include        "../headers/structures.h"
#include        "../headers/server.h"

int	main()
{
  t_env	env;
  t_channel channel;
  
  env = create_env();
  channel = create_channel("pipi");
  
  my_putstr("OK");
  return (0);
}
