read n 
total=0
#declare -i temp=0
for i in `seq 1 $n`
do
    read temp
    let total=total+temp

done

printf "%.3f" $(bc -l <<< $total/$n)
