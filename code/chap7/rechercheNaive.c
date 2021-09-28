#include<stdio.h>
#include<string.h>

int rechercheNaive(char *txt, char *seq) {
  for (int i = 0; i < (strlen(txt)-strlen(seq)+1); i++) {
    int j = 0;
    while ((j < strlen(seq)) && (seq[j] == txt[i+j]))
      j++;
    if (j == strlen(seq)) return i;
  }
  return -1;
}

int main(int argc, char **argv) {
  printf("%d\n",rechercheNaive("abcd","cd"));
  printf("%d\n",rechercheNaive("abcd","bc"));
  printf("%d\n",rechercheNaive("abcd","de"));
}
