#include <bits/stdc++.h>
using namespace std;

class Person{
protected:
    string name;
public:
    Person(string n):name(n){}
    virtual void display() const{
        cout << "Name: " << name << endl;
    }
};

class Employee : public Person{
private:
    int employeeID;

protected:
    float salary;

public:
    Employee(string n,int e,float s):Person(n),employeeID(e),salary(s){}
    int getEmployeeID(){ return employeeID;}
        void display() const{
            cout << "Name: " << name << endl;
            cout << "Employee ID: " << employeeID << endl;
            cout << "Salary: " << salary << endl;
        }

};
class Intern : public Employee{
private:
   string schoolName;
public:
    Intern(string n,int eID,float s,string sName)
        : Employee(n, eID, s), schoolName(sName) {}

    void display(){
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << getEmployeeID() << endl;
        cout << "Salary: " << salary << endl;
        cout << "School Name: " << schoolName << endl;
    }
};

class Manager : protected Employee{
private:
    string department;
public:
     Manager(string n,int eID, float s,string d)
        : Employee(n, eID, s), department(d){}

    string getDepartment(){return department;}
    void display(){
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << getEmployeeID() << endl;
        cout << "Salary: " << salary << endl;
        cout << "Department: " << department << endl;
    }
};

class Director : public Manager{
private:
    float bonus;
public:
    Director(string n,int eID,float s,string d, float b)
        : Manager(n, eID, s, d), bonus(b) {}

    void display(){
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << getEmployeeID() << endl;
        cout << "Salary: " << salary << endl;
        cout << "Department: " << getDepartment() << endl;
        cout << "Bonus: " << bonus << endl;
    }
};

int main(){
    Intern i("Ishraq", 101, 1533.12, "IuT");
    Manager m("Samira", 102, 123.123, "Sales");
    Director d("Trump", 103, 4512.52, "Operations", 2000.0);

    cout << "Intern Details:" << endl;
    i.display();
    cout << endl;

    cout << "Manager Details:" << endl;
    m.display();
    cout << endl;

    cout << "Director Details:" << endl;
    d.display();
    cout << endl;

}
