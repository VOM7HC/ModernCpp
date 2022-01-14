#include <algorithm>
#include <array>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    constexpr size_t arraySize { 7 };
    array<string, arraySize> colors {
        "red",
        "orange",
        "yellow",
        "green",
        "blue",
        "indigo",
        "violet"
    };

    cout << "Unsorted colors array:\n";
    for (string color : colors) {
        cout << color << " ";
    }

    sort(begin(colors), end(colors));

    cout << "Sorted colors array:\n";
    for (string color : colors) {
        cout << color << " ";
    }
}