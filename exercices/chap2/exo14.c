#include<stdio.h>
#include<stdlib.h>

int **genererTrianglePascal(int taille) {
  int **triangle = (int **)malloc(taille*sizeof(int *));
  for (int i = 0; i < taille; i++) {
    triangle[i] = (int *)malloc((i+1)*sizeof(int));
    triangle[i][0] = 1;
    for (int j = 1; j < i; j++)
      triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
    triangle[i][i] = 1;
  }
  return triangle;
}

void libererMemoire(int ** t, int taille) {
  for (int i = 0; i < taille; i++)
    free (t[i]);
  free(t);
}

void affichage(int ** triangle, int taille) {
  for (int i = 0; i < taille; i++) {
    for (int j = 0; j <= i; j++)
      printf("%d ",triangle[i][j]);
    printf("\n");
  }
}

int main(int argc, char**argv) {
  int taille;
  int **triangle;
  printf("Combien de lignes du triangle de Pascal ?");
  scanf("%d",&taille);
  triangle = genererTrianglePascal(taille);
  affichage(triangle,taille);
  libererMemoire(triangle,taille);
}
