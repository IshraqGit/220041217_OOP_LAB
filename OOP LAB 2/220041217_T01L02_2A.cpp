#include <bits/stdc++.h>
using namespace std;

int main(){
    int f1n,f1d,f2n,f2d;
    cout << "Enter first fraction: ";
    cin>>f1n; cin.ignore(); cin>>f1d;

    cout << "Enter second fraction: ";
    cin>>f2n; cin.ignore(); cin>>f2d;

    int den = f1d * f2d;
    int a = f1n*f2d,b = f2n* f1d;
    int res = a+b;

    cout << "Sum = " << res << "/" << den << endl;

}
