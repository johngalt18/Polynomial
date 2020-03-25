#include "polynom.hpp"
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

int main()
{
   setlocale(LC_ALL, "Russian"); // русский язык

   ifstream infile("data.txt");
   string line;
   vector <double> numbers;
   vector <vector <double>> coefs(2); // выделил память под 2 вектора под коэф-ты полиномов

   Polynomial p1;
   Polynomial p2;

   int poly_num = 0;
   while (getline(infile, line))
   {
       /* чтение из файла в вектор строк, из него сохранение в буфферный флот вектор
       и запись коэффициентов в вектор за пределами while */
       istringstream iss(line);

       copy(istream_iterator<double>(iss),
       istream_iterator<double>(),
       back_inserter(numbers));

       coefs[poly_num].resize(numbers.size());

       for (unsigned int coef=0; coef<numbers.size(); coef++)
           coefs[poly_num][coef] = numbers[coef];

       numbers.clear();
       poly_num += 1;
   }
   infile.close();

   p1 = coefs[0];
   p2 = coefs[1];

   p1.output();
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
   p6.output();
};
