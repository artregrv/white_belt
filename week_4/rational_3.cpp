#include <iostream>

class Rational
{
public:
	Rational() :
		_numerator(0),
		_denominator(1)
	{}

	Rational(int numerator, int denominator)
	{
		if (numerator == 0) {
			_numerator = 0;
			_denominator = 1;
		} else {
			int sign = (numerator / abs(numerator)) * (denominator / abs(denominator));

			numerator = abs(numerator);
			denominator = abs(denominator);

			int tmp_gcd = gcd(numerator, denominator);

			_numerator = numerator / tmp_gcd;
			_denominator = denominator / tmp_gcd;	
			
			_numerator *= sign;
		}
	}

	
	int Numerator() const
	{
		return _numerator;
	}

	int Denominator() const
	{
		return _denominator;
	}

private:
	int gcd(int lhs, int rhs)
	{
		while ((lhs != rhs)) {
			if (lhs > rhs) {
				lhs -= rhs;
			} else {
				rhs -= lhs;
			}
		}

		return lhs;
	}
	
	int _numerator;
	int _denominator;
};

bool operator==(const Rational &lhs, const Rational &rhs)
{
	return ((lhs.Numerator() == rhs.Numerator())
			&& (lhs.Denominator() == rhs.Denominator()));
}

Rational operator+(const Rational &lhs, const Rational &rhs)
{
	int lhs_numerator = lhs.Numerator() * rhs.Denominator();
	int rhs_numerator = rhs.Numerator() * lhs.Denominator();

	return Rational(lhs_numerator + rhs_numerator, 
					lhs.Denominator() * rhs.Denominator());
}

Rational operator-(const Rational &lhs, const Rational &rhs)
{
	int lhs_numerator = lhs.Numerator() * rhs.Denominator();
	int rhs_numerator = rhs.Numerator() * lhs.Denominator();

	return Rational(lhs_numerator - rhs_numerator, 
					lhs.Denominator() * rhs.Denominator());
}

Rational operator*(const Rational &lhs, const Rational &rhs)
{
	return Rational(lhs.Numerator() * rhs.Numerator(),
					lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational &lhs, const Rational &rhs)
{
	return Rational(lhs.Numerator() * rhs.Denominator(),
					lhs.Denominator() * rhs.Numerator());
}

using namespace std;

int main()
{
	const Rational r = Rational(1, 2) * Rational(1, 3) / Rational(1, 4);
	if (r == Rational(2, 3)) {
	  cout << "equal";
	}
	return 0;
}
