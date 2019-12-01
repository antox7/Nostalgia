// Ashurov, Anvar
// CS211 52A Homework 7B 

#include <iostream>
using namespace std;
int main( )
{

int b[3][2];
cout<<sizeof(b)<<endl;  //24 
cout<<sizeof(b+0)<<endl; // 8
cout<<sizeof(*(b+0))<<endl; // 8
// the next line prints 0012FF68
cout<<"The address of b is: "<<b<<endl; //0x7ffd354b70c0
cout<<"The address of b+1 is: "<<b+1<<endl; //0x7ffd354b70c8
cout<<"The address of &b is: "<<&b<<endl; //0x7ffd354b70c0
;
cout<<"The address of &b+1 is: "<<&b+1<<endl<<endl; //0x7ffec70db0e8
return 0;
}