#include<iostream>
using namespace std;
class complex {
public:
int real, imag;
complex(int r=0,int i=0){
r=real;
i=imag;
}
complex operator + (complex const &obj){
complex obj1;
obj1.real = real + obj.real;
obj1.imag = imag + obj.imag;
return obj1;
}
complex operator * (complex const &obj){
complex obj1;
obj1.real=((real)*(obj.real))-((imag)*(obj.imag));
obj1.imag=((real)*(obj.imag))+((imag)*(obj.real));
return obj1;
}
void multiplication(){
cout<<"MULTIPLICATION OF THE COMPLEX NUMBERS IS: "<<endl;
cout<<real<<"+"<<imag<<"i"<<endl;
}
void addition(){
cout<<"ADDITION OF THE COMPLEX NUMBERS IS: "<<endl;
cout << real <<"+"<<imag<<"i"<< '\n';
}
};
int main()
{
int l=0;
while (l==0)
{
complex c1,c2,c3,c4;
cout<<"ENTER REAL PART OF FIRST NUMBER: "<<endl;
cin>>c1.real;
cout<<"ENTER IMAGINARY PART OF FIRST NUMBER: "<<endl;
cin>>c1.imag;
cout<<"ENTER REAL PART OF SECOND NUMBER: "<<endl;
cin>>c2.real;
cout<<"ENTER IMAGINARY PART OF SECOND NUMBER: "<<endl;
cin>>c2.imag;
int e;
cout<<"WHICH OPERATION YOU WOULD LIKE TO PERFORM:\n PRESS1:ADDITION \n PRESS2:MULTIPLICATION "<<endl;
cin>>e;
switch (e)
{
case 1:
c3=c1+c2;
c3.addition();
break;
case 2:
c4=c1*c2;
c4.multiplication();
break;
default:
cout<<"Error";
break;
return 0;
}
}
}

