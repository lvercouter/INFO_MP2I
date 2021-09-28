#include <stdio.h>

int main(int argc, char **argv) {
  int n, i;
  printf("Entrez un nombre entier : ");
  scanf("%d",&n);
  for (i = n/2; (i > 1) && (n%i != 0) ; i--);
  printf("Son plus grand diviseur est %d\n",i);
}
