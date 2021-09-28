#include<stdio.h>

void swap (int *x, int *y) {
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

int main(int argc, char**argv) {
  int a = 4, b = 2;
  // ici a = 4 et b = 2
  swap(&a,&b);
  // ici a = 2 et b = 4
}
