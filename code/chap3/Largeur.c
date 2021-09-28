void parcoursLargeur(arbre *a) {
  fileArbre *file = newFileArbre();
  file = enfiler(file,a);
  while (!estFileVide(file)) {
    arbre * n = obtenirElementFile(file);
    // realiser ici ce qui doit etre fait lors
    // de la visite du noeud n
    listeArbre *fils = obtenirFils(n);
    file = defiler(file);
    // les noeuds fils sont ensuite ajoutes dans
    // la pile
    while (fils != NULL) {
      file = enfiler(file,fils);
      fils = fils->suivant;
    }
  }
}
