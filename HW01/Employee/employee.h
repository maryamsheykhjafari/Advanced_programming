#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
using namespace std;
class employee
{
public:
    string  name;
    string lname;
    int id;
    employee(string name , string lname ,int id, float Monthlyـsalary, float Management_fee=0)
    {
        this->name=name;
        this->lname=lname;
        this->id=id;
        set_ms(Monthlyـsalary) ;
        set_mf(Management_fee) ;
    }

 //set functions
    void set_ms(float Monthlyـsalary)
    {
        this->Monthlyـsalary=Monthlyـsalary;
    }

    void set_mf(float Management_fee)
    {
        this->Management_fee=Management_fee;
    }

 //get functions
    float get_ms()const
    {
        return  Monthlyـsalary;
    }

    float get_mf()const
    {
        return  Management_fee;
    }

    void print_inf()
    {

        cout<<"Name :"<< name<<endl;
        cout<<"Last name :"<< lname<<endl;
        cout<<"ID :"<<id<<endl;
        cout<<"Total salary:" <<get_mf()+get_ms()<<endl;
    }

private:
    float Monthlyـsalary ;
    float Management_fee ;


};
#endif // EMPLOYEE_H
