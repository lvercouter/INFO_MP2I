let affiche_division x y =
  	try print_int  (division x y) with
  		Division_by_zero -> print_string "Division impossible"
