#include <bits/stdc++.h>
using namespace std;

class employee{
private:
    string EmpName;
    int ID;
    float BaseSalary;
    int JoiningYear;
    int YearsOfService;
public:
    void FeedInfo(string name, int id, float salary, int year) {
        EmpName = name;
        ID = id;
        BaseSalary = salary;
        JoiningYear = year;
        YearsOfService = 2024 - JoiningYear;
    }
    float calculateTotalSalary() const{
        float updatedBaseSalary = BaseSalary;
        for (int i=0;i<YearsOfService;i++) {
            updatedBaseSalary += updatedBaseSalary * 0.03;
        }
        float transport = updatedBaseSalary*0.10;
        float housing = updatedBaseSalary*0.30;
        float miscellaneous = updatedBaseSalary*0.10;

        return updatedBaseSalary + transport + housing + miscellaneous;

    }
    float calculateBonus() const {
        string status = getStatus();
        float updatedBaseSalary = BaseSalary;

        for (int i = 0; i < YearsOfService; i++) {
            updatedBaseSalary += updatedBaseSalary * 0.03;
        }

        // Determine bonus based on status
        if (status == "Low") {
            return updatedBaseSalary * 0.05; // 5% for Low status
        } else if (status == "Moderate") {
            return updatedBaseSalary * 0.10; // 10% for Moderate status
        } else if (status == "High") {
            return updatedBaseSalary * 0.15; // 15% for High status
        }

        return 0.0;
    }


    void ShowInfo() const {
        cout << "Employee Name: " << EmpName << endl;
        cout << "Employee ID: " << ID << endl;
        cout << "Base Salary: $" << BaseSalary << endl;
        cout << "Joining Year: " << JoiningYear << endl;
        cout << "Years of Service: " << YearsOfService << endl;
        cout << "Total Salary: $" << calculateTotalSalary() << endl;
        cout << "Bonus: $" << calculateBonus() << endl;
        cout << "Status: " << getStatus() << endl;
    }

    string getStatus() const {
        int currentYear = 2024;
        int age = currentYear - JoiningYear;
        float totalSalary = calculateTotalSalary();

        if (age <= 25) {
            if (totalSalary <= 20000) {
                return "Low";
            } else {
                return "Moderate";
            }
        } else {
            if (totalSalary <= 21000) {
                return "Low";
            } else if (totalSalary > 21000 && totalSalary <= 60000) {
                return "Moderate";
            } else {
                return "High";
            }
        }
    }
};
int main(){
   employee emp;
    emp.FeedInfo("John Doe", 12345, 18000, 2018);
    emp.ShowInfo();

}
