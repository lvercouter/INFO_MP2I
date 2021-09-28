let min x y = if x < y then x else y;;

let rec minimum_liste l = match l with
  | [x] -> x
  | hd::tl -> min hd minimum_liste(tl);;
