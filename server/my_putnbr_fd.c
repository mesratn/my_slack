#include "server.h"

void	my_putchar_fd(int fd, char c)
{
  write(fd, &c, 1);
}

void	my_putnbr_fd(int fd, int n)
{
  int	mod;

  if (n < 0)
    {
      if (n == -2147483648)
	my_putstr_fd(fd, "-2147483648");
      else
	{
	  my_putstr_fd(fd, "-");
	  n *= -1;
	}
    }
  if (n >= 0)
    {
      if (n >= 10)
	{
	  mod = n % 10;
	  n = (n - mod) / 10;
	  my_putnbr_fd(fd, n);
	  my_putchar_fd(fd, mod + '0');
	}
      else
	my_putchar_fd(fd, n + '0');
    }
}
