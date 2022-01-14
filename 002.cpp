#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1 { "happy" };
    string s2 { "birthday" };
    string s3;

    cout << "s1: " << s1 << " ; length: " << s1.length() << "\n"
         << "s2: " << s2 << " ; length: " << s2.length() << "\n"
         << "s3: " << s3 << " ; length: " << s3.length();

    boolalpha;

    cout << "s1 starts with \"ha\": " << s1.starts_with("ha") << "\n";
    cout << "s2 starts with \"ha\": " << s2.starts_with("ha") << "\n";

    cout << "s1 ends with \"ay\": " << s1.ends_with("ay") << "\n";
    cout << "s1 ends with \"ay\": " << s1.ends_with("ay") << "\n";
}