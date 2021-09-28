# include<stdio.h>
# include<stdlib.h>

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

void fichierPascal(char *nom, int taille) {
  int **triangle = genererTrianglePascal(taille);
  FILE * f = fopen(nom,"w");
  if (f == NULL) {
    fprintf(stderr,"Erreur dans l'ouverture de %s\n",nom);
  } else {
    for (int i = 0; i < taille; i++) {
      for (int j = 0; j <= i; j++)
        fprintf(f,"%d ",triangle[i][j]);
      fprintf(f,"\n");
    }
  }
  fclose(f);
}

int main(int argc,char**argv) {
  fichierPascal("pascal.txt",5);
}
