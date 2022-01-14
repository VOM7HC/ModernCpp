#include <array>
#include <iostream>

using namespace std;

int main()
{
    const auto display = [](const auto& items) {
        for (const auto& item : items) {
            cout << item << " ";
        }
    };

    const int values1[3] { 10, 20, 30 };

    const auto array1 = to_array(values1);

    cout << "array1.size() = " << array1.size() << "\narray1: ";
    display(array1);

    const auto array2 = to_array({ 1, 2, 3, 4 });
    cout << "\n\narray2.size() = " << array2.size() << "\narray2: ";
    display(array2);

    cout << endl;
}