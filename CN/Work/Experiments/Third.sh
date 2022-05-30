touch ns-allinone-3.32/ns-3.32/temp.sh 
echo "
echo '

###############################

Third Network

 Default Network Topology

   Wifi 10.1.3.0
                 AP
  *    *    *    *
  |    |    |    |    10.1.1.0
 n5   n6   n7   n0 -------------- n1   n2   n3   n4
                   point-to-point  |    |    |    |
                                   ================
                                     LAN 10.1.2.0


./waf --run third

'
./waf --run third


rm temp.sh
" > ns-allinone-3.32/ns-3.32/temp.sh 
cd  ns-allinone-3.32/ns-3.32
$SHELL

