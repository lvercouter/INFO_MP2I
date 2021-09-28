#include <stdio.h>

int diviseurImpair(int a) {
  while ((a % 2) == 0)
    a = a / 2;
  return a;
}

int main(int argc, char**argv) {
  printf("pour 4, ca donne %d\n",diviseurImpair(4));
  printf("pour 7, ca donne %d\n",diviseurImpair(7));
  printf("pour 28, ca donne %d\n",diviseurImpair(28));
  printf("pour 86, ca donne %d\n",diviseurImpair(86));
  printf("pour 50, ca donne %d\n",diviseurImpair(50));
}
