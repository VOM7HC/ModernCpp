#include <iostream>

using namespace std;

double mypow(double x, long long n)
{
    if (n > 0) [[likely]]
        return x * pow(x, n - 1);
    else [[unlikely]]
        return 1;
}

int main()
{
    double a{ 2 };
    double result{ mypow(a, 2) };
    cout << result;
}