touch ns-allinone-3.32/ns-3.32/temp.sh 
echo "
echo '

###############################

First Network

Default Network Topology

       10.1.1.0
 n0 -------------- n1
    point-to-point

./waf --run first 

' 
./waf --run first 

rm temp.sh
" > ns-allinone-3.32/ns-3.32/temp.sh 
cd  ns-allinone-3.32/ns-3.32
$SHELL

