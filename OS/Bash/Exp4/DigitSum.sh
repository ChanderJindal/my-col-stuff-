#sum of digits
#4th
read n
MyAnswer=0
while ((n>0))
    do
        MyAnswer=$((MyAnswer + n%10 ))
        n=$((n/10))
done
echo "The Sum of Digits is $MyAnswer"