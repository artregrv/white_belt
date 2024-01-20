#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class Rational
{
public:
	Rational() :
		_numerator(0),
		_denominator(1)
	{}

	Rational(int numerator, int denominator)
	{

		if (denominator == 0) {
			throw std::invalid_argument("Invalid argument");
		}

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

	void SetNumerator(int numerator)
	{
		_numerator = numerator;
	}
	
	int Numerator() const
	{
		return _numerator;
	}

	void SetDenominator(int denominator)
	{
		_denominator = denominator;
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
	if (rhs.Numerator() == 0) {
		throw std::domain_error("Division by zero");
	}

	return Rational(lhs.Numerator() * rhs.Denominator(),
					lhs.Denominator() * rhs.Numerator());
}

bool operator<(const Rational &lhs, const Rational &rhs)
{
	return (lhs.Numerator() * rhs.Denominator())
			< (rhs.Numerator() * lhs.Denominator());
}

std::istream &operator>>(std::istream &stream, Rational &r)
{
	int numerator { 0 };
	int denominator { 1 };

	if (stream.peek() == EOF) {
		return stream;
	}

	stream >> numerator;
	stream.ignore(1);
	stream >> denominator;

	Rational new_r(numerator, denominator);

	r.SetNumerator(new_r.Numerator());
	r.SetDenominator(new_r.Denominator());

	return stream;
}

std::ostream &operator<<(std::ostream &stream, const Rational &r)
{
	stream << r.Numerator() << '/' << r.Denominator();

	return stream;
}

class Calculator
{
public:
	explicit Calculator(Rational &lhs, Rational &rhs, char operation) :
		_lhs(lhs),
		_rhs(rhs),
		_operation(operation)
	{}

	Rational calculate() const
	{
		if (_operation == '+') {
			return _lhs + _rhs;
		} else if (_operation == '-') {
			return _lhs - _rhs;
		} else if (_operation == '*') {
			return _lhs * _rhs;
		} else if (_operation == '/') {
			return _lhs / _rhs;
		} else {
			return Rational(0, 1);
		}
	}

private:
	Rational _lhs;
	Rational _rhs;
	char _operation;
};

int main()
{
	Rational lhs;
	Rational rhs;

	char operation;

	try {
		std::cin >> lhs;
		std::cin >> operation; 
		std::cin >> rhs;

		Calculator calculator(lhs, rhs, operation);

		std::cout << calculator.calculate() << '\n';

	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}

	return 0;
}
