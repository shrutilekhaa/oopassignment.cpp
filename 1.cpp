#include<iostream>
using namespace std;
class Shape{
    public:
    //constructor destructor 
    Shape(){}
    ~Shape(){}
    //virtual function
    virtual void get()=0;
    virtual float area()=0;
};
class Rectangle:public Shape{//inheritance used
    int lt,bt;
    public:
    //deriving constructor
    Rectangle():Shape(){
        cout<<"Constructor called for Rectangle\n"<<endl;
    }
    void get(){
        try{
        cout<<"Enter length and breadth of rectangle: "<<endl;
        cin>>lt>>bt;
        if (lt==bt)
            throw "rectangle has same length and breadth values";}
    catch(...){
        cout<<"Exception handled and not a rectangle\n"<<endl;
    }
    }
    float area(){
        int result=lt*bt;
        cout<<"The area of rectangle is: "<<result<<endl;
    }
};
class Triangle:public Shape{
    int b,h;
    public:
    //deriving constructor
    Triangle():Shape(){
        cout<<"Constructor called for Triangle\n"<<endl;
    }
    void get(){
        cout<<"Enter base and height of triangle: "<<endl;
        cin>>b>>h;
    }
    float area(){
        int result=0.5*b*h;
        cout<<"The area of triangle is: "<<result<<endl;
        return result;
    }
    //operator overloading
    Triangle operator ++(){
        Triangle x;
        x.b=++b;
        x.h=++h;
        cout<<"Area after incrementing is: "<<endl;
    }
};
class Circle:public Shape{
    int r;
    public:
    //deriving constructor
    Circle():Shape(){
        cout<<"Constructor called for Circle\n"<<endl;
    }
    void get(){
        cout<<"Enter radius of circle: "<<endl;
        cin>>r;
    }
    float area(){
        float result=3.14*r*r;
        cout<<"The area of circle is: "<<result<<endl;
        return result;
    }
    //template
    template <typename T> T increase(T r){
        ++r;
        return 3.14*r*r;
    }
};
class Square:public Shape{
    int s;
    public:
    //deriving constructor
    Square():Shape(){
        cout<<"Constructor called for Square\n"<<endl;
    }
    void get(){
        cout<<"Enter side of square: "<<endl;
        cin>>s;
    }
    float area(){
        float result=s*s;
        cout<<"The area of square is: "<<result<<endl;
        return result;
    }
    //operator overloading using friend
    friend void operator ++(Square &x){
        x.s=x.s+1;
        cout<<"Area of square after incrementing is: "<<endl;
    }
    
};
int main()
{
    Shape *s1, *s2, *s3, *s4, *s5;
    Rectangle r;
    Triangle t;
    Circle c;
    Square s;
    s1=&r;
    s2=&t;
    s3=&c;
    s4=&s;
    //exception handling used for rectangle
    s1->get();
    s1->area();
    s2->get();
    s2->area();
    //operator overloading used for triangle
    ++t;
    s2->area();
    s3->get();
    s3->area();
    //using template for circle
    cout<<"Area after incrementing for circle is: "<<c.increase<float>(3.2)<<endl;
    s4->get();
    s4->area();
    //operator overloading using friend function for square
    ++s;
    s4->area();
    return 0;
}
