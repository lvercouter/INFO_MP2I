#include <stdio.h>
#include <math.h>
//math.h est necessaire pour acceder aux fonctions sqrt et pow

struct point {
  float x,y;
};

struct segment {
  struct point ext1, ext2;
};

int main(int argc, char **argv) {
  struct segment seg;
  float longueur;
  printf("Extremite 1, X = ");
  scanf("%f",&seg.ext1.x);
  printf("Extremite 1, Y = ");
  scanf("%f",&seg.ext1.y);
  printf("Extremite 2, X = ");
  scanf("%f",&seg.ext2.x);
  printf("Extremite 2, Y = ");
  scanf("%f",&seg.ext2.y);
  longueur = sqrt(pow(seg.ext1.x-seg.ext2.x,2)+
    pow(seg.ext1.y-seg.ext2.y,2));
  printf("La longueur du segment est %f\n",longueur);
}
