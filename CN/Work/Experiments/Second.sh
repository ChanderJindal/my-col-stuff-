touch ns-allinone-3.32/ns-3.32/temp.sh 
echo "
echo '

###############################

Second Network

 Default Network Topology

       10.1.1.0
 n0 -------------- n1   n2   n3   n4
    point-to-point  |    |    |    |
                    ================
                      LAN 10.1.2.0

./waf --run second

'
./waf --run second

rm temp.sh
" > ns-allinone-3.32/ns-3.32/temp.sh 
cd  ns-allinone-3.32/ns-3.32
$SHELL

