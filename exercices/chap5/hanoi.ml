let rec hanoi n a c b = match n with
    | 1 -> 1 (* Un disque va de a vers c *)
    | _ -> hanoi (n-1) a b c +
            hanoi 1 a c b +
            hanoi (n-1) b c a
