#include <format>
#include <iostream>
#include <string>
#include <string_view>
using namespace std;

int main()
{
    string s1 { "red" };
    string s2 { s1 };
    string_view v1 { s1 };
    cout << format("s1: {}\ns2: {}\nv1: {}\n\n", s1, s2, v1);

    s1.at(0) = 'R';
    cout << format("s1: {}\ns2: {}\nv1: {}\n\n", s1, s2, v1);

    cout << format("s1 == v1: {}\ns2 == v1: {}\n\n", s1 == v1, s2 == v1);

    v1.remove_prefix(1);
    v1.remove_suffix(1);
    cout << format("s1: {}\nv1: {}\n\n", s1, v1);

    string_view v2 { "C-string" };
    cout << "The characters in v2 are: ";
    for (const char c : v2) {
        cout << c << " ";
    }

    cout << format("\n\nv2.size(): {}\n", v2.size());
    cout << format("v2.find('-'): {}\n", v2.find('-'));
    cout << format("v2.starts_with('C'): {}\n", v2.starts_with('C'));
}