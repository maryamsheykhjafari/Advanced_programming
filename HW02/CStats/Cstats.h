#ifndef CSTATS_H
#define CSTATS_H
#include<iostream>
#include <math.h>
using namespace std;
template <typename _T ,  typename _SZ>

class cstats
{
public:
    cstats()
     {
        data=nullptr;
        length=0;

    }

    cstats(_T *data , _SZ length)
    {
        this-> last_mean=0;
        this->last_std=0;
        this ->length=length;

        if(data == nullptr)
        {
            this->data = new _T[length]  ;
            for (size_t i =0 ;i < length; i++)

                this-> data[i]=0;
        }
        else
        {
            this->data = data;
        }


    }

    ~cstats()

    {
        if (length >0 && data !=nullptr)
        {
            delete[] data;
            data = nullptr;
            length = 0;}
    }


       void  update()

    {

        //MEAN
        float sum=0;
        int STD=0;


        for (int i =0; i <this->length ; i++)
        {
          sum +=data[i];
        }

        this->last_mean= sum/ this->length;


        //Standard Deviation

        for (int  i = 0; i < this->length; i++)
        {
            STD += pow(this->data[i] - this->last_mean, 2);
        }
        this->last_std = sqrt(STD / this->length);





    }
       //Rand fill

    void rand_fill(int min , int max)
    {
        for (int i ; i <length ;i++)
        {
         this->data[i] = rand() % (max - min + 1) + min;
        }

    }

    void print()


    { cout << "Data is :"<<endl;

        for (size_t i =0 ; i<this->length;i++)
        {
            cout<<data[i]<<endl;
        }
        cout<<"---------------------"<<endl;

        cout<<"Length of Array: "<<this->length<<endl;
        cout << "Mean of Array: " << this->last_mean << endl;
        cout << "Standard Division of Array: " << this->last_std << endl;
    }




private:

    _T *data;
    _SZ length  ;
    float   last_mean;
    float last_std;



};

template class cstats<int, int>;
template class cstats<float, int>;
template class cstats<int, long>;
template class cstats<float, long>;
template class cstats<long, long>;


#endif // CSTATS_H
