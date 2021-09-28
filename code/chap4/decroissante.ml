let gen_decroissante l =
        match l with
          | [] -> 1 :: l
          | head::tail -> (head+1) :: l;;
