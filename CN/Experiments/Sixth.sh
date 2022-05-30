touch ns-allinone-3.32/ns-3.32/temp.sh 
echo "
echo'
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

./waf --run sixth
'
./waf --run sixth

rm temp.sh
" > ns-allinone-3.32/ns-3.32/temp.sh 
cd  ns-allinone-3.32/ns-3.32
$SHELL

