type 'a arbre_binaire =
  | Vide
  | Noeud of ('a arbre_binaire) * 'a * ('a arbre_binaire);;

let rec rechercher ab x = match ab with
  | Vide -> false
  | Noeud(abg,v,abd) -> if x = v then true
            else (rechercher abg x) || (rechercher abd x);;

let rec rechercher_abr ab x = match ab with
  | Vide -> false
  | Noeud(abg,v,abd) -> if x = v then true
            else if x < v then (rechercher_abr abg x)
            else (rechercher_abr abd x);;
