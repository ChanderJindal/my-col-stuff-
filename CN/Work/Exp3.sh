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

echo "./waf --run hello-simulator  
./waf --run first 
./waf --run second 
rm temp.sh" > ns-allinone-3.32/ns-3.32/temp.sh
#Enter the 3 commands to run there

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
