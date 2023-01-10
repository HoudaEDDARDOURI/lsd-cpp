#include <iostream>
using namespace std;

class shape 
{   
    public :
        float width;
        float height;
        shape(float ,float );
};
//constructor of class shape defined outside the class 
shape::shape(float x,float y)
{   
        width = x;
        height = y;
}

class rectangle : public shape 
{
    public :
        float area();
        rectangle(float w,float h) : shape(w,h) {} ;
};

float rectangle::area()
{
    return height * width;
}


class triangle : public shape
{
    public :
        float area();
        triangle(float w,float h) : shape(w,h) {};
    
};

float triangle::area()
{
    return width * height * 0.5 ;
}


int main()
{
    rectangle R(3.33,2);
    cout << "area of rectangle : "<<R.area()<<endl;
    triangle T(4.5,7);
    cout << "area of triangle : "<< T.area();
    

    return 0;
}
