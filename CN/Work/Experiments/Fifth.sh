touch ns-allinone-3.32/ns-3.32/temp.sh 
echo "
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

./waf --run fifth
'

./waf --run fifth

rm temp.sh
" > ns-allinone-3.32/ns-3.32/temp.sh 
cd  ns-allinone-3.32/ns-3.32
$SHELL

