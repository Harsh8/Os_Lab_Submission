echo "enter pattern ";
 read a;
echo "enter file name ";
read c;
b= grep $a $c;
if [ $? -eq 0 ]
then              
echo pattern found ;
else
echo pattern not found;
fi
