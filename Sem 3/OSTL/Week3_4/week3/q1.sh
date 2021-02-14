echo "Enter number"
read n
no=`expr \( $n \% 2 \)`
if [ $no -eq 0 ]
then
echo "even"
else
echo "odd"
fi
