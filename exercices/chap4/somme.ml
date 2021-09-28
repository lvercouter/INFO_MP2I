let rec somme_entiers n = match n with
  | 1 -> 1
  | _ -> n + (somme_entiers (n-1));;
