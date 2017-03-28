/*
** bzero.c for my_slack in /Users/nada/Documents/ETNA/TIC-DVC3/my_slack/client
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Tue Mar 28 16:57:08 2017 MESRATI Nada
** Last update Tue Mar 28 17:29:22 2017 MESRATI Nada
*/
void	my_bzero(void *s1, int n)
{
  char *c;

  c = (char *)s1;
  while (n > 0)
    {
      *c++ = 0;
      n--;
    }
}
