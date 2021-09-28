#ifndef FILEINT_H
#define FILEINT_H

struct selement {
  int valeur;
  struct selement *precedent;
  struct selement *suivant;
};
typedef struct selement element;

typedef struct {
  element *tete;
  element *queue;
} fileInt;
#endif

fileInt* newFileInt();
fileInt* enfiler(fileInt *f, int val);
fileInt* defiler(fileInt *f);
int obtenirElementFile(fileInt *f);
int estFileVide(fileInt *f);
