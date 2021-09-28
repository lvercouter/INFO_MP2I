void parcoursProfondeurPrefixe(arbre *a) {
  pileArbre *pile = newPileArbre();
  pile = empiler(pile,a);
  while (!estPileVide(pile)) {
    arbre * n = obtenirElementPile(pile);
    // realiser ici ce qui doit etre fait lors
    // de la visite du noeud n
    listeArbre *fils = obtenirFils(n);
    pile = depiler(pile);
    // les noeuds fils sont ensuite ajoutes dans
    // la pile
    while (fils != NULL) {
      pile = empiler(pile,fils);
      fils = fils->suivant;
    }
  }
}
