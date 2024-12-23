#include <iostream>
using namespace  std;

class Shapes{
    protected:
        int area;
    public:
        virtual void getArea() {}
};

class circle : public Shapes {
        int radius;
    public:
        void getArea(int r) {
            area = 3.14 * r * r;
            cout<<area<<" cm^2"<<endl;
        }
};

class triangle : public Shapes {
        int base;
        int height;
    public:
        void getArea(int b, int h) {
            area = 0.5 * b * h;
            cout<<area<<" cm^2"<<endl;
        }
};

class rectangle : public Shapes {
        int length;
        int breadth;
    public:
        void getArea(int l, int b) {
            area = l * b;
            cout<<area<<" cm^2"<<endl;
        }
};

int main() {
    circle c;
    triangle t;
    rectangle r;

    int n;
    cout<<"Enter 1 for circle, 2 for triangle and 3 for rectangle.";
    cin>>n;

    switch(n) {
        case 1:
            int radius;
            cout<<"Enter radius : ";
            cin>>radius;
            c.getArea(radius);
            break;
        case 2:
            int base, height;
            cout<<"Enter base : ";
            cin>>base;
            cout<<"Enter height : ";
            cin>>height;
            t.getArea(base, height);
            break;
        case 3:
            int length, breadth;
            cout<<"Enter length : ";
            cin>>length;
            cout<<"Enter breadth : ";
            cin>>breadth;
            r.getArea(length, breadth);
            break;
        default:
            cout<<"Invalid Choice.";
    }
    return 0;
}