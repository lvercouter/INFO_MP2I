#include<stdio.h>

int main(int argc, char**argv) {
  int heure,minute;
  do {
    printf("Heure ? ");
    scanf("%d",&heure);
    if ((heure < 0) || (heure > 23))
      printf("L'heure doit etre entre 0 et 23\n");
  } while ((heure < 0) || (heure > 23));
  do {
    printf("Minute ? ");
    scanf("%d",&minute);
    if ((minute < 0) || (minute > 59))
      printf("La minute doit etre entre 0 et 59\n");
  } while ((minute < 0) || (minute > 59));
  if (((heure > 6)||((heure == 6)&&(minute > 29))) &&
    (heure < 12))
    printf("Matin\n");
  else if ((heure > 11) && (heure < 14))
    printf("Midi\n");
  else if ((heure > 13) && (heure < 18))
    printf("Apres-midi\n");
  else if ((heure > 17) &&
    ((heure < 21)||((heure == 21)&&(minute < 30))))
    printf("Soiree\n");
  else printf("\n");
}
