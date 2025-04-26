#ifndef DATE_H
#define DATE_H
#include<ctime>
class Date
{
public:


    Date(int year=1400 ,int month= 12 , int day=12);


  //set functions
    void set_date(int year , int month , int day);
    void set_y(int year);
    void set_m(int month);
    void set_d(int day);
  //get functions

    int get_y()const;
    int get_m()const;
    int get_d()const;


    void print1()const;
    void print2()const;


    void from_miladi ();
    void  to_miladi  ();
    void sync();


private :

    int year;
    int month;
    int day;


};

#endif // DATE_H
