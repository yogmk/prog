 #include <stdio.h>

struct bitfield_s
{
  unsigned int b0:1;
  unsigned int b1:1;
  unsigned int b2:1;
  unsigned int b3:1;

  unsigned int b4:1;
  unsigned int b5:1;
  unsigned int b6:1;
  unsigned int b7:1;

};

union bitfield_e
{
  unsigned char c;
  struct bitfield_s s;

};

int main ()
{
  union bitfield_e b;
  unsigned char c = 0x12;
  int i;

  b.c = c;
  printf ("%d%d%d%d%d%d%d%d\n", b.s.b7, b.s.b6, b.s.b5, b.s.b4,
    b.s.b3, b.s.b2, b.s.b1, b.s.b0);

  return 0;
}

