#include<iostream>
#include <exception>
using namespace std;

class test {
	private:
		static int count;
	public:
		test() {
			if(count<=5 ) {
				count++;
			}
			else {
				throw "Can't create any more objects";
			}
		}
		int getValueOfCount() {
			return count;
		}
};

int test::count = 1;

int main() {
	//test *t1 = new test();
	test t1;
	try {
		cout<<"First instance: "<<t1.getValueOfCount()<<endl;
	}catch(const char* msg) {
		cerr<<msg<<endl;
	}
	
	//test *t2 = new test();
	test t2;
	try {
		cout<<"Second instance : "<<t2.getValueOfCount()<<endl;
	}catch(const char* msg) {
		cerr<<msg<<endl;
	}
	
	
	//test *t3 = new test();
	test t3;
	try {
		cout<<"Third instance : "<<t3.getValueOfCount()<<endl;
	}catch(const char* msg) {
		cerr<<msg<<endl;
	}
	
	//test *t4 = new test();
	test t4;
	try {
		cout<<"Fourth instance : "<<t4.getValueOfCount()<<endl;
	}catch(const char* msg) {
		cerr<<msg<<endl;
	}
	
	//test *t5 = new test();
	test t5;
	try {
		cout<<"Fifth instance : "<<t5.getValueOfCount()<<endl;
	}catch(const char* msg) {
		cerr<<msg<<endl;
	}
	
	//test *t6 = new test();
	test t6;
	try {
		cout<<"Sixth instance : "<<t6.getValueOfCount()<<endl;
	}catch(const char* msg) {
		cerr<<msg<<endl;
	}
	

	
	return 0;
}
