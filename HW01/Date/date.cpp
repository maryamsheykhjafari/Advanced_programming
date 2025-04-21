#include "date.h"
#include<iostream>
using namespace std;
Date::Date(int y ,int m , int d)
{
    set_y(y);
    set_m(m);
    set_d(d);
}

void Date::set_y(int y)
{
    this->y=y;
}

void Date::set_m(int m)
{
    this->m=m;
}

void Date::set_d(int d)
{
    this->d=d;
}

int Date::get_y() const
{
    return y;
}

int Date::get_m() const
{
    return m;
}

int Date::get_d() const
{
    return d;
}

void Date::print1() const
{

    cout<<get_y()<<"-"<<get_m()<<"-"<<get_d()<<endl;

}

void Date::print2() const
{
    cout<<get_y()<<"-"  ;
    switch (get_m())
    {
    case 1:
        cout << "Farvardin";
        break;
    case 2:
        cout << "Ordibehsht" ;
        break;
    case 3:
        cout << "khordad";
        break;
    case 4:
        cout << "tir" ;
        break;
    case 5:
        cout << "mordad" ;
        break;
    case 6:
        cout << "shahrivar" ;
        break;
    case 7:
        cout << "mehr" ;
        break;
    case 8:
        cout << "aban" ;
        break;
    case 9:
        cout << "azar"  ;
        break;
    case 10:
        cout << "dey" ;
        break;
    case 11:
        cout << "bahman" ;
        break;
    case 12:
        cout << "esfand";
        break;
    default:
        cout << "Invalid month";
        break;
    }

    cout<< "-"<< get_d()<< endl;
}
