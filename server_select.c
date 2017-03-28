/*
** server_select.c for my_slack in /Users/nada/Documents/ETNA/TIC-DVC3
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Tue Mar 28 16:45:51 2017 MESRATI Nada
** Last update Tue Mar 28 16:45:53 2017 MESRATI Nada
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 4242
#define BACKLOG 512

int			main()
{
  int			listener;
  struct sockaddr_in	srv_addr;
  struct sockaddr_in	cli_addr;
  struct protoent	*proto;
  socklen_t		socklen;
  int			client1;
  int			client2;
  char			buffer[20];
  int			nread;
  fd_set		readfs;

  if ((proto = getprotobyname("TCP")) == NULL)
    return (EXIT_FAILURE);
  socklen = sizeof(cli_addr);
  if ((listener = socket(AF_INET, SOCK_STREAM, proto->p_proto)) == -1)
    {
      perror(__FUNCTION__);
      return (EXIT_FAILURE);
    }
  srv_addr.sin_family = AF_INET;
  srv_addr.sin_addr.s_addr = INADDR_ANY;
  srv_addr.sin_port = htons(PORT);
  if ((bind(listener, (const struct sockaddr*)&srv_addr, sizeof(srv_addr))) == -1)
    {
      perror(__FUNCTION__);
      return (EXIT_FAILURE);
    }
  if ((listen(listener, BACKLOG)) == -1)
    {
      perror(__FUNCTION__);
      return (EXIT_FAILURE);
    }
  client1 = accept(listener, (struct sockaddr *)&cli_addr, &socklen);
  client2 = accept(listener, (struct sockaddr *)&cli_addr, &socklen);
  if (client1 == -1 || client2 == -1)
    return (EXIT_FAILURE);
  write(client1, "Hello client1\n", strlen("Hello client1\n"));
  write(client2, "Hello client2\n", strlen("Hello client2\n"));
  while (42)
    {
      FD_ZERO(&readfs);
      FD_SET(client1, &readfs);
      FD_SET(client2, &readfs);
      FD_SET(0, &readfs);
      select(6, &readfs, NULL, NULL, NULL);
      if (FD_ISSET(client1, &readfs))
	{
	  printf("client1\n");
	  memset(buffer, 0, 20);
	  nread = read(client1, buffer, 20);
	  buffer[nread] = '\0';
	  write(client2, buffer, strlen(buffer));
	  FD_CLR(client1, &readfs);
	}
      if (FD_ISSET(client2, &readfs))
	{
	  printf("client2\n");
	  memset(buffer, 0, 20);
	  nread = read(client2, buffer, 20);
	  buffer[nread] = '\0';
	  write(client1, buffer, strlen(buffer));
	  FD_CLR(client2, &readfs);
	}
      if (FD_ISSET(0, &readfs))
	{
	  close(client1);
	  close(client2);
	  return (EXIT_SUCCESS);
	}
    }
  return (0);
}
