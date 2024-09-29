#include <bits/stdc++.h>
using namespace std;

class Product{
private:
    int Quantity;
    float Price;
    string Name;
    int ID;
    string availabilityStatus;

    static float total_value;
public:
    void assignInfo(string name,int id,float price,int qty){
        this->Name = name;
        this->ID = id;
        this->Quantity = qty;
        this->Price = price;
        this->total_value += price * qty;
    }
    void addToInventory(int addedQuantity){
        Quantity += addedQuantity;
    }
    bool isAvailable(){
        return Quantity > 0;
    }
    void purchase(int purchasedQuantity){
        if(Quantity - purchasedQuantity < 0){
            cout << "Purchased quantity is greater than stock" << endl;
            return;
        }
        Quantity -= purchasedQuantity;
    }
    void updatePrice(int discountPercent){
        total_value -= (Quantity * Price);
        Price = Price - Price * (discountPercent/100.0);
        total_value += (Quantity * Price);
    }
    void displayInventoryValue(){
        cout << "The sum of all of these products in inventory is: "
             << Price*Quantity << endl;
    }
    void displayDetails(){
       cout << "The details regarding the product are given below:\n";

       cout << "The Product name is: "  << Name << endl;
       cout << "The Product ID is: "  << ID << endl;
       cout << "The Product Price is: "  << Price << endl;
       cout << "Availability: " << (isAvailable() ? "Available" : "Out of Stock") << '\n';
       cout << "The Product Quantity is: "  << Quantity << endl;
    }
    static float getTotalVal(){
        return total_value;
    }
    static void displayTotalInventoryValue(){
        cout << "The total value of all the products available in the inventory is: "<<getTotalVal() << endl;
    }
    Product(){
        Quantity = 0;
        Price = 0;
        Name = "Not Assigned yet";
        ID = -1;
        availabilityStatus = "Item is undeclared";
    }

};

float Product :: total_value = 0;
int main(){
    Product soap,lemon;

    soap.assignInfo("Merlin",213,50,10);

    soap.displayDetails();
    soap.displayTotalInventoryValue();

    lemon.assignInfo("REMON",223,50,10);
    lemon.displayDetails();
    lemon.displayTotalInventoryValue();


    soap.updatePrice(50);

    soap.displayDetails();
    soap.displayTotalInventoryValue();
}

