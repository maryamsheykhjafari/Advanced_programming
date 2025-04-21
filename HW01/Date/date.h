#ifndef DATE_H
#define DATE_H

class Date
{
public:


    Date(int y=1 ,int m= 1 , int d=1);
  //set functions
    void set_y(int y);
    void set_m(int m);
    void set_d(int d);
  //get functions

    int get_y()const;
    int get_m()const;
    int get_d()const;


    void print1()const;
    void print2()const;

private :

    int y;
    int m;
    int d;


};

#endif // DATE_H
