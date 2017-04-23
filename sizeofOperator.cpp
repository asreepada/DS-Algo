#include <iostream>

#define my_sizeof(type)   (char*)(&type+1)-(char*)(&type) //(char *)(&type+1)-(char*)(&type)
using namespace std;
int main() {
    int i=0;
    double j=0.0;
    cout<<"The size is : "<<my_sizeof(i)<<endl;
    cout<<"Size of char : "<<my_sizeof(j)<<endl;
    return 0;
}
