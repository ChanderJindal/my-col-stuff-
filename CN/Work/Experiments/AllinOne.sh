touch ns-allinone-3.32/ns-3.32/temp.sh 
#Make a temp file

echo "
echo 'Hello World!'
./waf --run hello-simulator  

echo '

###############################

First Network

Default Network Topology

       10.1.1.0
 n0 -------------- n1
    point-to-point

'
./waf --run first 

echo '

###############################

Second Network

 Default Network Topology

       10.1.1.0
 n0 -------------- n1   n2   n3   n4
    point-to-point  |    |    |    |
                    ================
                      LAN 10.1.2.0
'
./waf --run second

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

'
./waf --run third

echo '

###############################

Fourth Experiment
'

./waf --run fourth

echo '

###############################

Fifth Network(TCP)

         node 0                 node 1
   +----------------+    +----------------+
   |    ns-3 TCP    |    |    ns-3 TCP    |
   +----------------+    +----------------+
   |    10.1.1.1    |    |    10.1.1.2    |
   +----------------+    +----------------+
   | point-to-point |    | point-to-point |
   +----------------+    +----------------+
           |                     |
           +---------------------+
                5 Mbps, 2 ms

'

./waf --run fifth

echo '

###############################

Sixth Network(TCP)

         node 0                 node 1
   +----------------+    +----------------+
   |    ns-3 TCP    |    |    ns-3 TCP    |
   +----------------+    +----------------+
   |    10.1.1.1    |    |    10.1.1.2    |
   +----------------+    +----------------+
   | point-to-point |    | point-to-point |
   +----------------+    +----------------+
           |                     |
           +---------------------+
                5 Mbps, 2 ms
'
./waf --run sixth

echo '

###############################

Seventh Network (TCP)


         node 0                 node 1
   +----------------+    +----------------+
   |    ns-3 TCP    |    |    ns-3 TCP    |
   +----------------+    +----------------+
   |    10.1.1.1    |    |    10.1.1.2    |
   +----------------+    +----------------+
   | point-to-point |    | point-to-point |
   +----------------+    +----------------+
           |                     |
           +---------------------+
                5 Mbps, 2 ms

'

./waf --run seventh

rm temp.sh

" > ns-allinone-3.32/ns-3.32/temp.sh
#Enter the commands to run there

echo "
###################

TYPE './temp.sh'

###################
"

cd  ns-allinone-3.32/ns-3.32
$SHELL
