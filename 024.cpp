#pragma once
#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <span>
#include <sstream>
#include <stdexcept>
#include <utility>

using namespace std;

class MyArray final {
    friend istream& operator>>(std::istream& in, MyArray& a);

    friend void swap(MyArray& a, MyArray& b) noexcept;

public:
    explicit MyArray(size_t size);

    explicit MyArray(initializer_list<int> list);

    MyArray(const MyArray& original);
    MyArray& operator=(const MyArray& right);

    MyArray(MyArray&& original) noexcept;
    MyArray& operator=(MyArray&& right) noexcept;

    ~MyArray();

    size_t size() const noexcept { return m_size; };
    std::string toString() const;

    bool operator==(const MyArray& right) const noexcept;

    int& operator[](size_t index);

    const int& operator[](size_t index) const;

    explicit operator bool() const noexcept { return size() != 0; }

    MyArray& operator++();

    MyArray operator++(int);

    MyArray& operator+=(int value);

private:
    size_t m_size { 0 };
    unique_ptr<int[]> m_ptr;
};

std::ostream& operator<<(std::ostream& out, const MyArray& a);

MyArray::MyArray(size_t size)
    : m_size { size }
    , m_ptr { make_unique<int[]>(size) }
{
    cout << "MyArray(size_t) constructor\n";
}

MyArray::MyArray(initializer_list<int> list)
    : m_size { list.size() }
    , m_ptr { make_unique<int[]>(list.size()) }
{
    cout << "MyArray(initializer_list) constructor\n";

    copy(begin(list), end(list), m_ptr.get());
}

MyArray::MyArray(const MyArray& original)
    : m_size { original.size() }
    , m_ptr { make_unique<int[]>(original.size()) }
{
    cout << "MyArray copy constructor\n";

    const span<const int> source { original.m_ptr.get(), original.size() };
    copy(begin(source), end(source), m_ptr.get());
}

MyArray& MyArray::operator=(const MyArray& right)
{
    cout << "MyArray copy assignment operator\n";
    MyArray temp { right };
    swap(*this, temp);
    return *this;
}

MyArray::MyArray(MyArray&& original) noexcept
    : m_size { exchange(original.m_size, 0) }
    , m_ptr { std::move(original.m_ptr) }
{
    cout << "MyArray move constructor\n";
}

MyArray& MyArray::operator=(MyArray&& right) noexcept
{
    cout << "MyArray move assignment operator\n";

    if (this != &right) {
        m_size = std::exchange(right.m_size, 0);
        m_ptr = std::move(right.m_ptr);
    }

    return *this;
}

MyArray::~MyArray()
{
    cout << "MyArray destructor\n";
}

string MyArray::toString() const
{
    const span<const int> items { m_ptr.get(), m_size };
    ostringstream output;
    output << "{";

    for (size_t count { 0 }; const auto& item : items) {
        ++count;
        output << item << (count < m_size ? ", " : "");
    }

    output << "}";
    return output.str();
}

bool MyArray::operator==(const MyArray& right) const noexcept
{
    const span<const int> lhs { m_ptr.get(), size() };
    const span<const int> rhs { right.m_ptr.get(), right.size() };
    return equal(begin(lhs), end(lhs), begin(rhs), end(rhs));
}

int& MyArray::operator[](size_t index)
{
    if (index >= m_size) {
        throw out_of_range { "Index out of range" };
    }

    return m_ptr[index];
}

const int& MyArray::operator[](size_t index) const
{
    if (index >= m_size) {
        throw out_of_range { "Index out of range" };
    }

    return m_ptr[index];
}

MyArray& MyArray::operator++()
{
    const span<int> items { m_ptr.get(), m_size };
    for_each(begin(items), end(items), [](auto& item) { ++item; });
    return *this;
}

MyArray MyArray::operator++(int)
{
    MyArray temp(*this);
    ++(*this);
    return temp;
}

MyArray& MyArray::operator+=(int value)
{
    const span<int> items { m_ptr.get(), m_size };
    for_each(begin(items), end(items),
        [value](auto& item) { item += value; });
    return *this;
}

istream& operator>>(istream& in, MyArray& a)
{
    span<int> items { a.m_ptr.get(), a.m_size };

    for (auto& item : items) {
        in >> item;
    }

    return in;
}

ostream& operator<<(ostream& out, const MyArray& a)
{
    out << a.toString();
    return out;
}

void swap(MyArray& a, MyArray& b) noexcept
{
    std::swap(a.m_size, b.m_size);
    a.m_ptr.swap(b.m_ptr);
}
