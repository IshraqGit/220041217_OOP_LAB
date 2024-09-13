#include <bits/stdc++.h>
using namespace std;

int main(){

    cout << "Enter employee type (first letter only):\n"
         << "laborer (l), secretary (s), manager (m), accountant (a),\n"
         << "executive (e), researcher (r): " << endl;
    enum etype {
    laborer,
    secretary,
    manager,
    accountant,
    executive,
    researcher };

    etype chakri;

    char ch;
    cin>>ch;

    switch(ch){
    case 'l':
        chakri = laborer;
        break;
    case 's':
        chakri = secretary;
        break;
    case 'm':
        chakri = manager;
        break;
    case 'a':
        chakri = accountant;
        break;
    case 'e':

        chakri = executive;
        break;
    case 'r':
        chakri = researcher;
        break;
    default:
        cout << "Invalid input!." << endl;
        return 1;
    }

    switch(chakri){

    case laborer:
        cout << "Employee type is laborer." << endl;
        break;
    case secretary:
        cout << "Employee type is secretary." << endl;
        break;
    case manager:
        cout << "Employee type is manager." << endl;
        break;
    case accountant:
        cout << "Employee type is accountant." << endl;
        break;
    case executive:
        cout << "Employee type is executive." << endl;
        break;
    case researcher:
        cout << "Employee type is researcher." << endl;
        break;

    }
}

