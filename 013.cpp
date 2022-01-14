#include <array>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>

using namespace std;

int main()
{
    auto showValues = [](auto& values, const string& message) {
        cout << message << ": ";

        for (auto value : values) {
            cout << value << " ";
        }

        cout << endl;
    };

    auto values1 = views::iota(1, 11);
    showValues(values1, "Generate integers 1-10");

    auto values2 = values1 | views::filter([](const auto& x) { return x % 2 == 0; });
    showValues(values2, "Filtering even integers");

    auto values3 = values2 | views::transform([](const auto& x) { return x * x; });
    showValues(values3, "Mapping even integers to squares");

    auto values4 = values1 | views::filter([](const auto& x) { return x % 2 == 0; })
                           | views::transform([](const auto& x) { return x * x; });
    showValues(values4, "Squares of even integers");

    cout << "Sum the squares of the even integers from 2-10: " << accumulate(begin(values4), end(values4), 0) << endl;

    array<int, 10> numbers { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    auto values5 = numbers | views::filter([](const auto& x) { return x % 2 == 0; })
                           | views::transform([](const auto& x) { return x * x; });
    showValues(values5, "Squares of even integers in array numbers");
}
