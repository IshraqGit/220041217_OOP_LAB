#include <bits/stdc++.h>
using namespace std;

class BankAccount{
private:
    int AccNum;
    string Name;
    string AccType;
    double Balance;
    const double MinBalance;
    static int TotalAcc;
    static int CurAcc;
    static double totalSourceTax;
public:
    BankAccount(int accnum,string name,string acctype,double balance,double minbalance)
        : MinBalance(minbalance){
        this->AccNum = accnum;
        this->Name = name;
        this->AccType = acctype;
        this->Balance = balance;
        TotalAcc++;
        CurAcc++;
    }
    ~BankAccount(){
        cout << "Account of Mr." << Name << " with account no " << AccNum <<
                " is destroyed with a balance BDT " << Balance << endl;
        CurAcc--;
    }
    double getBalance() const{
        return Balance;
    }
    void giveInterest(double interestRate = 3.00){
        double interest = Balance * (interestRate/100.0);
        double tax = interest * 0.10;
        double netInterest = interest - tax;
        totalSourceTax += tax;
        Balance  += netInterest;
        showBalance();
    }
    void withdrawal(double x){
        if(x<0 || (Balance - x < MinBalance)){
            cout << "Invalid Amount withdrawal" << endl;
            return;
        }
        Balance -= x;
        showBalance();
    }
    void deposit(double x){
       if(x<=0){
         cout << "Invalid amount deposit" << endl;
         return;
       }
       Balance += x;
       showBalance();
    }
    void showBalance(){
        cout << "Current Balance: " << Balance << endl;
    }
    void display(){
        cout << AccNum << endl;
        cout << Name << endl;
        cout << AccType << endl;
        cout << Balance << endl;
        cout << MinBalance << endl;
    }

    static int getTotalAccounts(){
        return TotalAcc;
    }
    static int getActiveAccounts(){
        return CurAcc;
    }
    static double getTotalSourceTax(){
        return totalSourceTax;
    }

};

int BankAccount :: TotalAcc = 0;
int BankAccount :: CurAcc = 0;
double BankAccount::totalSourceTax = 0.0;


void display_stat() {
    cout << "Total BankAccounts created: " << BankAccount::getTotalAccounts() << endl;
    cout << "Total active BankAccounts: " << BankAccount::getActiveAccounts() << endl;
    cout << "Total source tax collected: BDT " << BankAccount::getTotalSourceTax() << endl;
}

BankAccount Larger(const BankAccount &A,const BankAccount &B){
    return (A.getBalance() > B.getBalance()) ? A : B;
}
int main(){
    BankAccount acc1(12345, "Alice", "Savings", 10000.0, 1000.0);
    BankAccount acc2(67890, "Bob", "Current", 15000.0, 500.0);
    acc1.display();
    acc2.display();
    acc1.deposit(5000);
    acc2.withdrawal(3000);
    acc1.giveInterest();
    acc2.giveInterest(4.0);

    BankAccount largerAccount = Larger(acc1, acc2);
    cout << "Larger account balance belongs to: " << largerAccount.getBalance() << endl;
    display_stat();
}
