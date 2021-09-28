#include <stdio.h>

enum jour{lundi,mardi,mercredi,jeudi,vendredi,samedi,dimanche};

int main(int argc, char **argv) {
  enum jour j;
  j = jeudi;
  printf("%d\n",j);
}
