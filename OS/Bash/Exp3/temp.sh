declare -i testvar
declare testvar="0"
echo $testvar
declare testvar="1"
echo $testvar
if (($testvar == 1))
    then 
        echo "1"
elif (($testvar == "1"))
    then
        echo "2"
else
    echo "3"
fi 