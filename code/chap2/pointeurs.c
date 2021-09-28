#include<stdio.h>

int main(int argc, char** argv) {
  int x = 5, y = 10;
  int *p1, *p2;
  p1 = &x;
  p2 = &y;
  *p1 = 7;
  *p2 = x;
}
