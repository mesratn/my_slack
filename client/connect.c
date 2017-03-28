/*
** connect.c for my_slack in /Users/nada/Documents/ETNA/TIC-DVC3/my_slack/client
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Tue Mar 28 17:19:19 2017 MESRATI Nada
** Last update Tue Mar 28 17:19:20 2017 MESRATI Nada
*/

#include		"client.h"

int			my_connect(char **cmd)
{
  struct protoent	*pe;
  struct sockaddr_in	sin;
  int			s;
  int			port;

  if (cmd[1] != NULL)
    port = my_getnbr(cmd[1]);
  pe = getprotobyname("TCP");
  if (pe == NULL)
    return (-1);
  s = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (s == -1)
    return (-1);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = inet_addr(cmd[0]);
  if (connect(s, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
    {
      my_putstr("Error connect()\n");
      return (-1);
    }
  freetab(cmd);
  return (s);
}