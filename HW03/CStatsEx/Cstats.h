#ifndef CSTATS_H
#define CSTATS_H
#include<iostream>
#include <math.h>
#include<algorithm>
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

     virtual ~cstats()

    {
        if (length >0 && data !=nullptr)
        {
            delete[] data;
            data = nullptr;
            length = 0;}
    }


     virtual  void  update()

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

    virtual  void print()


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




protected:

    _T *data;
    _SZ length  ;
    float   last_mean;
    float last_std;



};
template<typename _T,typename _SZ>
class  CStatsEx: public cstats<_T,_SZ>
 {

public:
     CStatsEx(string name)
    {
         this->name=name;
    }
     CStatsEx(float* data, int length, string name) :cstats<_T,_SZ> (data,length) ,name(name){};


    virtual void update()
    {

         cstats<_T,_SZ>::update();

        last_max=*max_element(this->data ,this->data +this->length);
         last_min=*min_element(this->data,this->data +this->length);

    }


    void sort()
    {
        std::sort(this->data,this->data +this->length)  ;

    }


     virtual void print()
    {
        cstats<_T,_SZ>::print();
        cout << "Object Name: " << name << endl;
        cout << "Min Element: " << last_min<< endl;
        cout << "Max Element: " << last_max << endl;
    }





 private:
     string name;
     int last_min;
     int last_max;

 };
template class cstats<int, int>;
template class cstats<float, int>;
template class cstats<int, long>;
template class cstats<float, long>;
template class cstats<long, long>;


#endif // CSTATS_H
