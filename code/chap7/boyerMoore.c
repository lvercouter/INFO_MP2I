#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dictionnaireCharInt.h"

dictionnaireCharInt * distances(char *seq) {
  dictionnaireCharInt * d = newDictionnaireCharInt();
  for (int i = 0; i < (strlen(seq)-1); i++)
    ajouterDictCI(d,seq[i],strlen(seq)-i-1);
  return d;
}

int boyerMooreHorspool(char *txt, char *seq) {
  // un dictionnaire est cree avec le dernier indice
  // de chaque caractere de la sequence
  dictionnaireCharInt *dist = distances(seq);
  // i est l'indice deplace sur txt
  // il est place au niveau du dernier caractere de seq
  int i = 0;
  while ((i+strlen(seq)) <= strlen(txt)) {
    // j est l'indice deplace sur seq
    // il est place au niveau du dernier caractere de seq
    int j = strlen(seq)-1;
    while ((j>=0)&&(txt[i+j] == seq[j])) j--;
    if (j < 0) {
      free(dist);
      return i;
    }
    // la sequence n'a pas ete trouvee
    // i est decalee
    if (estPresentDictCI(dist,txt[i+strlen(seq)-1]))
      i = i + obtenirElementDictCI(dist,txt[i+strlen(seq)-1]);
    else
      i = i + strlen(seq);
  }
  free(dist);
  return -1;
}

int main(int argc, char **argv) {
  printf("%d\n",boyerMooreHorspool("here is a simple example","example"));
  printf("%d\n",boyerMooreHorspool("here is a simple example"," simple"));
  printf("%d\n",boyerMooreHorspool("abcd","ab"));
  printf("%d\n",boyerMooreHorspool("abcd","bc"));
  printf("%d\n",boyerMooreHorspool("abcd","de"));
}
