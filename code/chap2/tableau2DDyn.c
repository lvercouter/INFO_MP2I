#include<stdlib.h>

int main(int argc, char**argv) {
  int **notes;
  int nbEleves, nbNotes;
  printf("Combien d'eleves ? ");
  scanf("%d",&nbEleves);
  // allocation dynamique de la première dimension
  notes = (int**)malloc(nbEleves*sizeof(int *));
  // le compteur i parcourt la première dimension
  for (int i = 0; i < nbEleves; i++) {
    printf("Combien de notes pour l'eleve %d ? ",i);
    scanf("%d",&nbNotes);
    // allocation dynamique de la seconde dimension pour l'eleve i
    // on alloue nbNotes +1 pour y ajouter le nombre de notes
    notes = (int*)malloc((nbCours+1*sizeof(int));
    notes[i][0] = nbNotes;
    // le compteur j parcourt la deuxieme dimension
    for (int j = 1; j <= nbNotes; j++) {
      // Cette boucle s'assure que la note est entre 0 et 20
      // sinon elle redemande ne note
      do {
        printf("Note no%d ? ",j);
        scanf("%d",&(notes[i][j]));
        if ((notes[i][j] < 0) || (notes[i][j] > 20))
          printf("Erreur. La note doit etre entre 0 et 20.\n");
      } while ((notes[i][j] < 0) || (notes[i][j] > 20));
    }
  }
}
