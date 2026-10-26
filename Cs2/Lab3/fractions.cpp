#include "fractions.h"

fractions::Fraction::Fraction(int numerator, int denominator)
    : _numerator(numerator), _denominator(denominator)
{    
    if (denominator == 0)
    {
        cerr << "Can't Divide by 0: " << endl;
    }
}

fractions::Fraction fractions::Fraction::operator+(fractions::Fraction const &frac)
{
    int answer_numerator = ((_numerator * frac._denominator) + (frac._numerator * _denominator));
    int answer_denominator = (frac._denominator * _denominator);
    return simplify(Fraction(answer_numerator, answer_denominator));
}

fractions::Fraction fractions::Fraction::operator-(fractions::Fraction const &frac)
{
    int answer_numerator = ((_numerator * frac._denominator) - (frac._numerator * _denominator));
    int answer_denominator = (frac._denominator * _denominator);
    return simplify(Fraction(answer_numerator, answer_denominator));;
}


fractions::Fraction fractions::Fraction::operator*(Fraction const &frac)
{
    int answer_numerator = _numerator * frac._numerator;
    int answer_denominator = _denominator * frac._denominator;
    return simplify(Fraction(answer_numerator, answer_denominator));
}

fractions::Fraction fractions::Fraction::operator/(Fraction const &frac)
{
    int answer_numerator = _numerator * frac._denominator;
    int answer_denominator = _denominator * frac._numerator;
    return simplify(Fraction(answer_numerator, answer_denominator));
}

fractions::Fraction fractions::Fraction::simplify(Fraction frac)
{   
    int a = abs(frac._numerator);
    int b = abs(frac._denominator);

    while (b != 0)
    {
        int remainder = a % b;
        a = b;
        b = remainder;
    }

    int gcd = a;

    if(gcd == 0)
       return Fraction(0,1);

    return Fraction(frac._numerator / gcd, frac._denominator / gcd);
    
}
/*
void fractions::Fraction::simplify()
{
    return 0;
}
*/
/*
int fractions::Fraction::gcd(int a, int b)
{
    return 0;
}
*/
bool fractions::Fraction::operator==(Fraction const &frac)
{
    return _numerator * frac._denominator ==
    frac._numerator * _denominator;
}
ostream &fractions::operator<<(ostream &os, const Fraction &frac)
{
    os << frac._numerator << "/" << frac._denominator;
    return os;
}