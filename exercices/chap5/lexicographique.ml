let rec ordre_lex l m = match l,m with
    | [],[] -> 0
    | [],_ -> -1
    | _,[] -> 1
    | hd1::tl1,hd2::tl2 ->
        if hd1 > hd2 then 1
        else if hd2 > hd1 then -1
        else ordre_lex tl1 tl2
