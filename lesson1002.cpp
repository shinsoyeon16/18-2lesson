//»ó¼Ó

#include <iostream>
using namespace std;

class Person {
public:
	void sleep() {
		cout << "sleep" << endl;
	}
};
class Student : public Person {
public:
	void study() {
		cout << "study" << endl;
	}
};

class ParTimeStd : public Student {
public:
	void work() {
		cout << "work" << endl;
	}
};
int main() {
		return 0;
	}


