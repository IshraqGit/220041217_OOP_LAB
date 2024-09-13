#include <bits/stdc++.h>
using namespace std;

struct frac{
    int num;
    int den;
};
int main(){
    frac n1,n2,res;
    cout << "Enter first fraction: ";
    cin>>n1.num; cin.ignore(); cin>>n1.den;

    cout << "Enter Second fraction: ";
    cin>>n2.num; cin.ignore(); cin>>n2.den;

    res.den = n1.den * n2.den;
    res.num = n1.num*n2.den + n2.num*n1.den;

        cout << "Sum = " << res.num << "/" << res.den << endl;

}

