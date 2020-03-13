#include "polynom.hpp"
#include <iostream>
using namespace std;

int main()
{
   setlocale(LC_ALL, "Russian"); // русский язык
   Polynomial p1; 
   p1.output();
   Polynomial p2;
   p2.output();
   Polynomial p3(p1.get_degree() + p2.get_degree());
   p3 = p1 * p2;
   p3.output();
   Polynomial p4(p1.get_degree() * 3);
   p4 = p1 ^ 3; 
   p4.output();
};
