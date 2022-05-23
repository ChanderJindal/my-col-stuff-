read text
# Split the string by space
readarray -d "" -t strarr <<< "$text"

# Print each value of the array by 
# using loop
for (( n=0; n < ${#strarr[*]}; n++))
    do
        echo "${strarr[n]}"
done