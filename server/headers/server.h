/*
** headers.h for my_slack in /home/naej/ETNA/my_slack/server/headers
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Thu Apr 13 16:21:13 2017 BILLAUD Jean
** Last update Fri Apr 14 16:21:55 2017 BILLAUD Jean
*/

#ifndef		__SERVER_H_
#define		__SERVER_H_

/*
** Libmy
*/
void	my_putchar(char c);
void	my_putstr(char *c);
void	my_put_nbr(int n);
void	my_aff_tab(int tab[], int len);
int	my_getnbr(char *str);
int	my_isneg(int n);
void	my_strlen(char *str);
int	my_putnbr_base(int nbr, char *base);
char	*my_strcat(char *str1, char *str2);
int	my_strcmp(char *s1, char *s2);
char	*my_strcpy(char *dest, char *src);
char	*my_strdup(char *str);
char	*my_strncat(char *str1, char *str2, int n);
int     my_strncmp(char *s1, char *s2, int n);
char    *my_strncpy(char *dest, char *src, int n);
char    *my_strstr(char *str, char* to_find);
int   	count_word(char *str, char separe);
char    **my_str_to_wordtab(char *str, char separe);
void    my_swap(int *a, int *b);

/*
** Construct
*/

t_env		*create_env();
t_user		*create_user(char *login, struct sockaddr_in *cli_addr);
t_channel	*create_channel(char *cli_name);

#endif
