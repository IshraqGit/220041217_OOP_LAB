#include <iostream>
#include "Products.h"
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <bits/stdc++.h>

using namespace std;

void EditInformationByKeyboard(Products &P);
string generateRandomString(int length);
double randomInRange(double min, double max);
int randomInRange(int min, int max);
void generateInformaiotnRandom(Products &P);
void ShowAllDiscount(Products ar[]);
void grossTotal(Products ar[]);
void ShowAllAlphabetically(Products  ar[]);

int main()
{
    Products Product[100];

    cout << "Enter information for first Product." << endl;
    EditInformationByKeyboard(Product[0]);
//    cout << "Enter information for second Product" << endl;
//    EditInformationByKeyboard(Product[1]);

    for(int i=1;i<100;i++){
        generateInformaiotnRandom(Product[i]);
    }
//    ShowAllDiscount(Product);

//    grossTotal(Product);

    ShowAllAlphabetically(Product);

}
void ShowAllAlphabetically(Products  ar[]){
    sort(ar,ar+100);

    for(int i=0;i<100;i++){
        cout << ar[i].getName() << endl;
    }
}
void grossTotal(Products ar[]){
  for(int i=0;i<100;i++){
     cout << "Net Total for Product " << i+1 << " is:\n";
     cout << ar[i].netTotal(ar[i].getAmount()) << endl;
  }
}
void ShowAllDiscount(Products ar[]){
  for(int i=0;i<100;i++){
     cout << "Total Discount for Product " << i+1 << " is:\n";
     cout << ar[i].calculateDiscount(ar[i].getAmount()) << endl;
  }
}
void generateInformaiotnRandom(Products &P){
    string Name = generateRandomString(randomInRange(3,7)) + " " +
                  generateRandomString(randomInRange(3,7)) + " " +
                  generateRandomString(randomInRange(3,7));

    string CategoryName = generateRandomString(randomInRange(3,7));
    string Description = "";
    for(int i=0;i<10;i++){
        Description += generateRandomString(randomInRange(3,7)) + " ";
    }
    static int  counter  = 1;
    srand(counter++);
    int Amount = randomInRange(1,100);
    double RegularPrice = randomInRange(10.50,2000.50);
    double DiscountRate = randomInRange(3,15);

    P.setName(Name);
    P.setCategory(CategoryName);
    P.setDescription(Description);
    P.setAmount(Amount);
//    cout << RegularPrice << endl;
    P.setRegularPrice(RegularPrice);
    P.setDiscountRate(DiscountRate);
}

double randomInRange(double min, double max) {
    // Ensure min is less than or equal to max
    if (min > max) {
        std::swap(min, max); // Swap if min is greater than max
    }

    // Generate a random double between 0 and 1
    double randomFraction = static_cast<double>(rand()) / RAND_MAX;

    // Scale and shift the random value to the desired range
    return min + randomFraction * (max - min);
}

int randomInRange(int min, int max) {
    // Ensure min is less than or equal to max
    if (min > max) {
        std::swap(min, max); // Swap if min is greater than max
    }

    return rand() % (max - min + 1) + min;
}

string generateRandomString(int length) {
    std::string randomString;
    const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int alphabetSize = sizeof(alphabet) - 1; // Exclude null character

    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    for (int i = 0; i < length; ++i) {
        randomString += alphabet[rand() % alphabetSize];
    }

    return randomString;
}

void EditInformationByKeyboard(Products &P){
        cout << "Name: ";
        string Name; cin>>Name;
        cout << "Category: ";
        string Category; cin>>Category;
        cout << "Description: ";
        string Description; cin>>Description;

        cout << "Amount: ";
        int Amount; cin>>Amount;
        cout << "RegularPrice: ";
        float RegularPrice; cin>>RegularPrice;
        cout << "DiscountRate: ";
        float DiscountRate; cin>>DiscountRate;

        P.setName(Name);
        P.setCategory(Category);
        P.setDescription(Description);
        P.setAmount(Amount);
        P.setRegularPrice(RegularPrice);
        P.setDiscountRate(DiscountRate);
}
