#check Palindrome
read str 
NewStr=`echo "$str" | rev`

echo $str
echo $NewStr
if [[ "$NewStr" == "$str" ]]
    then
        echo "$str is a Palindrome."
else
    echo "$str is NOT a Palindrome."
fi