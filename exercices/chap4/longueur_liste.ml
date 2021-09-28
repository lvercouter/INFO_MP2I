let rec longueur_liste l = match l with
  | [] -> 0
  | hd::tl -> 1 + longueur_liste tl;;
