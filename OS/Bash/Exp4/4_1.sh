#Average of n numbers
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
echo "$total"
printf "%.4f" `echo "$((total/n))" | bc`
