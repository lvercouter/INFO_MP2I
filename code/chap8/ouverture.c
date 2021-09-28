FILE *f = fopen("monFichier.txt","r+"); if (f != NULL) {
  //...
  // realiser des ecritures et lecture
  fclose(f);
} else printf("Echec de l'ouverture");
