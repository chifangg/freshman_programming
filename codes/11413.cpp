#include<iostream>
#include"function.h"
using namespace std;


Rational::Rational( int n, int d ) : numerator( n ), denominator( d ) 
{
     reduce(); // store the fraction in reduced form
} // end Rational constructor

Rational Rational::addition( const Rational &a ) const //type/class
{
    Rational t( a.numerator * denominator + a.denominator * numerator, a.denominator * denominator );/////int t
    t.reduce(); // store the fraction in reduced form
    return t;
} // end function addition


Rational Rational::multiplication( const Rational &m ) const  
{
     Rational t( m.numerator * numerator, m.denominator * denominator ); 
     t.reduce(); // store the fraction in reduced form
     return t;
} // end function multiplication

void Rational::printRational() const 
{
       cout << numerator << '/' << denominator << "\n";
} // end function printRational

void Rational::reduce() 
{
   int gcdnum = gcd(numerator, denominator); // greatest common divisor
   numerator /= gcdnum;
   denominator /= gcdnum;
   if(denominator < 0)
    {
    	numerator *= -1;
    	denominator *= -1;
	}
} 
