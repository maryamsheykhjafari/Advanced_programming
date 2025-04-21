#include <iostream>
#include "date.h"
using namespace std;

int main()
{
    Date d1(1401,11,30);
    d1.print1();
    d1.print2();


    Date* d2 = new Date(1400, 11, 30);
    d2->print1();
    d2->print2();
    delete d2;

    return 0;
}
