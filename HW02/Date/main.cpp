#include <iostream>
#include "date.h"
#include<exception>
using namespace std;

int main()
{


    try {
        Date *d1 = new Date ();
        d1->print1();
        d1->sync();
        d1->print1();
        cout<<"-------------------------"<<endl;

        Date *d2= new Date(1357,11,22);
        d2->print1();
        d2->to_miladi();

        Date d3(1200,13,14);



    } catch (std::exception &e)

    {

        cout<<e.what();
    }



    return 0;
}
