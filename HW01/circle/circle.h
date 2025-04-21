#ifndef CIRCLE_H
#define CIRCLE_H

class circle
{
public:
    circle( float r=0  , int x=0 , int y=0);

 //set functions
    void set_r(float r);
    void set_center(int x , int y);

 //get functions

    float get_r( )const;
    int get_x()const;
    int get_y()const;



    float perimeter(float r);
    float area(float r);
    void shift (int a, int b);
    void print ();


 private:

    float r;
    int x,y;
};

#endif // CIRCLE_H
