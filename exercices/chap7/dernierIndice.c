#include<stdio.h>
#include<string.h>

int dernierIndice(char *txt, char c) {
  for (int i = strlen(txt); i >= 0; i--)
    if (txt[i] == c) return i;
  return -1;
}

int main(int argc, char **argv) {
  printf("%d\n",dernierIndice("abdcd",'d'));
  printf("%d\n",dernierIndice("abcda",'c'));
  printf("%d\n",dernierIndice("abcd",'e'));
}
