let rec factoriel x = match x with
      | 1 -> 1
      | _ -> x * factoriel(x-1)

let _ =
  let n = Scanf.scanf "%d" (fun x -> x) in
  let res = factoriel n in
  let _ = Printf.printf "%d! = %d\n" n res in ()
