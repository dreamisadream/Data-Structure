#include "Polynomial.h"

#include <iostream>

using namespace std;

int main()
{
    Polynomial A;
    Polynomial B;
    Polynomial C = A + B;
    C.showPoly();
    return 0;
}
