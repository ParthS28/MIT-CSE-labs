echo "Enter a, b and c"
read a
read b
read c
d=`expr $b \* $b - 4 \* $a \* $c`
echo $d

if [ $d -gt 0 ]
then
q="r"
echo "Real and distinct roots"
elif [ $d -lt 0 ]
then
q="i"
echo "Imaginary roots"
else
echo "Real and equal roots"
q="e"
fi
case $q in
"r")
d=`echo "scale=4; sqrt($d)" | bc`
s1=`echo "(-1*$b)/(2*$a)" | bc`
s2=`echo "($d)/(2*$a)" | bc`
r1=`echo "($s1+$s2)" | bc`
r2=`echo "($s1-$s2)" | bc`
echo "Root1: $r1 Root2: $r2"
;;
"e")
d=`echo "scale=4; sqrt($d)" | bc`
s1=`echo "(-1*$b)/(2*$a)" | bc`
s2=`echo "($d)/(2*$a)" | bc`
r1=`echo "($s1+$s2)" | bc`
echo "Root: $r1"
;;
"i")
d=`echo "-1*$d" |bc`
d=`echo "scale=4; sqrt($d)" | bc`
s1=`echo "(-1*$b)/(2*$a)" | bc`
s2=`echo "($d)/(2*$a)" | bc`
echo "Root1: $s1 + $s2 i"
echo "Root2: $s1 - $s2 i"
;;
esac