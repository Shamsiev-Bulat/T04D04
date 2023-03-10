#include <math.h>
#include <stdio.h>
static int
is_hex (int c)
{
  if (c >= '0' && c <= '9') 
    return (c - '0') | 0x80;
  
  c |= 0x20; 
  return (c >= 'a' && c <= 'f') ?  ((c - 'a') + 10) | 0x80 : 0;
}

static int
n_a (int c)
{
  puts("n/a");
  return c;
}

int
hextochar ()
{
  int c1, c2, xd1, xd2;
  int nc = 0;
  
  while ((c1 = getchar()) != EOF) {
    nc++;
    if (c1 == '\n')
      return n_a(c1); 
    if ((c2 = getchar()) == EOF || c2 == '\n')
      return n_a(c2); 
    if (!(xd1 = is_hex(c1)) || !(xd2 = is_hex(c2)))
      return n_a(1); 
    xd1 &= 0xf;
    xd2 &= 0xf;
    printf("%c", (xd1 << 4) | xd2);
    c1 = getchar();
    if (c1 == ' ' || c1 == '\n') { 
      printf("%c", c1);
      if (c1 == '\n')
        return 0; 
    } else
      return n_a(c1 | 0x1); 
  }

  if (nc)
    puts("n/a");
  return EOF;
}

int
skipline (FILE *in)
{
  int c;

  while ((c = fgetc(in)) != EOF)
    if (c == '\n')
      break;

  return c;
}

int
main (int ac, char *av[])
{
  if (ac != 2)
  Errexit:
    return((printf("Usage: %s 1 | 0\n", av[0]), 1));

  int c = av[1][0];
  if (av[1][1] || !(c == '1' || c == '0'))
    goto Errexit;

  if (c == '1') {
    while ((c = hextochar()) != EOF)
      if (c && c != '\n') 
        if (skipline(stdin) == EOF)
          break;
  } else {
    puts("Not implemented yet");
  }
  
  return puts("End") == EOF;
}