#include<stdio.h>

int main(int argc, char**argv) {
  int n;
  printf("De quel nombre voulez-vous les multiples ? ");
  do {
    scanf("%d",&n);
    if (n < 1) printf("Le nombre doit etre strictement positif");
  } while (n <1);
  for (int i = n; i <= 100; i ++)
    if ((i % n) == 0)
      printf("%d ",i);
}
