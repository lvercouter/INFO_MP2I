#include <stdio.h>

int main(int argc, char **argv) {
  int somme = 0;
  for (int i = 1; i <= 10; i++) {
    somme = somme + i;
    printf("la somme des %d premiers entiers naturels", i);
    printf(" vaut : %d\n", somme);
  }
}
