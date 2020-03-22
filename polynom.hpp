#pragma once
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Polynomial{

private:
	vector <double> coefs; // указатель на массив коэффициентов
	int degree; // степень полинома
public:
	Polynomial(); // конструктор по умолчанию
	Polynomial(int); // конструктор с параметрами (степень)
	Polynomial(int, vector <double>); // конструктор с параметрами (степень и коэффициенты)
	Polynomial(const Polynomial&); // копирующий конструктор
	~Polynomial(); // деструктор

	int get_degree(); // получение степени

	void input(); // заполнение полинома
	void output(); // вывод полинома

	Polynomial & operator= (const Polynomial & p); // присваиваниe
        Polynomial & operator= (vector <double> vec);
	friend Polynomial operator* (const Polynomial&, int); // умножение полинома на число
	friend Polynomial operator* (const Polynomial&, const Polynomial&); // умножение полинома на полином
	friend Polynomial operator^ (const Polynomial&, int); // возведение в степень

	Polynomial derivative(); // производная	
	Polynomial antiderivative(); // первоообразная

	double discriminant(); // дискриминант многочлена
};


Polynomial::Polynomial() 
   { 
      // тривиальный полином
      setlocale(LC_ALL, "Russian"); // русский язык
      degree = 1;
      coefs.reserve(1); // выделить место в памяти для массива
      coefs[0]=0;
   }
   
Polynomial::Polynomial(int deg) 
   {   
      degree = deg; // степень
      coefs.reserve(degree+1); // выделить место в памяти для массива
      for (int i = 0; i < degree+1; i++)
         coefs[i] = 1; // коэффициенты = 1
   }


Polynomial::Polynomial(int deg, vector <double> vec) 
   { 
      degree = deg; // степень
      coefs.reserve(degree+1); // выделить место в памяти для массива
      for (int i = 0; i < degree+1; i++)
         coefs[i] = vec[i];
   }

Polynomial::~Polynomial() 
   {
   }

void Polynomial::input() 
   { 
      cout << "Вводим коэффициенты полинома степени " << degree << ": ";
      for (int i = 0; i < degree + 1; i++)
         cin >> coefs[i];
   }

int Polynomial::get_degree() 
   { 
      return degree;
   }
   
void Polynomial::output()
   {
      cout << "Полином: ";
      if (degree == 1)
      {
         cout << 0;
      }
      else
      {
         for (int i = 0; i < degree-1; i++)
            cout << coefs[i] << "*x^" << degree - i << "+";
         cout << coefs[degree - 1] << "*x+" << coefs[degree] << endl;
      }
   } 

Polynomial & Polynomial::operator= (const Polynomial& p) 
   {
      coefs.clear();
      degree = p.degree;
      for (int i = 0; i < degree+1; ++i)
         coefs[i] = p.coefs[i];
      return *this;
   }
Polynomial & Polynomial::operator= (vector <double> vec)
    {
        degree = vec.size() - 1;
        coefs.resize(degree+1);
        for (int i = 0; i < degree+1; ++i)
            coefs[i] = vec[i];
        return *this;
    }

Polynomial operator* (const Polynomial& p, int mn)
   { 
      vector <double> vec;
      for (int i = 0; i < p.degree+1; i++)
         vec[i] = p.coefs[i] * mn; // умножаем на число
      Polynomial pm(p.degree, vec);
      return pm;
   }

Polynomial operator* (const Polynomial& p1, const Polynomial& p2)
   { 
      int deg = p1.degree + p2.degree;
      vector <double> vec(deg + 1); // динамический массив размера
      for (int i = 0; i < p1.degree + 1; i++)
         for (int j = 0; j < p2.degree + 1; j++)
            vec[i+j] += p1.coefs[i] * p2.coefs[j]; // умножаем на полином
      Polynomial pm(deg, vec);
      return pm;
   }
   
Polynomial operator^ (const Polynomial& p, int deg) 
   {
      int new_degree = p.degree;
      
      vector < vector <double>> vec(deg);
      vec[0].resize(deg+1);
      
      for (int i = 0; i < new_degree + 1; i++)
         vec[0][i] = p.coefs[i];

      for (int k = 1; k < deg; k++) 
      {
         new_degree += p.degree;
         vec[k].resize(new_degree+1);
         for (int i = 0; i < new_degree + 1; i++)
            vec[k][i] = 0;
         
         for (int i = 0; i < new_degree - p.degree + 1; i++)
            for (int j = 0; j < p.degree + 1; j++)
               vec[k][i + j] += vec[k-1][i] * p.coefs[j]; // умножаем на полином
      }

      Polynomial pm(new_degree, vec[deg-1]);
      return pm;
   }

Polynomial Polynomial::derivative() 
   {
      vector <double> vec(this->degree);
      for (int i = 0; i < this->degree; i++)
         vec[i] = this->coefs[i] * (this->degree - i); // умножаем на число
      Polynomial pm(this->degree-1, vec);
      return pm;
   }
   
Polynomial Polynomial::antiderivative() 
   {
      vector <double> vec(this->degree+2);
      for (int i = 0; i < this->degree+1; i++)
         vec[i] = this->coefs[i] / (this->degree - i + 1); // умножаем на число
      vec[this->degree + 1] = 1;
      Polynomial pm(this->degree+1, vec);
      return pm;
   }

double Polynomial::discriminant() 
   {
   double d = pow(this->coefs[0], this->degree * 2 - 2);
   for (int i = 0; i < this->degree; i++)
      for (int j = i + 1; j < this->degree + 1; j++)
         d *= pow(this->coefs[i] - this->coefs[j], 2);
   return d;
   }
