#include "Products.h"

#include <iostream>
using namespace std;

Products::Products()
{

}
bool Products :: operator < (Products &P){
    return this->Name < P.Name;
}

float Products :: netTotal(int amountOfProducts){
    float Discount = calculateDiscount(amountOfProducts);
    float Regular = Amount*RegularPrice;

    float Net = Regular - Discount;

    return Net;
}
double Products :: calculateDiscount(int amountofProducts){
    double discountPrice;
    if(amountofProducts > Amount){
        cout << "Purchased amount is greater than inventory" << endl;
        exit(1);
    }
    if(amountofProducts >= 5){
        discountPrice = (amountofProducts*RegularPrice)*(DiscountRate/100);
    }
    if(amountofProducts >= 10){
        discountPrice = discountPrice * 0.03;
    }

    return discountPrice;

}

void Products :: setName(string name){
    Name = name;
}
void Products :: setCategory(string category){
    Category = category;
}
void Products :: setDescription(string description){
    Description = description;
}
void Products :: setAmount(int amount){
    Amount = amount;
}
void Products :: setRegularPrice(float regularprice){
    RegularPrice = regularprice;
}
void Products :: setDiscountRate(float discountrate){
    DiscountRate = discountrate;
}

string Products :: getName(){
    return Name;
}
string Products :: getCategory(){
    return Category;
}
string Products :: getDescription(){
    return Description;
}
int Products :: getAmount(){
    return Amount;
}
float Products :: getRegularPrice(){
    return RegularPrice;
}
float Products :: getDiscountRate(){
    return DiscountRate;
}
