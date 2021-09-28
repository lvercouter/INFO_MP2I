#include<stdio.h>
#include<stdlib.h>

int main(int argc, char**argv) {
  int *numero, *note;
  // ces pointeurs se deplaceront dans les tableaux
  int *pnumero, *pnote;
  int nb = 0;
  do {
    printf("Combien d'etudiants ? ");
    scanf("%d",&nb);
    if (nb < 1)
      printf("Ce nombre doit etre strictement positif.\n");
  } while (nb < 1);
  numero = (int *)malloc(nb*sizeof(int));
  note = (int *)malloc(nb*sizeof(int));
  pnumero = numero;
  pnote = note;
  for (int i = 0; i < nb; i++) {
    printf("Numero d'etudiant : ");
    scanf("%d",pnumero);
    do {
      printf("Note : ");
      scanf("%d",pnote);
      if ((*pnote < 0) || (*pnote > 20))
        printf("Erreur. La note doit etre entre 0 et 20.\n");
    } while ((*pnote < 0) || (*pnote > 20));
    // on deplace les pointeurs a la valeur suivante
    pnumero++;
    pnote++;
  }
  // on remet les pointeurs au debut du tableau
  pnumero = numero;
  pnote = note;
  printf("Les eleves n'ayant pas eu la moyenne sont : ");
  for (int i = 0; i < nb; i++) {
    if (*pnote < 10) printf("%d ",*pnumero);
    pnumero++;
    pnote++;
  }
  printf("\n");
  free(numero);
  free(note);
}
