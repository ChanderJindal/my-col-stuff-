#check Palindrome
#5th
read str 
NewStr=`echo "$str" | rev`

if [[ "$NewStr" == "$str" ]]
    then
        echo "$str is a Palindrome."
else
    echo "$str is NOT a Palindrome."
fi
