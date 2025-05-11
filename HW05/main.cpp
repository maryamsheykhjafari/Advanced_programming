// shared_ptr-examples.cpp
// The following examples assume these declarations:
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;


struct MediaAsset
{
    virtual ~MediaAsset() = default; // make it polymorphic
};

struct Song : public MediaAsset
{
    std::string artist;
    std::string title;
    Song(const std::string& artist_, const std::string& title_) :
        artist{ artist_ }, title{ title_ }
    {
        std::cout << "Song " << artist_ << " - " << title_ << " constructed\n";
    }

    ~Song()
    {
        std::cout << "~Song " << artist << " - " << title << " destructed\n";
    }

    void print()
    {
        cout<<"Artist name is :"<<endl;
        cout<<"Title is :"<<endl;
    }
};

struct Photo : public MediaAsset
{
    std::string date;
    std::string location;
    std::string subject;
    Photo(
        const std::string& date_,
        const std::string& location_,
        const std::string& subject_) :
        date{ date_ }, location{ location_ }, subject{ subject_ } {}
};

using namespace std;

//Song example
void example1()
{
    //TODO: کامل کنید. اسم خواننده و آلبوم را خودتان انتخاب کنید
    auto sp1 = make_shared<Song>("sorena","Gavazn");


    //یک خواننده دیگر
    shared_ptr<Song> sp2(new Song ("falling in reverse","popular monster") );


    shared_ptr<Song> sp3(nullptr);
    //Equivalent to: shared_ptr<?> sp3;

    //و یک خواننده دیگر
    sp3 = make_shared<Song>("falling in reverse", "the drug in me is you ");


    //Initialize with copy constructor. make it equal to sp1
    auto sp4=sp1;

    //Initialize via copy assignment. make it equal to sp2
    auto sp5 =sp2;

    // swap pointers as well as ref counts.
    sp1.swap(sp2);
    sp1->print();
    sp2->print();
}

void example2()
{
    vector<shared_ptr<Song>> v
    {
        //Create at least 3 shared_ptr of different Songs
        //یکی از صوتها حتما به نام افتخاری باشد. در ادامه لازم است

        make_shared<Song>("Mohammad Reza Shajarian","Bidad"),
        make_shared<Song>("Dariush","Be Man Nagoo Dooset Daram"),
        make_shared<Song>("Alireza Eftekhari","Niloufaraneh")

    };



    //Print all songs using for loop
    for(size_t i ; i<v.size();i++)
    {
        v[i]->print();
    }

        //خروجی کد زیر را بررسی کنید. این کد چه کاری انجام می دهد
        vector<shared_ptr<Song>> v2;
    remove_copy_if(v.begin(), v.end(), back_inserter(v2), [] (shared_ptr<Song> s)
                   {
                       return s->artist.compare("Eftekhari") == 0;
                   });

    for (const auto& s : v2)
    {
        cout << s->artist << ":" << s->title << endl;
    }
}

//مثال زیر را تکمیل کنید و بیان کنید چه کاری انجام می دهد؟
void example3()
{
    vector<shared_ptr<MediaAsset>> assets {
    make_shared<Song>("Shoore Eshgh", "Alireza Eftekhari"),
    make_shared<Song>("Imagine", "John Lennon"),
    make_shared<Photo>("1402-01-17", "Hossein Khosravi", "Quds Day in Shahrood")

    };

    vector<shared_ptr<MediaAsset>> photos;

    copy_if(assets.begin(), assets.end(), back_inserter(photos), [] (shared_ptr<MediaAsset> p) -> bool
            {
                // Use dynamic_pointer_cast to test whether
                // element is a shared_ptr<Photo>.
                shared_ptr<Photo> temp = dynamic_pointer_cast<Photo>(p);
                return temp.get() != nullptr;
            });

    for (const auto&  p : photos)
    {
        // We know that the photos vector contains only
        // shared_ptr<Photo> objects, so use static_cast.
        cout << "Photo location: " << (static_pointer_cast<Photo>(p))->location << endl;
    }
}

int main()
{
    example1();
    example2();
    example3();
}
