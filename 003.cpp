#include <format>
#include <iostream>

using namespace std;

int main()
{
    string student { "Alice" };
    int grade { 87 };

    cout << format("{}'s grade is {}", student, grade) << endl;
}