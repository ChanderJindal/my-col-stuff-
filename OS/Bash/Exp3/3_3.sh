#check prime or not
read a
declare -i flag
declare flag="0"
#echo " sqrt($a) " | bc
declare -i i 
declare i="1"
while (( $i > $sqrt($a)+1 ))
    do
        ((i++))
        echo $i
        if (($a % $i == 0))
            then
                declare $flag = "1"
                echo "$i"
            fi      
done
if (($flag == 1 ))
    then
        echo "The number $a is Prime"
else
    echo "The number $a is NOT Prime"
fi
