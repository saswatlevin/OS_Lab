echo "Enter num"
read num
start=1
while [ $start -le $num ]
do
	echo $start
    start=$((start+2))
done    	