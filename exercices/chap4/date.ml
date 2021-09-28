type mois = Janvier | Fevrier | Mars |
  Avril | Mai | Juin | Juillet | Aout |
  Septembre | Octobre | Novembre | Decembre;;

type date = {j : int; m : mois; a : int };;

let bissextile a =
  (a mod 4 =0) && (not (a mod 100 = 0) || (a mod 400 = 0));;

let existe d = match d.m with
  | Avril|Juin|Septembre|Novembre -> (d.j > 0) && (d.j <= 30)
  | Fevrier -> if bissextile d.a then (d.j > 0) && (d.j <= 29)
                else (d.j > 0) && (d.j <= 28)
  | _ -> (d.j > 0) && (d.j <= 31);;
