#include <iostream>
using namespace std;

class Base {
public:
    virtual void show(){}
};

class Derived : public Base {
public:
    void show()
    {
        cout << "In Derived \n";
    }
};

int main(void)
{
    Base *bp = new Derived;  //Upcasting

    // RUN-TIME POLYMORPHISM
    bp->show();

    return 0;
}
/* Output */
// In Derived

