#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <string>
using namespace std;

class Products
{
    private:
        string Name;
        string Category;
        string Description;
        int Amount;
        float RegularPrice;
        float DiscountRate;

    public:
        Products();

        void setName(string name);
        void setCategory(string category);
        void setDescription(string description);
        void setAmount(int amount);
        void setRegularPrice(float regularprice);
        void setDiscountRate(float discountrate);

        string getName();
        string getCategory();
        string getDescription();
        int getAmount();
        float getRegularPrice();
        float getDiscountRate();

        double calculateDiscount(int amountofProducts);


        float netTotal(int amountOfProducts);

        bool operator < (Products &P);

};

#endif // PRODUCTS_H
