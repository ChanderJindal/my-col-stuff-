#include <iostream>
using namespace std;
class Complex{
private: float real;
float imag;
public:
Complex(): real(0), imag(0){ }
void input(){ int a[2];
for(int i=0; i<2; i++){ cin>>a[i]; }
real = a[0]; imag = a[1]; }
Complex operator + (Complex c){
Complex temp;
temp.real = real + c.real;
temp.imag = imag + c.imag;
return temp; }
friend Complex operator * (Complex c1, Complex c2);
void output(){
if(imag < 0) cout << "Complex number: "<< real<< "i" << imag ;
else cout << "Complex number: " <<real << " + i" <<imag; }};
Complex operator * (Complex c1, Complex c2) {
Complex c3;
c3.real=c1.real*c2.real-c1.imag*c2.imag;
c3.imag=c1.imag*c2.imag;
return(c3); }
int main(){
Complex b, c, result;
int ch;
cout<<"\nEnter 1st complex number:- ";b.input();
cout<<"Enter 2nd complex number:- ";c.input();
cout<<"Complex Numbers operations\n1. Addition\n2. Multiplication";
cout<<"\nEnter choice:- ";cin>>ch;
switch(ch){
case 1:result = b + c;
result.output(); break;
case 2:result = b*c;
result.output(); break; }
cout<<"\nThis has been '+' operator overloading by Chander Jindal\n";
return 0;
}
