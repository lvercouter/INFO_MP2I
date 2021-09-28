#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int x,y;
} point;

typedef struct {
  int nbPoints;
  point *points;
} figure;

figure * nouvelleFigure(int nbPts) {
  figure *f = (figure *)malloc(sizeof(figure));
  f->nbPoints = nbPts;
  f->points = (point *)malloc(nbPts*sizeof(point));
  return f;
}

void libererFigure(figure *f) {
  free(f->points);
  free(f);
}

typedef struct {
  int nbFigures;
  figure **figures;
} dessin;

dessin * nouveauDessin(int nbFigs,int *nbPts) {
  dessin *d = (dessin *)malloc(sizeof(dessin));
  d->nbFigures = nbFigs;
  d->figures = (figure **)malloc(nbFigs*sizeof(figure *));
  for (int i = 0; i < nbFigs; i++)
    d->figures[i] = nouvelleFigure(nbPts[i]);
  return d;
}

void libererDessin(dessin *d) {
  for (int i = 0; i < d->nbFigures; i++)
    libererFigure(d->figures[i]);
  free(d->figures);
  free(d);
}

int main(int argc, char** argv) {
  int pts[3] = {3,4,5};
  dessin * d = nouveauDessin(3,pts);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < pts[i]; j++) {
      printf("%d %d\n",i,j);
      d->figures[i]->points[j].x = i;
      d->figures[i]->points[j].y = j;
    }
  }
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < pts[i]; j++)
      printf("x = %d y = %d\n",d->figures[i]->points[j].x,d->figures[i]->points[j].y);
  libererDessin(d);
}
