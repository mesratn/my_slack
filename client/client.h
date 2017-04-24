#ifndef		__CLIENT_H_
# define	__CLIENT_H_

#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

# define BUFF_SIZE	3000

void	freetab(char **tab);
int	tablen(char **tab);
void	my_bzero(void *s1, int n);
int	my_connect(char **cmd);
int	get_cmd();
int     my_getnbr(char *str);
void	my_putstr(char *str);
char    **my_str_to_wordtab(char *str, char separe);
int	my_strcmp(char *s1, char *s2);
int	my_client(int s);
int	connect_serv(char **cmd);

#endif
