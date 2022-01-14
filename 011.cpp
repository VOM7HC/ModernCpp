#include <array>
#include <iostream>
using namespace std;

constexpr size_t rows { 2 };
constexpr size_t columns { 3 };
void printArray(const array<array<int, columns>, rows>& a);

int main()
{
    const array<array<int, columns>, rows> array1 { 1, 2, 3, 4, 5, 6 };

    cout << "Values in array1 by row are:" << endl;
    printArray(array1);
}

void printArray(const array<array<int, columns>, rows>& a)
{
    for (auto const& row : a) {

        for (auto const& element : row) {
            cout << element << ' ';
        }

        cout << endl;
    }
}