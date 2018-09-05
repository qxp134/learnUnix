#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

int a = 0;
mutex mu;

class Lock{
private:
	mutex t;
	mutex* mt =& t;
public:
	Lock(mutex* m) :mt(m)
	{ 
		this->mt->lock();
	}
	~Lock(){ (*mt).unlock(); }
};

void fun(){

	for (int i = 0; i < 100; i++){
		Lock m1(&mu);
		a++;
		cout << a << "我是t1" << endl;
		
	}
}

void fun1(){
	for (int i = 100; i > 0; i--){
		Lock m2(&mu);
		a++;
		cout << a <<"我是t2\n" ;

	}	
}

int main(){
	thread t1(fun);
	thread t2(fun1);
	t1.join();
	t2.join();
	return 0;
}