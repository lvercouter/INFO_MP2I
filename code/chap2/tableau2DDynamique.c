#include<stdlib.h>

int main(int argc, char**argv) {
  int **matrice;
  matrice = (int**)malloc(3*sizeof(int *));
  for (int i = 0; i < 3; i++)
    matrice[i] = (int*)malloc(5*sizeof(int));
}
