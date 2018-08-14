echo "Enter the number"
read num
x=`expr $num % 2`
if [ $x -eq 0 ]
then
   echo "even"
else
   echo "odd"
fi       