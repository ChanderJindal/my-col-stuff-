read x
read y 
if (($x > $y));then   #Yes then is to be in same line
echo "X is greater than Y  ";
elif (($x == $y));then
    printf "X is equal to Y   "; #yes, echo and printf both print
else 
    echo "X is less than Y  ";
fi