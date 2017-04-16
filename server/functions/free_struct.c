/*
** free_struct.c for my_slack in /home/naej/ETNA/my_slack/server/functions
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sun Apr 16 11:11:46 2017 BILLAUD Jean
** Last update Sun Apr 16 13:00:56 2017 BILLAUD Jean
*/


void	free_user(t_user *user)
{
  free(user->name);
  free(user);
}

void	free_channel(t_channel *channel)
{
  free(channel->name);
  free(channel);
}

void	free_env(t_env	*env)
{
  free(env->name);
  free(env);
}
