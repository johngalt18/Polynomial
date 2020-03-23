ude "polynom.hpp"
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm> 

using namespace std;

int main()
{
   ifstream is("coefs.txt");
   istream_iterator<double> start(is), end;
   vector<double> numbers(start, end);
   cout << "Read " << numbers.size() << " numbers" << std::endl;

   cout << "numbers read in:\n";
   copy(numbers.begin(), numbers.end(), ostream_iterator<double>(cout, " "));
   cout << endl;
   
   setlocale(LC_ALL, "Russian"); // русский язык
   Polynomial p1(3, {14, 4, 8, 5}); 
   p1.output();
   Polynomial p2(2, {2, 5, 3});
   p2.output();
   Polynomial p3(p1.get_degree() + p2.get_degree());
   p3 = p1 * p2;
   cout << "Результат перемножения полиномов: " << endl;
   p3.output();
   Polynomial p4(p1.get_degree() * 3);
   p4 = p1 ^ 2; 
   cout << "Результат возведения первого полинома в степень 2: " << endl;
   p4.output();
   Polynomial p5(10);
   p5 = p4.derivative();
   cout << "Производная текущего полинома: " << endl;
   p5.output();
   Polynomial p6(2);
   p6 = p5.antiderivative();
   cout << "Интеграл: " << endl;
   vector <double> s1({2, 5, 7});
   p6 = s1;
   p6.output();
   // cout << "Дискриминант полинома 2: " << p2.discriminant() << endl;
};
