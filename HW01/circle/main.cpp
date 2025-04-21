#include <iostream>
#include "circle.h"
#include<execution>
using namespace std;

int main()
{


     int radius;
     int x_center;
     int y_center;
     try {
         cout<<"Please enter radius :"<<endl;
         cin>>radius;
     }
     catch (exception& e)
     {
         e.what();
     }

     cout<<"Please enter x of center :"<<endl;
     cin>>x_center;
     cout<<"Please enter y of center :"<<endl;
     cin>>y_center;

     circle c1(radius,x_center,y_center);
     c1.shift(2,2);
     c1.print();

    return 0;
}
