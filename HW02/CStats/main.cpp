#include <iostream>
#include"Cstats.h"
#include<exception>
using namespace std;

int main()
{
    int num_s;
    cout << "Please Enter Number of Scors: "<<endl;
    try {
        cin>>num_s ;

        if(num_s <= 0)
            throw invalid_argument("The number can't be negative");


    }
    catch (exception& e)
    {
        cout<<e.what()<<endl;
    }

    try {

        float* scores=new float[num_s]  ;
        for (int i =0 ; i<num_s;i++)
        {

            cout<<"Please enter scors"<< i+1<<":"<<endl;

            cin>>scores[i];

            if (scores[i]<0 || scores[i] >20)
            {
                throw invalid_argument("score most be between 0-20");
            }



        }
        cstats<float , int > c1(scores,num_s);
        c1.print();
        cout << endl;
        c1.update();
        c1.print();

        cout << endl;

        cstats<int, long> c2(nullptr, 50);
        c2.rand_fill(0, 20);
        c2.update();
        c2.print();

    }
    catch (exception &e)
    {
         e.what();
     }


    return 0;
}
