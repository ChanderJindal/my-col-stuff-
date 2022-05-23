#Check if input is Int or str
read a
if [[ $a == $((a)) ]]
    then
        echo "It's a Number!"
        exit
fi
echo "It's a String!"