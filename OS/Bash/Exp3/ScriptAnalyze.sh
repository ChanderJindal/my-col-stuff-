#File commands
read file
c=`cat $file | wc -c`
w=`cat $file | wc -w`
l=`grep -c "." $file`
echo "Total characters = $c"
echo "Total words = $w"
echo "Total lines = $l"
