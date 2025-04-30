#include <iostream>

using namespace std;

class Tool {


public:

    Tool(int strength)
    {
        set_strength(strength);
    }

    void set_strength(int strength)
    {
        this->strength=strength;
    }

    int get_strength()const
    {
        return strength;
    }

    char get_type()const
    {
        return type;
    }



protected:

    int strength;
    char type;


};

class Scissors:public Tool
{
public:
    Scissors(int strength):Tool(strength)
    {
        Tool::type='s';
    }

    bool fight (Tool t)

    {

        float strengthMultiplier=1;

        if(t.get_type()=='r')
            strengthMultiplier /= 2;


        if (t.get_type()=='p')

          strengthMultiplier *= 2;

        return (strengthMultiplier* this->get_strength() > t.get_strength());

    }
};


class Paper:public Tool
{
public:

    Paper(int strength):Tool(strength)
    {
        Tool::type='p';
    }

    bool fight (Tool t)

    {
     float strengthMultiplier=1;
        if(t.get_type()=='s')

        strengthMultiplier /=2;
        if(t.get_type()=='r')

        strengthMultiplier *=2;

        return(strengthMultiplier *this->get_strength() >t.get_strength());
    }


};

class Rock:public Tool
{
public:
    Rock(int strength):Tool(strength)
    {

        Tool::type='r';

    }


    bool fight (Tool t)
    {

        float strengthMultiplier=1;
        if(t.get_type()=='p')

        strengthMultiplier /=2;
        if(t.get_type()=='s')

        strengthMultiplier *=2;

        return(strengthMultiplier *this->get_strength() >t.get_strength());

    }
};

int main() {


    Scissors s1(5);
    Paper p1(7);
    Rock r1(15);
    cout << s1.fight(p1) << p1.fight(s1) << endl;
    cout << p1.fight(r1) << r1.fight(p1) << endl;
    cout << r1.fight(s1) << s1.fight(r1) << endl;

    return 0;
}
