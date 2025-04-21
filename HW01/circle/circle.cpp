#include "circle.h"
#include<iostream>
#include<stdexcept>
using namespace std;
circle::circle( float r, int x , int y) {
    set_r(r);
    set_center(x,y);
}

void circle::set_r(float r)
{ if(r>0)
     this->r=r;
    else
        throw invalid_argument("radius can't be negative");
}

void circle::set_center(int x, int y)
{
    this->x=x;
    this->y=y;
}

float circle::get_r() const
{
    return r;
}

int circle::get_x() const
{
    return x;
}

float circle::perimeter(float r)
{
    float res=  2*r*3.14;
    return res;
}

float circle::area(float r)
{
    float a= r*r*3.14;
    return a;
}

void circle::shift(int a, int b)
{
    x+=a;
    y+=b;
}

int circle::get_y() const
{
    return y;
}

void circle::print()
{   cout <<"Information:"<<endl;
    cout<<"The radius of circle is : "<<get_r()<<endl;
    cout<<"The center of circle is : "<< "("<< get_x()<<","<<get_y()<<")"<<endl;
    cout<<"The perimeter of circle is : "<<perimeter(r)<<endl;
    cout<<"The area of circle is : "<<area(r)<<endl;
}


