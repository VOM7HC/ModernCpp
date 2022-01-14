#include <iostream>
#include <memory>
using namespace std;

class Integer {
public:
    Integer(int i)
        : value { i }
    {
        cout << "Constructor for Integer " << value << "\n";
    }

    ~Integer()
    {
        cout << "Destructor for Integer " << value << "\n";
    }

    int getValue() const { return value; };

private:
    int value { 0 };
};

int main()
{
    cout << "Creating a unique_ptr object that points to an Integer\n";

    auto ptr { make_unique<Integer>(7) };

    cout << "Integer value: " << ptr->getValue()
         << "\n\nMain ends\n";
}