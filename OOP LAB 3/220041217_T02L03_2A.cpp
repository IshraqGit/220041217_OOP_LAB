#include <bits/stdc++.h>
using namespace std;

class RationalNumber{
    private:
        int numerator;
        int denominator;
    public:
        void assign(int numerator,int denominator){
            if(denominator != 0){
                this->numerator = numerator;
                this->denominator = denominator;
            }else{
                cout << "You can not assign 0 as denominator" << endl;
            }
        }
        float convert(){
            return (float)numerator/denominator;
        }
        void invert(){
            if(numerator == 0){
                cout<< "You can not assign 0 as denominator.Inversion Failed";
            }else{
                swap(numerator,denominator);
            }
        }
        void print(){
            cout << "The Rational Number is ";
            if(numerator*denominator < 0){
                cout << "- ";
            }
            cout << abs(numerator) << "/" << abs(denominator) << endl;
        }
};
int main(){
    RationalNumber r;
    r.assign(3,-2);
    r.convert();
    r.print();

    r.invert();
    r.print();
}


