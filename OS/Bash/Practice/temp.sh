read n 
total=0
#declare -i temp=0
for i in `seq 1 $n`
do
    read temp
    let total=total+temp

done

echo "scale=3;$total/$n" | bc 