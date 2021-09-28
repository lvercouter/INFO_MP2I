#ifndef FILEINT_H
#define FILEINT_H

struct EFI {
  int valeur;
  struct EFI *precedent;
  struct EFI *suivant;
};
typedef struct EFI elementFileInt;

typedef struct {
  elementFileInt *tete;
  elementFileInt *queue;
} fileInt;
#endif

fileInt* newFileInt();
fileInt* enfiler(fileInt *f, int val);
fileInt* defiler(fileInt *f);
int obtenirElementFile(fileInt *f);
int estFileVide(fileInt *f);
