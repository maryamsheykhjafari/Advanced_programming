#include <iostream>
#include<vector>
#include<cmath>
using namespace std;

class shape
{
public:


    shape(float a )
    {
        set_a(a);
    }
    void set_a(float a)
    {
        this->a=a;
    }

    float get_a ()const
    {
        return a;
    }

    virtual void print() =0;

    ~shape()
    {

    }

protected:
    float a;


};

class twodimensional_shape:public shape

{

public:

    twodimensional_shape(float a , string name ):shape(a)
    {
        set_name(name);
    }

    void set_name (string name)
    {
        this->name=name;
    }

    string get_name()const
    {
        return name;
    }

    virtual  void print()

    {
        cout<<"The Name of Shape is :"<<get_name()<<endl;
        cout<<"The Area of  is :" <<Area()<<endl;

    }


    virtual float Area()const=0;

protected:
    string name;

};


class circle: public twodimensional_shape
{
public:

    circle(float a, string name ) :twodimensional_shape(a,name)
    {
        this->r=a;

    }

     float Area()const override
     {

       return r*r*3.14;
     }

    float get_r()const
    {
        return r;
    }


    virtual void print () override
    {
        twodimensional_shape::print();

        cout<<"The Radius of the Circle is:"<<get_r()<<endl;
    }


private:

    float r;

};

class  triangle :public twodimensional_shape
{
public:

    triangle (float a , string name , float  Height ): twodimensional_shape(a , name)
    {
        this-> Base=a;
        this->Height=Height;
    }

    float get_Base()const
    {
        return Base;
    }

    float get_Height()const
    {
        return Height;
    }


    float Area ()const override
    {
        return Height*Base *0.5;
    }

    virtual void print () override
    {
        twodimensional_shape ::print();
       cout<<"The Base of the Triangle is:"<<get_Base()<<endl;
       cout<<"The Height of the Triangle is:"<<get_Height()<<endl;

    }

private:

    float Base;
    float Height;


};


class threeodimensional_shape:public shape

{
public:
    threeodimensional_shape (float a , string name ):shape(a)
    {
        set_name(name);
    }

    void set_name (string name)
    {
        this->name=name;
    }

    string get_name()const
    {
        return name;
    }

    virtual  void print() override

    {
        cout<<"The Name of Shape is :"<<get_name()<<endl;
        cout<<"The Volume of  is :" <<Volume()<<endl;

    }

    virtual double Volume ()const =0;

protected:
    string name;
};

class sphere :public threeodimensional_shape
{
public:
    sphere(float a , string name ): threeodimensional_shape(a , name)
    {
        this->r=a;
    }

    float get_r()const
    {
        return r;
    }
    virtual double Volume ()const override
    {
        return (4.0 / 3.0) * 3.14 * r * r * r;

    }

    void print() override
    {
        threeodimensional_shape::print();
        cout<<"The Radius of the Sphere is:"<<get_r()<<endl;
    }
private:
    float r;

};
class tetrahedron :public threeodimensional_shape
{
public:

    tetrahedron(float a ,string name ):threeodimensional_shape(a , name){}

    virtual double Volume ()const override
    {
        return a*a*a /(sqrt(26));
    }

    void print() override
    {
        threeodimensional_shape::print();
        cout<<"The Side of the Tetrahedron is:"<<get_a()<<endl;
    }


};







int main()
{



    vector<shape*> shape{new circle(10,"Circle 1"),new triangle(9,"Triangle 1",12),
      new sphere ( 2,"Sphere 1"),new tetrahedron( 2 , "Tetrahedron 1")};

    for (const auto& s : shape) {
        s->print();
    }


    for (auto& s : shape) {
        delete s;
    }

    return 0;
}
