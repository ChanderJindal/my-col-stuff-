#Average of n numbers
#1st
echo "Enter N"
read n 
total=0
i=1

while (( i<=n ))
    do
        read temp
        total=$((temp+total))
        ((i++))
done
echo "The Total Sum is = $total"
printf "The Average is = %.4f \n" $(echo $total / $n | bc -l)
