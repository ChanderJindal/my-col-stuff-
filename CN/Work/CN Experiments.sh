sudo apt update
#get update if any

sudo apt install build-essential autoconf automake libxmu-dev
#Install #1

sudo apt install build-essential autoconf automake libxmu-dev python-pygraphviz cvs mercurial bzr git cmake p7zip-full python-matplotlib python-tk python-dev python-kiwi python-gnome2 python-gnome2-desktop qt4-dev-tools qt4-qmake qt4-qmake qt4-default gnuplot-x11 wireshark

#Install #2

wget https://www.nsnam.org/releases/ns-allinone-3.32.tar.bz2
#Get file from link
#git clone https://gitlab.com/nsnam/ns-3-allinone.git
#2nd option ^

tar jxvf ns-allinone-3.32.tar.bz2 
#unzip Linux style

#cd ns-allinone-3.32
#$SHELL
#Change of Working Directory causes fall of Script

./ns-allinone-3.32/build.py --enable-examples --enable-tests
#Build in that directory

#cd ns-3.32
#$SHELL 
#Change of Working Directory causes fall of Script

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

Fourth Experiment'

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

./ns-allinone-3.32/ns-3.32/temp.sh
#Run that new file
#didn't worked from distance

rm ns-allinone-3.32/ns-3.32/temp.sh
#After the work is done, remove all proof

'''
./ns-allinone-3.32/ns-3.32/waf --run hello-simulator

./ns-allinone-3.32/ns-3.32/waf --run first
#./ns-allinone-3.32/ns-3.32/waf --pyrun first.py

./ns-allinone-3.32/ns-3.32/waf --run second 
#./ns-allinone-3.32/ns-3.32/waf --pyrun second.py
'''
