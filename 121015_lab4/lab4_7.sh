echo Enter a filename
read a
echo 'Do you want to revoke the read and write permissions for file $a?'
echo 'If yes then type y'
read b
if [ $b = 'y' -o $b = 'Y' ]
then 
echo Write the code for the permission
read c
chmod $c $a
else
echo No changes needed
fi
