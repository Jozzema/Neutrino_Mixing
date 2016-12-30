#include <iostream>
#include "neutrino.hpp"

using namespace std;

int main() {

   neutrino n1 = neutrino();

   cout << "Test: " << n1.debug() << endl;
   cout << "P = " << n1.probabilidad_oscilacion() << endl;
   
   return 0;
}
