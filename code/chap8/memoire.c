#include <stdio.h>
#include <stdlib.h>

int n;

int f(int x) {
  int y = x*2;
  return y;
}

int main(int argc, char **argv) {
  int *t;
  scanf("%d",&n);
  t = (int *)malloc(n*sizeof(int));
  t[0] = 1;
  for (int i = 1; i < n; i++)
    t[i] = f(t[i-1]);
  for (int i = 0; i < n; i++)
    printf("%d ",t[i]);
  printf("\n");
  free(t);
  return EXIT_SUCCESS;
}
