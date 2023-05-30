#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <stdlib.h>
using namespace std;

void generateSetOfNumbers(int arr[]) {
int p[50] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36, 37,38,39,40,41,42,43,44,45,46,47,48,49};
for (int i=49; i>0; --i){
int j = rand()%i;
int temp = p[i];
p[i] = p[j];
p[j] = temp; }
for (int i=0; i<10; ++i)
arr[i] = p[i]; }
int main(){
string ques[50],ans[50]; int r[10];
for(int i=0,j=1;i<50;i++,j++){
stringstream s1,s2;
s1 << i; s2 << j;
ques[i]="1+";
ques[i]+=s1.str();
ans[i]=s2.str();
}
srand(time(0)); generateSetOfNumbers(r); for(int i=0;i<10;i++){
int x=r[i]; cout<<ques[x]<<endl; }
cout<<"Chander Jindal's Code\n";
return 0;}