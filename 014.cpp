#include <iostream>
#include <vector>   
#include <stdexcept>

using namespace std;

int main() {
   vector<int> integers1(7); 
               
   vector<int> integers2{integers1};
   integers1 = integers2;
}