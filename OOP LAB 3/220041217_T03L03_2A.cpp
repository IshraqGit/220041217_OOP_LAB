#include <bits/stdc++.h>
using namespace std;

class bankAccount{
    private:
        string nameOfTheCustomer;
        int accountNumber;
        string typeOfAccount;
        int balanceAmount;
    public:
        bankAccount(){
            balanceAmount = 0;
        }
        void customerDetails(string name,int accNum){
            this->nameOfTheCustomer = name;
            this->accountNumber = accNum;
        }
        void accountType(string accType){
           this->typeOfAccount = accType;
        }
        void balance(){
            cout << "Current Balance is: " << balanceAmount << endl;
        }
        void deposit(int pushCash){
            this->balanceAmount = pushCash;
            cout << "Balance After Deposit: " << balanceAmount << endl;
        }

        void withdraw(int pullCash){
            cout << "Balance before withdrawing cash: " << balanceAmount << endl;
            balanceAmount -= pullCash;
            cout << "Balance after withdrawing cash: " << balanceAmount << endl;
        }
        void display(){
            cout << "Customer Bank Account Details:\n";
            cout << "Name           : " << nameOfTheCustomer << endl;
            cout << "Account number : "<< accountNumber << endl;
            cout << "Account type   : " << typeOfAccount << endl;
            cout << "Total Balance  : " << balanceAmount << endl;
        }
};
int main(){
    bankAccount b;
    b.customerDetails("Ishraq",123);
    b.accountType("Current");
    b.balance();
    b.deposit(10000);
    b.withdraw(500);
    b.display();
}


