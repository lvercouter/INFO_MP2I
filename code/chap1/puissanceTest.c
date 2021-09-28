#include<assert.h>
#include"puissance.h"

int main(int argc, char**argv) {
  int p = puissance(3,2);
  assert(p == 9);
  p = puissance(5,0);
  assert(p == 1);
  p = puissance(-4,2);
  assert(p == 16);
  p = puissance(-4,3);
  assert(p == -64);
}
