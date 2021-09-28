let calcul op x y =
  	match op with
  		| "plus" -> x+y
  		| "moins" -> x-y
  		| "multiplie" -> x*y
  		| "divise" -> x/y
  		| _ -> 0;;
