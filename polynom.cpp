#include "polynom.hpp"
#include <iostream>
using namespace std;

int main()
{
   setlocale(LC_ALL, "Russian"); // русский язык
   Polynomial p1(3, {14, 4, 8, 5}); 
   p1.output();
   Polynomial p2(2, {5, 6, 12});
   p2.output();
   Polynomial p3(p1.get_degree() + p2.get_degree());
   p3 = p1 * p2;
   p3.output();
   Polynomial p4(p1.get_degree() * 3);
   p4 = p1 ^ 2; 
   p4.output();
   cout << "Дискриминант полинома: " << p4.discriminant() << endl;
};
