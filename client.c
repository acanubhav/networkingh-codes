#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
int
main (int argc, char *argv[])
{
  int cfd;
  struct sockaddr_in addr;	//structure to give socket addresses to both the sides of socket
  char ch[20];
  printf ("Enter the string");
  scanf ("%s", ch);
  cfd = socket (AF_INET, SOCK_STREAM, 0);	//domain type and protocol,creaqte an enddpoint for communication
  addr.sin_family = AF_INET;	//address of protocol family
  addr.sin_addr.s_addr = inet_addr ("127.0.0.1");	/* Check for server on loopback */
  addr.sin_port = htons (29008);	//er hostshort from host  byte  order  to  network byte order.

  if (connect (cfd, (struct sockaddr *) &addr, sizeof (addr)) < 0)
    {
      perror ("connect error");
      return -1;
    }
  if (write (cfd, &ch, 1) < 0)
    perror ("write");
  if (read (cfd, &ch, 1) < 0)
    perror ("read");
  printf ("nReply from Server: %snn", ch);
  close (cfd);
  return 0;
}
