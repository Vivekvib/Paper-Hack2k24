#include <iostream>
#include <string>
using namespace std;

class Person{
	protected:
		string name;
	public:
		Person(string n): name(n) {}
		void display();
};

class Student:public Person{
	string course;
	float marks;
	int year;
	public: 
		Student(string n, string c, float m, int y): Person(n), course(c), marks(m), year(y) {}
		void display();
};

class Employee:public Person{
	string department;
	int salary;
	public:
		Employee(string n,string d, int s): Person(n), department(d), salary(s) {}
		void display();
};

void Person::display(){
	cout << "Name of the person is: " << name << endl;
}

void Student::display() {
	Person::display();
	cout << "My course is: " << course << endl;
	cout << "Marks Scored: " << marks << endl;
	cout << "Current Year: " << year << endl;
}

void Employee::display(){
	Person::display();
	cout << "Department: " << department << endl;
	cout << "Salary: " << salary << endl;
}

int main() {
	Person p("Anish");
	Employee e("Dhruv", "C.S", 300000);
	Student s("Mohit","C.S",80,1);
	e.display();
}

