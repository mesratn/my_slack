/*
** add_struct.c for my_slack in /home/naej/ETNA/my_slack/server/functions
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Thu Apr 13 16:34:07 2017 BILLAUD Jean
** Last update Fri Apr 14 17:25:45 2017 BILLAUD Jean
*/

#include 	<stdlib.h>
#include 	<stdio.h>
#include 	<unistd.h>
#include 	<netdb.h>
#include 	<sys/socket.h>
#include 	<arpa/inet.h>
#include        "../headers/structures.h"
#include        "../headers/server.h"

void	add_channel_to_env(t_env *env, t_channel *chan)
{
  if (env->first == NULL)
    {
      env->first = chan;
      env->last = chan;
    }
  else
    {
      env->last->next = chan;
      chan->prev = env->first;
      env->last = chan;
    }
}
