#include <array>
#include <format>
#include <iostream>

using namespace std;

int main()
{
    array<int, 5> n { 32, 27, 64, 18, 95 };

    cout << format("{}{:>10}\n", "Element", "Value");

    for (size_t i { 0 }; i < n.size(); ++i) {
        cout << format("{:>7}{:>10}\n", i, n[i]);
    }

    cout << format("\n{}{:>10}\n", "Element", "Value");

    for (size_t i { 0 }; i < n.size(); ++i) {
        cout << format("{:>7}{:>10}\n", i, n.at(i));
    }

    
    for (const int item : n) {
        cout << item << " ";
    }

    cout << "\nitems after modification: ";
    for (int& itemRef : n) {
        itemRef *= 2;
    }
}