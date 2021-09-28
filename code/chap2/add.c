#include<stdio.h>
#include<stdlib.h>

int main(int argc, char**argv) {
  int somme = 0;
  for (int i = 1; i < argc; i++)
    somme += atoi(argv[i]);
  printf("%d\n",somme);
}
