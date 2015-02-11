echo -n "Enter a number to get sum upto that number"
read no
echo $no
n=`expr $no + 1 `
k=`expr $no \* $n `
ans=`expr $k / 2 `
echo $ans
 
