let rec multiplication x y = match x with
    | 1 -> y
    | n -> y + multiplication (x-1) y
