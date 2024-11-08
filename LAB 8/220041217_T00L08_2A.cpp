#include <bits/stdc++.h>
using namespace std;

class Shape{
public:
    virtual void whoAmI(){
        cout << "What shape am I?" << endl;
    }
};

class TwoDimensionalShape : public Shape{
protected:
    float Area;
    float Perimeter;
public:
    void setArea(float a){Area = a;}
    void setPerimeter(float p){Perimeter = p;}

    float getArea(){return Area;}
    float getPerimeter(){return Perimeter;}
    void whoAmI(){
        cout <<"I am a Two Dimensional Shape"<< endl;
    }
    virtual float calculateArea(){
        return 0.00;
    }
    virtual float calculatePerimeter(){
        return 0.00;
    }
    virtual void print(){
        cout << "Area is      : " << Area << endl;
        cout << "Perimeter is : " << Perimeter << endl;
    }
};

class ThreeDimensionalShape : public Shape{
private:
    float SurfaceArea;
    float Volume;
public:
    void setSurfaceArea(float a){SurfaceArea = a;}
    void setVolume(float v){Volume = v;}

    float getSurfaceArea(){return SurfaceArea;}
    float getVolume(){return Volume;}
    void whoAmI(){
        cout << "I am a Three Dimensional Shape" << endl;
    }
    virtual float calculateSurfaceArea(){
        return 0.00;
    }
    virtual float calculateVolume(){
        return 0.00;
    }
    virtual void print(){
        cout << "Surface Area is : " << SurfaceArea << endl;
        cout << "Volume is       : " << Volume << endl;
    }
};

class Square :public TwoDimensionalShape{
private:
    float side;

public:
    Square(float s) : side(s){
        setArea(side * side);
        setPerimeter(4 * side);
    }
    void whoAmI(){
        cout <<"I am Square. I am a Two Dimensional Shape" << endl;
    }
};

class Circle : public TwoDimensionalShape{
private:
    float r;
public:
    Circle(float rad) : r(rad){
        setArea(3.1416*r*r);
        setPerimeter(2 *3.1416*r);
    }
    void whoAmI(){
        cout <<"I am Circle. I am a Two Dimensional Shape"<< endl;
    }
};

class Cube : public ThreeDimensionalShape{
private:
    float Length;

public:
    Cube(float l) : Length(l){
        setSurfaceArea(6 *Length *Length);
        setVolume(Length*Length * Length);
    }
    void whoAmI(){
        cout << "I am Cube. I am a Three Dimensional Shape" << endl;
    }
};

class Cylinder : public ThreeDimensionalShape{
private:
    float Height;
    float Radius;

public:
    Cylinder(float r,float h) :Radius(r),Height(h){
        setSurfaceArea(2 * 3.1416 * Radius * Height + 2 * 3.1416 * Radius * Radius);
        setVolume(3.1416 * Radius * Radius * Height);
    }
    void whoAmI(){
        cout << "I am Cylinder. I am a Three Dimensional Shape" << endl;
    }
};

int main() {
    Square sq(5);
    sq.whoAmI();
    sq.print();

    cout << endl;

    Circle circ(10.2);
    circ.whoAmI();
    circ.print();

    cout << endl;

    Cube Cuba(34.15);
    Cuba.whoAmI();
    Cuba.print();

    cout << endl;

    Cylinder Seal(12.9,12.3);
    Seal.whoAmI();
    Seal.print();
}
