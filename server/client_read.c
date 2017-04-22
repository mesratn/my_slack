#include "server.h"

void		client_read(t_env *e, int fd)
{
  int		r;
  char		buf[BUFF_SIZE];

  r = read(fd, buf, BUFF_SIZE);
  if (r > 0)
    {
      buf[r - 1] = '\0';
      if (!get_cmd(e, buf, fd))
	send_msg_in_chan(e, fd, buf);
    }
  else
    my_disconnect(e, fd);
}
