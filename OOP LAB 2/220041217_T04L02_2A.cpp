#include <bits/stdc++.h>
using namespace std;

const int distance = 100;

struct Car {
    string brand;
    string model;
    int year;
    string fuel_type;
    int mileage;
    float fuel_price_per_liter;
};

void display_carinfo(const Car& c, int i);
void check_fuel_efficiency(const Car& c);
float fuel_consumption_calculation(const Car& c);
int fuel_cost_estimation(const Car& c);

int main() {
    cout << "How many cars do you want to input: ";
    int n; cin >> n;
    Car cars[n];

    for (int i = 0; i < n; ++i) {
        cout << "Information for car " << i + 1 << ": " << endl;

        cout << "Car brand: ";
        cin >> cars[i].brand;

        cout << "Car model: ";
        cin >> cars[i].model;

        cout << "Car year: ";
        cin >> cars[i].year;

        cout << "Car fuel type: ";
        cin >> cars[i].fuel_type;

        cout << "Car mileage (km per liter): ";
        cin >> cars[i].mileage;

        cout << "Fuel price per liter: ";
        cin >> cars[i].fuel_price_per_liter;
    }

    for (int i = 0; i < n; ++i) {
        display_carinfo(cars[i], i);
        check_fuel_efficiency(cars[i]);
        cout << "Fuel consumption for 100 km: " << fuel_consumption_calculation(cars[i]) << " liters" << endl;
        cout << "Estimated fuel cost for 100 km: $" << fuel_cost_estimation(cars[i]) << endl;
    }

    return 0;
}

float fuel_consumption_calculation(const Car& c) {
    return  100/ (float)c.mileage;
}

void check_fuel_efficiency(const Car& c) {
    if (c.fuel_type == "Electric") {
        cout << "The car is fuel efficient" << endl;
    } else if (c.mileage > 15) {
        cout << "The car is fuel efficient" << endl;
    } else {
        cout << "The car is not fuel efficient" << endl;
    }
}

void display_carinfo(const Car& c, int i) {
    cout << "Information for car " << i + 1 << ": " << endl;
    cout << "Car brand     : " << c.brand << endl;
    cout << "Car model     : " << c.model << endl;
    cout << "Car year      : " << c.year << endl;
    cout << "Car fuel type : " << c.fuel_type << endl;
    cout << "Car mileage   : " << c.mileage << " km per liter" << endl;
    cout << "Fuel price per liter: $" << c.fuel_price_per_liter << endl;
}

int fuel_cost_estimation(const Car& c) {
    return fuel_consumption_calculation(c) ;
}
