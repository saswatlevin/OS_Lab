echo "Enter a"
read a
echo "Enter b"
read b
echo "Enter c"
read c
d=$((b*b))
x=$((4*a*c))
det=$((d-x))
abs=${det#-}
case $det in
	$abs)
     echo "Roots are"
     echo "scale=3 ( ( ( -1 *$b)+sqrt($det) )/( 2*$a ) )|bc"
     echo "scale=3 ( ( ( -1 *$b)-sqrt($det) )/( 2*$a ) )|bc"
     ;;
     *)
     echo "Imaginary Roots"
     ;;
     *)
esac
exit 0     