#include "date.h"
#include<iostream>
#include<stdexcept>
#include<ctime>
using namespace std;
Date::Date(int year ,int month , int day)
{
    set_date(year , month , day) ;
}

void Date::set_date(int year , int month , int day)
{

    set_y(year);
    set_m(month);
    set_d(day);

}

void Date::set_y(int year)
{
    this->year=year;
}

void Date::set_m(int month)
{
    if (month>0 && month<=12)
        this->month=month;
    else

    throw invalid_argument ("Month have to be between 1-12");;
}

void Date::set_d(int day)
{    if (day>0 && day<=31)
        this->day=day;
    else

    throw invalid_argument ("Day have to be between 1-31");

}

int Date::get_y() const
{
    return year;
}

int Date::get_m() const
{
    return month;
}

int Date::get_d() const
{
    return day;
}

void Date::print1() const
{

    cout<<get_y()<<"-"<<get_m()<<"-"<<get_d()<<endl;

}

void Date::from_miladi() {
    int gy = year;
    int gm = month;
    int gd = day;

    int g_days_in_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int j_days_in_month[12] = {31,31,31,31,31,31,30,30,30,30,30,29};

    // محاسبه سال کبیسه
    bool gy_leap = ((gy % 4 == 0 && gy % 100 != 0) || (gy % 400 == 0));
    if (gy_leap) g_days_in_month[1] = 29;

    // تعداد روز از مبدا
    int gy_days = (365 * (gy - 1600)) + ((gy - 1600 + 3) / 4) - ((gy - 1600 + 99) / 100) + ((gy - 1600 + 399) / 400);
    for (int i = 0; i < gm - 1; ++i)
        gy_days += g_days_in_month[i];
    gy_days += gd - 1;

    int j_days = gy_days - 79;

    int j_np = j_days / 12053;
    j_days %= 12053;

    int jy = 979 + 33 * j_np + 4 * (j_days / 1461);
    j_days %= 1461;

    if (j_days >= 366) {
        jy += (j_days - 1) / 365;
        j_days = (j_days - 1) % 365;
    }

    int jm = 0;
    for (int i = 0; i < 12 && j_days >= j_days_in_month[i]; ++i) {
        j_days -= j_days_in_month[i];
        jm++;
    }

    int jd = j_days + 1;

    cout << "Jalali Date: " << jy << "-" << jm + 1 << "-" << jd << endl;
}

void Date::to_miladi()
{
    int jy = year;
    int jm = month;
    int jd = day;

    int g_days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int j_days_in_month[] = {31,31,31,31,31,31,30,30,30,30,30,29};

    jy -= 979;
    int j_day_no = 365 * jy + (jy / 33) * 8 + ((jy % 33 + 3) / 4);
    for (int i = 0; i < jm - 1; ++i)
        j_day_no += j_days_in_month[i];
    j_day_no += jd - 1;

    int g_day_no = j_day_no + 79;

    int gy = 1600 + 400 * (g_day_no / 146097);
    g_day_no %= 146097;

    bool leap = true;
    if (g_day_no >= 36525) {
        g_day_no--;
        gy += 100 * (g_day_no / 36524);
        g_day_no %= 36524;

        if (g_day_no >= 365) g_day_no++;
        else leap = false;
    }

    gy += 4 * (g_day_no / 1461);
    g_day_no %= 1461;

    if (g_day_no >= 366) {
        leap = false;
        g_day_no--;
        gy += g_day_no / 365;
        g_day_no %= 365;
    }

    int gm = 0;
    int gd = 0;
    for (int i = 0; i < 12; ++i)
    {
        int days_in_month = g_days_in_month[i];
        if (i == 1 && leap) days_in_month++;
        if (g_day_no < days_in_month)
        {
            gm = i + 1;
            gd = g_day_no + 1;
            break;
        }
        g_day_no -= days_in_month;
    }

    cout << "Gregorian Date: " << gy << "-" << gm << "-" << gd << endl;
}

void Date::sync()
{
    time_t t = time(NULL);//get system time
    tm current_time;
    localtime_s(&current_time, &t);//convert to local time
    int year = current_time.tm_year+1900;
    int month = current_time.tm_mon+1;
    int day= current_time.tm_mday;

    set_y(year);
    set_m(month);
    set_d(day);
}


void Date::print2() const
{
    cout<<get_y()<<"-"  ;
    switch (get_m())
    {
    case 1:
        cout << "Farvardin";
        break;
    case 2:
        cout << "Ordibehsht" ;
        break;
    case 3:
        cout << "khordad";
        break;
    case 4:
        cout << "tir" ;
        break;
    case 5:
        cout << "mordad" ;
        break;
    case 6:
        cout << "shahrivar" ;
        break;
    case 7:
        cout << "mehr" ;
        break;
    case 8:
        cout << "aban" ;
        break;
    case 9:
        cout << "azar"  ;
        break;
    case 10:
        cout << "dey" ;
        break;
    case 11:
        cout << "bahman" ;
        break;
    case 12:
        cout << "esfand";
        break;
    default:
        cout << "Invalid month";
        break;
    }

    cout<< "-"<< get_d()<< endl;
}
