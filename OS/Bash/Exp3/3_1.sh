#Greatest of 3 numbers
read a
read b
read c

if (($a > $b));then
    if (($a > $c));then
        echo "The Greatest of $a, $b and $c is $a"
    else  
        echo "The Greatest of $a, $b and $c is $c"
    fi
else
    if (($b > $c)); then
        echo "The Greatest of $a, $b and $c is $b"
    else
        echo "The Greatest of $a, $b and $c is $c"
    fi
fi