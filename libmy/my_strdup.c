/*
** my_strdup.c for my_strdup in /home/mesrat_n/piscine/C/Jour07/my_strdup
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Tue Oct  7 08:31:37 2014 MESRATI Nada
** Last update Thu Oct  9 18:48:17 2014 MESRATI Nada
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	*my_strcpy(char *dest, char *src);

char	*my_strdup(char *str)
{
  int	i;
  char	*dest;

  i = 0;
  while (str[i] != '\0')
    i++;
  dest = malloc(i * (sizeof(*str)));
  if(dest == NULL)
    return 0;
  dest = my_strcpy(dest, str);
  return (dest);
}
