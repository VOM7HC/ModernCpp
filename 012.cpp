#include <array>
#include <iostream>
#include <numeric>
using namespace std;

int multiply(int x, int y)
{
    return x * y;
}

int main()
{
    constexpr size_t arraySize { 5 };
    array<int, arraySize> integers { 1, 2, 3, 4, 5 };

    cout << "Product of integers: "
         << accumulate(begin(integers), end(integers), 1, multiply) << endl;

    cout << "Product of integers with a lambda: "
         << accumulate(begin(integers), end(integers), 1,
                [](const auto& x, const auto& y) { return x * y; })
         << endl;
}