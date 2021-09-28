#include <stdlib.h>
#include "fileInt.h"

// constructeur qui cree un nouvel espace pour la file
fileInt* newFileInt() {
  fileInt * f = (fileInt *)malloc(sizeof(fileInt));
  f->tete = NULL;
  f->queue = NULL;
  return f;
}

fileInt* enfiler(fileInt *f, int val) {
  //un nouvel element est cree
  element *e = (element *)malloc(sizeof(element));
  e->valeur = val;
  // et devient la tete de la file
  e->precedent = NULL;
  e->suivant = f->tete;
  // si la liste etait vide, il devient aussi la queue de liste
  if (f->tete == NULL)
    f->queue = e;
  else
    f->tete->precedent = e;
  f->tete = e;
  return f;
}

fileInt* defiler(fileInt *f) {
  if (estFileVide(f))
    return f;
  else {
    // si la liste n'avait qu'un element elle devient vide
    if (f->queue->precedent == NULL) {
      f->queue = NULL;
      f->tete = NULL;
    } else {
      //l'element de queue est detache du precedent
      f->queue->precedent->suivant = NULL;
      //qui devient la nouvelle queue
      f->queue = f->queue->precedent;
    }
  }
  return f;
}

int obtenirElementFile(fileInt *f) {
  return f->queue->valeur;
}

int estFileVide(fileInt *f) {
  return (f->tete == NULL);
}
