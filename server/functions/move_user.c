/*
** move_user.c for my_slack in /home/naej/ETNA/my_slack/server/functions
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sun Apr 16 11:21:09 2017 BILLAUD Jean
** Last update Sun Apr 16 13:03:15 2017 BILLAUD Jean
*/

#include 	<stdlib.h>
#include 	<stdio.h>
#include 	<unistd.h>
#include 	<netdb.h>
#include 	<sys/socket.h>
#include 	<arpa/inet.h>
#include        "../headers/structures.h"
#include        "../headers/server.h"

void		change_user_channel(t_channel *chan1, t_channel *chan2, t_user *user)
{
  remove_user_from_chan(chan1, user);
  add_user_to_chan(chan2, user);
}

void		remove_user_from_chan(t_channel *channel, t_user *user, int quit)
{
  if (channel->last = channel->prev)
    channel->first = NULL;
  else if (user->next == NULL)
    channel->last = user->prev;
  else if (user->prev == NULL)
    channel->first = user->next;
  else
    {
      user->next->prev = user->prev;
      user->prev->next = user->next;
    }
  user->next = NULL;
  user->prev = NULL;
  if (quit == 1)
    free_user(user);
}
