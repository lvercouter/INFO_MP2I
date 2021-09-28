#include <stdio.h>

int puissance(int a, int n) {
  int resultat = a;
  for (int i = 2; i <= n; i++)
    resultat = resultat * a;
  return resultat;
}

int main(int argc, char **argv) {
  int nombre, exposant, puiss;
  printf("Saisissez un nombre entier : ");
  scanf("%d",&nombre);
  printf("Saisissez son exposant : ");
  scanf("%d",&exposant);
  // appel de la fonction puissance
  puiss = puissance(nombre,exposant);
  printf("%d ^ %d = %d\n",nombre,exposant,puiss);
}
