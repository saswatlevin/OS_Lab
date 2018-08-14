#!/bin/bash
prime(){

echo "Hi!"
echo "Enter number"
read number
i=2
if [ $number -eq 2 ]
then
echo "Prime"	
fi

while [ $i -lt $number ]

do
i=$((i+1))
x=`expr $number % 2`
if [ $x -eq 0 ]
then
    echo "Not Prime"
    exit 0
else
    echo "Prime"
    exit 0
fi
done
}

prime
exit 0