#include <cmath>
#include <format>
#include <iostream>

using namespace std;

int main()
{
    double principal { 1000.00 };
    double rate { 0.05 };

    cout << format("Initial principal: {:>7.2f}\n", principal)
         << format("    Interest rate: {:>7.2f}\n", rate);

    cout << format("\n{}{:>20}\n", "Year", "Amount on deposit");

    for (int year { 1 }; year <= 10; ++year) {
        double amount { principal * pow(1.0 + rate, year) };
        cout << format("{:>4d}{:>20.2f}\n", year, amount);
    }
}
