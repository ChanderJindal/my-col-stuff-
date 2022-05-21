read equation 
printf "%.3f" $(bc -l <<< $equation)

#read equation 

#echo $equation | bc 
#echo "scale=3;$equation" | bc
#no round offs here
