#include<stdio.h>

int main(int argc, char**argv) {
  int montant, dix, cinq, deux, un;
  printf("Quel est le montant ? ");
  scanf("%d",&montant);
  dix = montant / 10;
  montant = montant % 10;
  cinq = montant / 5;
  montant = montant % 5;
  deux = montant / 2;
  un = montant % 2;
  printf("%d billets de 10 euros.\n",dix);
  printf("%d billets de 5 euros.\n",cinq);
  printf("%d billets de 2 euros.\n",deux);
  printf("%d billets de 1 euro.\n",un);
}
