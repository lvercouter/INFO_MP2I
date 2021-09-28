#include<stdio.h>

const int MAX = 50;

int main(int argc, char**argv) {
  int numero[MAX], note[MAX]; // les numeros et notes d'etudiants
  int i = 0, nb = 0; // nb sera le nombre d'etudiants
  do {
    printf("Numero d'etudiant : ");
    scanf("%d",&(numero[i]));
    // si la saisie n'est pas strictement positive il faut quitter
    // la boucle sans demander de note
    if (numero[i] > 0) {
      // Cette boucle s'assure que la note est entre 0 et 20
      // sinon elle redemande ne note
      do {
        printf("Note : ");
        scanf("%d",&(note[i]));
        if ((note[i] < 0) || (note[i] > 20))
          printf("Erreur. La note doit etre entre 0 et 20.\n");
      } while ((note[i] < 0) || (note[i] > 20));
      nb = nb + 1;
    }
    // on avance le compteur pour le prochain etudiant si la condition
    // ci-dessous est vrai, cad que la derniere saisie est strictement
    //positive et qu'on n'a pas completement rempli le tableau
    i = i + 1;
  } while ((numero[i-1] > 0) && (i < MAX));
  printf("Les eleves n'ayant pas eu la moyenne sont : ");
  for (i = 0; i < nb; i++)
    if (note[i] < 10) printf("%d ",numero[i]);
  printf("\n");
}
