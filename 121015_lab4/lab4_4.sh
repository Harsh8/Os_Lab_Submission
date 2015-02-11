echo -n "Enter a number"
read no
n=`expr $no / 2 `
i=2
sym=0
if [ $no == 2 ]
then
sym=0
elif [ $no == 3 ]
then 
sym=0
else
while [ "$i" -le "$n" ]
do

d=`expr $no % $i `

if [ $d == 0 ]
then
sym=1
#echo $sym
fi

i=`expr $i + 1 `
done
fi

if [ $sym == 1 ]
then
echo Not a prime number
else
echo It is  a prime number 
fi 
