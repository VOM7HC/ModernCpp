#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>

using namespace std;

int main()
{
    default_random_engine engine{ static_cast<uint32_t>(time(0)) };
    const uniform_int_distribution<int> randomInt{ 1, 6 };

    for (int counter{ 1 }; counter <= 10; ++counter) {
        cout << randomInt(engine) << " ";
    }

    cout << endl;
}