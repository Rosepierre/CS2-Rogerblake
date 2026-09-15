#include <iostream>

using namespace std;

class Rectangle
{
    private: 
    int _side1 = 0;
    int _side2 = 0;

    public:
    //Constructor
   
    //setters

    void setside1(int s1)
    {
        _side1 = s1;
    }
    void setside2(int s2)
    {
        _side2 = s2;
    }

    //gettters

    int getside1()
    {
        return _side1;
    }

    int getside2()
    {
        return _side2;
    }
};

int main(int argc, char* argv[])
{
    Rectangle r1;
    Rectangle* r2 = new Rectangle;
    r1.setside1(42);
    r1.setside2(15);

    r2->setside1(123);
    r2->setside2(321);


    cout << r1.getside1() << endl;
    cout << r1.getside2() << endl;

    delete r2;
    return 0;
}


