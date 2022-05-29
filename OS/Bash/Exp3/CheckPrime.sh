#check prime
#3rd
read a 
flag=0
for((i=2; i<=`echo "sqrt($a)" | bc`; i++))
do
    if [ $((a%i)) == 0 ]
        then
            flag=1 
            break
    fi
done
if (( flag == 0  ))
    then
        echo "$a is a Prime Number"
else
    echo "$a is not a Prime Number"
fi
