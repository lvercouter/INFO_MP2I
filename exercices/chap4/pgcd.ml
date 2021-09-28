let rec pgcd a b =
  if b = 0 then a else pgcd b (a mod b);;
