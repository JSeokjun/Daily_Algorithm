let rec factorial product counter maxcounter =
  if counter > maxcounter then product
  else factorial (product * counter) (counter + 1) maxcounter;;

let n = Scanf.scanf "%d" (fun x -> x);;

print_int(factorial 1 1 n)