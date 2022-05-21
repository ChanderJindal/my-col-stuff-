read a
read b
read c

if (($a == $b && $b == $c)); then
echo "EQUILATERAL  "
elif (($a == $c || $a == $b || $b == $c)); then
printf "ISOSCELES"
else
echo "SCALENE"
fi