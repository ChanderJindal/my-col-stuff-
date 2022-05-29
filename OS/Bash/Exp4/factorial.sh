#factorial
#3rd

read n

MyAnswer=1

while ((n>0))
    do
        MyAnswer=$((MyAnswer*n))
        ((n--))
done
echo "The Factorial is $MyAnswer"