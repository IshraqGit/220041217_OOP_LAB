#include <bits/stdc++.h>
using namespace std;

class Temperature{
    private:
        int temp;
        int incrementStep;
    public:
        Temperature(){
            temp = 0;
        }
        void setIncrementStep(int x){
            incrementStep = x;
        }
        int getTemperature(){
            return temp;
        }
        void increment(){
            temp += incrementStep;
        }
        void resetTemperature(){
            temp = 0;
        }


};
int main(){
    Temperature a;
    a.setIncrementStep(1);
    a.increment();
    a.increment();
    a.increment();
    cout << a.getTemperature() << endl;

}
