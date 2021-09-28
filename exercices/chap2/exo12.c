#include<stdio.h>
#include<stdlib.h>

int main(int argc, char**argv) {
  int *numero, *note; // les numeros et notes d'etudiants
  int nb = 0; // nb sera le nombre d'etudiants
  do {
    printf("Combien d'etudiants ? ");
    scanf("%d",&nb);
    if (nb < 1)
      printf("Ce nombre doit etre strictement positif.\n");
  } while (nb < 1);
  numero = (int *)malloc(nb*sizeof(int));
  note = (int *)malloc(nb*sizeof(int));
  for (int i = 0; i < nb; i++) {
    printf("Numero d'etudiant : ");
    scanf("%d",&(numero[i]));
    // Cette boucle s'assure que la note est entre 0 et 20
    // sinon elle redemande une note
    do {
      printf("Note : ");
      scanf("%d",&(note[i]));
      if ((note[i] < 0) || (note[i] > 20))
        printf("Erreur. La note doit etre entre 0 et 20.\n");
    } while ((note[i] < 0) || (note[i] > 20));
  }
  printf("Les eleves n'ayant pas eu la moyenne sont : ");
  for (int i = 0; i < nb; i++)
    if (note[i] < 10) printf("%d ",numero[i]);
  printf("\n");
  free(numero);
  free(note);
}
