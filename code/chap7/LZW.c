#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"dictionnaireStringInt.h"
#include"dictionnaireIntString.h"

unsigned short *compressionLZW(char *txt) {
  dictionnaireStringInt *d = newDictionnaireStringInt();
  char *mot = (char *)malloc(100*sizeof(char));
  char *nvMot;
  int j = 0, k = 0;
  int code = 257;
  unsigned short *resultat =
    (unsigned short *)malloc(strlen(txt)*sizeof(unsigned short));
  for (int i = 0; i < strlen(txt); i++) {
    mot[j] = txt[i];
    mot[j+1] = '\0';
    // on verifie si le mot est dans le dictionnaire
    if ((strlen(mot) > 1) && (!estPresentDictSI(d,mot))) {
      // le nouveau mot est ajoute dans le dictionnaire
      ajouterDictSI(d,mot,code);
      code++;
      nvMot = (char *)malloc(100*sizeof(char));
      strncpy(nvMot,mot,strlen(mot)-1);
      // le code du mot est recupere et ecrit
      if (strlen(nvMot) > 1)
        resultat[k] = (unsigned short)obtenirElementDictSI(d,nvMot);
      else resultat[k] = (unsigned short)nvMot[0];
      k++;
      // le mot est mis a jour avec le dernier caractere seulement
      j = 0;
      nvMot[0] = txt[i];
      nvMot[1] = '\0';
      mot = nvMot;
    }
    j++;
  }
  // le dernier mot est ecrit
  if (strlen(nvMot) > 1) {
    resultat[k] = (unsigned short)obtenirElementDictSI(d,nvMot);
  }
  else resultat[k] = (unsigned short)nvMot[0];
  return resultat;
}

char *decompressionLZW(unsigned short *data) {
  dictionnaireIntString *d = newDictionnaireIntString();
  int i = 1, j = 1, code = 257;
  char *tmpRes= (char *)malloc(1000*sizeof(char));
  char *mot = (char *)malloc(10*sizeof(char));
  char *motDic = (char *)malloc(10*sizeof(char));
  // lecture du premier caractere
  char lastCar = data[0];
  motDic[0] = data[0]; motDic[1] = '\0';
  tmpRes[0] = data[0];
  while (data[i] != 0) {
    // pour tous les autres code, le caractere precedent
    // est concatene avec celuis correspondant au code
    // courant. Le mot obtenu est ajoute au dictionnaire
    if (data[i] < 257) {
      sprintf(mot,"%c",(char)data[i]);
      tmpRes[j] = data[i];
      sprintf(motDic,"%c%c",lastCar,data[i]);
      ajouterDictIS(d,(int)code,motDic);code++;
      j++;
    } else if (estPresentDictIS(d,data[i])) {
      mot = obtenirElementDictIS(d,(int)data[i]);
      tmpRes = strcat(tmpRes,mot);
      sprintf(motDic,"%c%s",lastCar,mot);
      ajouterDictIS(d,(int)code,motDic);code++;
      j = j + strlen(mot);
    }
    // preparation de l'etape suivante avec une maj du
    // dernier caractere et la preparation d'un nouveau
    // mot a ajouter au dictionnaire
    i++;
    lastCar = mot[strlen(mot)-1];
    motDic = (char *)malloc(10*sizeof(char));
  }
  tmpRes[j] = '\0';
  // une chaine de caracteres de la taille necessaire au resultat
  // est allouee et renvoye
  char * resultat = (char *)malloc(strlen(tmpRes)*sizeof(char));
  strcpy(resultat,tmpRes);
  return resultat;
}

int main(int argc, char **argv) {
  unsigned short *tab = compressionLZW("taratata");
  for (int i = 0; i < strlen("taratata"); i++)
    printf("%u ", tab[i]);
  printf("\n");
  printf("Decompression: %s\n,",decompressionLZW(tab));
  tab = compressionLZW("barbapapa");
  for (int i = 0; i < strlen("barbapapa"); i++)
    printf("%u ", tab[i]);
  printf("\n");
  printf("Decompression: %s\n,",decompressionLZW(tab));
}
