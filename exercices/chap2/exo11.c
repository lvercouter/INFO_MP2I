#include<stdio.h>
#include<string.h>

int main(int argc, char**argv) {
  char str[100];
  int palindrome = 1,i = 0,longueur;
  printf("Entrez une chaine de caracteres : ");
  scanf("%s",str);
  longueur = strlen(str);
  while (i < (longueur/2)) {
    if (str[i] != str[longueur - i - 1])
      palindrome = 0;
    i++;
  }
  if (palindrome)
    printf("C'est un palindrome.\n");
  else
    printf("Ce n'est pas un palindrome.\n");
}
