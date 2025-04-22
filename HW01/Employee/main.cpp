#include <iostream>
#include"employee.h"
using namespace std;

int main()
{
    employee emp ("hasn","moradi",6478,2500000,0);

    employee manag ("sina","moradi",5187,20000000,500000);
    emp.print_inf();
    cout<<"---------------------"<<endl;
    manag.print_inf();
    return 0;
}
