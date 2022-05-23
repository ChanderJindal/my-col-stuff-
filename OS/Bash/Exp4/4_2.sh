#Fibonacci series
read n

if [[ n == 0 ]]
    then
        exit
elif [[ n == 1 ]]
    then
        echo "1"
        exit
else
    i=1
    first=1
    second=1
    echo "The #1 number of Fibonacci series is = 1"
    while(( i < n ))
        do  
            echo "The #$i number of Fibonacci series is = $second"
            second=$((second+first))
            first=$((second-first))
            ((i++))
        done
fi 