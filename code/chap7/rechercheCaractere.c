#include<stdio.h>
#include<string.h>

int rechercheCaractere(char *txt, char c) {
  for (int i = 0; i < strlen(txt); i++)
    if (txt[i] == c) return i;
  return -1;
}

int main(int argc, char **argv) {
  printf("%d\n",rechercheCaractere("abcd",'d'));
  printf("%d\n",rechercheCaractere("abcd",'a'));
  printf("%d\n",rechercheCaractere("abcd",'e'));
}
