#include <vector>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Polynom
{
   private:
      unsigned int degree;
      vector <float> coefficients;
   public:
      Polynom();
      Polynom(unsigned int deg);
      Polynom(unsigned int deg, vector <float> coefs);
      unsigned int get_degree();
      void print_poly(); 
      float get_coeff(unsigned int i);
      Polynom(const Polynom &);
      Polynom operator+(const Polynom &);
      Polynom operator*(const Polynom &);
      Polynom operator=(const Polynom &);
      Polynom operator~(); 
      Polynom operator!(); 
      Polynom operator$(); 
      ~Polynom();
};

Polynom::Polynom():degree{0}, coefficients{0}
{
}

Polynom::~Polynom()
{
   coefficients.clear();
}

Polynom::Polynom(unsigned int deg):degree(deg)
{
   coefficients.reserve(degree+1);
   for (int i = 0; i <= degree; i++)
   {
      coefficients[i] = 0;
   }
}

Polynom::Polynom(unsigned int deg, vector <float> coefs):degree(deg), coefficients(coefs)
{
}

unsigned int Polynom::get_degree()
{
   return degree;
}

float Polynom::get_coeff(unsigned int i)
{
   if (i <= degree)
      return coefficients[i];
   else return 0;
}

void Polynom::print_poly()
{
   for (auto i = 0; i <= degree; i++)
   {
      cout << showpos << coefficients[i] << "x^" <<noshowpos << i;
   }
   cout << endl;
}

Polynom::Polynom(const Polynom &p2)
{
   degree = p2.degree;
   coefficients = p2.coefficients;
}

Polynom Polynom::operator~()
{
  Polynom result(degree+1); 
   
   for (auto i = 1; i <= result.degree; i++)
   {
      result.coefficients[i] = coefficients[i-1] / i;
   }
   
   return result;
}

Polynom Polynom::operator+(const Polynom &p2)
{
   Polynom result;

   if (degree >= p2.degree)
   {
      result = Polynom(degree, coefficients);

      for (auto i = 0; i <= p2.degree; i++)
      {
         result.coefficients[i] = result.coefficients[i] + p2.coefficients[i];
      }
   }
   else
   {
      result = Polynom(p2.degree, p2.coefficients);
      
      for (auto i = 0; i <= degree; i++)
      {
         result.coefficients[i] = result.coefficients[i] + coefficients[i];
      }
   }
   return result;
}

Polynom Polynom::operator*(const Polynom &p2)
{
   Polynom result(degree+p2.degree);

   for (unsigned int k1 = 0; k1 <= degree; k1++)
   {
      for (unsigned int k2 = 0; k2 <= p2.degree; k2++)
      {
         unsigned int deg;

         deg = k1 + k2;

         result.coefficients[deg] += coefficients[k1] * p2.coefficients[k2];
      }
   }
   return result;
}

Polynom Polynom::operator=(const Polynom &p2)
{
   degree = p2.degree;
   
   coefficients.clear();
   
   coefficients.reserve(degree+1);
   
   for (unsigned int deg = 0; deg <= degree; deg++)
   {
      coefficients[deg] = p2.coefficients[deg];
   }
   return *this;
}

Polynom Polynom::operator!()
{
  Polynom result(degree-1);

   for (auto i = 0; i <= result.degree; i ++)
   {
      result.coefficients[i] = coefficients[i+1]*(i+1);
   }
   return result;
}

int main()
{
   Polynom A(4, {1, 9, -2, 4, -7});
   
   Polynom B(3, {0, 2, 6, 3});
   
   cout << "A + B = ";
   
   (A+B).print_poly();
   
   cout << "A * B = ";

   (A*B).print_poly();
   
   cout << "(A * B)` = ";
   
   Polynom F = ((A*B).operator!());
   
   F.print_poly();
   
   cout << "~(A*B)` = ";
   
   F.operator~().print_poly();
   
   return 0;
}