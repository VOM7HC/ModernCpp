#include <cassert>
#include <iostream>
#include <string>
#include <variant>

int main()
{
    std::variant<int, float> v, w;
    v = 42;
    int i = std::get<int>(v);
    w = std::get<int>(v);
    w = std::get<0>(v);
    w = v;
    v = 4.2f;
    float j = std::get<float>(v);
}