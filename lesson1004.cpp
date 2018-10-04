#include <iostream>
using namespace std;

// Employee class
class Employee
{
protected:
	char name[20];
	int pay;
public:
	Employee(const char* _name);
	virtual const char* GetName();
	virtual int GetPay();
};

Employee::Employee(const char* _name)
{
	strcpy_s(name, _name);
}
 const char* Employee::GetName()
{
	return name;
}
 int Employee::GetPay()
 {
	 return  pay;
 }


// Permanent class
class Permanent : public Employee
{
private:
	int salary;
public:
	Permanent(const char * _name, int sal);
	virtual int GetPay();
};
Permanent::Permanent(const char* _name, int sal)
	:Employee(_name)
{
	salary = sal;
}
int Permanent::GetPay()
{
	return salary;
}

// Temporary class
class Temporary :public Employee
{
private:
	int time;  
	int pay;
public:
	Temporary(const char* _name, int _time, int _pay);
	virtual int GetPay();
};
Temporary::Temporary(const char* _name, int _time, int _pay)
	:Employee(_name)
{
	time = _time;
	pay = _pay;
}
int Temporary::GetPay()
{
	return time*pay;
}

// Department class
class Department
{
private:
	Employee * empList[10];
	int index;
public:
	Department() : index(0) {};
	void AddEmployee(Employee * emp);
	void ShowList();
};

void Department::AddEmployee(Employee * emp)
{
	empList[index++] = emp;
}
void Department::ShowList()
{
	for (int i = 0; i < index; i++) {
		cout << "name : " << empList[i]->GetName() << endl;
		cout << "pay : " << empList[i]->GetPay() << endl;
		cout << endl;
}
}

int main()
{
	Department department;
	department.AddEmployee(new Permanent("Kim", 2000));
	department.AddEmployee(new Permanent("Lee",1000));
	department.AddEmployee(new Temporary("Han",10,1800));
	department.AddEmployee(new Temporary("Shin", 8, 3000));

	department.ShowList();
	return 0;

}