#include<stdio.h>
#include<math.h>
#include<string.h>

long hashRabin(char *txt, int base) {
  long hash = 0;
  for (int i = 0; i < strlen(txt); i++) {
    hash += txt[i]*pow(base,strlen(txt)-i-1);
  }
  return hash;
}

long newHashRabin(long hash, int base, char* ancienTxt, char nouveau) {
  // on retire la valeur du premier caractere
  long res = hash-ancienTxt[0]*pow(base,strlen(ancienTxt)-1);
  // on monte d'une puissance les valeurs restantes
  res = res * base;
  // on ajoute le nouveau caractere
  res += nouveau;
  return res;
}

int rabinKarp(char *txt, char *seq) {
  long hashSeq = hashRabin(seq,101);
  char tmpStr[100];
  // tmpStr sert a stocker les parties du texte a comparer
  // le debut du texte de la meme taille que seq est copie
  strncpy(tmpStr,txt,strlen(seq));
  long hashTxt = hashRabin(tmpStr,101);
  for (int i = 0; i < strlen(txt) - strlen(seq) + 1; i++ ) {
    if (hashSeq == hashTxt) {
      // les hash sont egaux, on compare chaque caractere
      int j = i;
      while ((j < i + strlen(seq))&&(seq[j-i] == txt[j])) j++;
      // si ce test est vrai la sequence est trouvee
      if (j == (i + strlen(seq))) return i;
    }
    // le hash de la sequence est mis a jour
    // pour la prochaine iteration
    if ((i + strlen(seq)) < strlen(txt)) {
      hashTxt = newHashRabin(hashTxt,101,tmpStr,txt[i + strlen(seq)]);
      strncpy(tmpStr,&(txt[i+1]),strlen(seq));
    }
  }
  return -1;
}

int main(int argc, char **argv) {
  printf("%d\n",rabinKarp("here is a simple test","test"));
  printf("%d\n",rabinKarp("here is a simple example","here"));
  printf("%d\n",rabinKarp("abcd","ab"));
  printf("%d\n",rabinKarp("abcd","bc"));
  printf("%d\n",rabinKarp("abcd","de"));
}
