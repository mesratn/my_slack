
/*
** create_structure.c for my_slack in /home/naej/ETNA/my_slack/server/functions
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Wed Apr 12 21:24:35 2017 BILLAUD Jean
** Last update Thu Apr 13 16:19:48 2017 BILLAUD Jean
*/

t_env	*create_env()
{
  t_env	*env;

  env = NULL;
  env = malloc(sizeof (*env));
  if (env == NULL)
    {
      log(ERROR, "L'environnement n'a pu être créé\n");
      return (0);
    }
  env->channel = NULL;
  log(INFO, "L'environnement a bien été créé\n");
  return (env);
}

t_user		*create_user(char *login, sockaddr_in *cli_addr)
{
  t_user	*user;

  user = NULL;
  user = malloc(sizeof (*user));
  if (user == NULL)
    {
      log(ERROR, "Le user n'a pu être créé\n");
      return (0);
    }
  user->login = my_strdup(login);
  user->cli_addr = cli_addr;
  user->next = NULL;
  user->prev = NULL;
  log(INFO, "Le user a bien été créé\n");
  return (user);
}

t_channel	*create_channel(char *name)
{
  t_channel	*channel;

  channel = NULL;
  channel = malloc(sizeof (*channel));
  if (channel == NULL)
    {
      log(ERROR, "Le channel n'a pu être créé\n");
      return (0);
    }
  channel->name = my_strdup(name);
  channel->first = NULL;
  channel->last = NULL;
  log(INFO, "Le channel a bien été créé\n");
  return (channel);
}
