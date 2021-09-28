let rec catalan n = match n with
    | 0 -> 1
    | n -> 2*(2*n-1) * catalan(n-1) / (n+1)
