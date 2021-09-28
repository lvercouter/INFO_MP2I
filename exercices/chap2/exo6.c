#include<stdio.h>

int main(int argc, char**argv) {
  int p, u, rang, precedent, tmp;
  printf("Entrez la borne souhaitee ? ");
  do {
    scanf("%d",&p);
    if (p < 1)
      printf("La borne doit etre strictement positive");
  } while (p <1);
  // u et rang correspondent au premier terme de la suite
  u = 1;
  rang = 1;
  // precedent represente la valeur du terme precedent celui
  // en cours de traitement
  precedent = 1;
  // on sort de la boucle des qu'un terme depassant la borne est trouve
  while (u < p) {
    tmp = u;
    u = u + precedent;
    precedent = tmp;
    rang = rang + 1;
  }
  printf("Le premier terme de la suite de Fibonacci a ");
  printf("depasser %d est %d de rang %d\n",p,u,rang);
}
