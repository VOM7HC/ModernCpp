#include <iostream>

using namespace std;

int main()
{
    int total { 0 };
    int gradeCounter { 0 };
    int aCount { 0 };
    int bCount { 0 };
    int cCount { 0 };
    int dCount { 0 };
    int fCount { 0 };

    cout << "Enter the integer grades in the range 0 - 100";

    int grade;
    while (cin >> grade) {
        total += grade;
        ++gradeCounter;

        switch (grade / 10) {
        case 9:
            [[fallthrough]];
        case 10:
            ++aCount;
            break;
        case 8:
            ++bCount;
            break;
        case 7:
            ++cCount;
            break;
        case 6:
            ++dCount;
            break;
        default:
            ++fCount;
            break;
        }
    }
}