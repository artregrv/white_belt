#include <iostream>
#include <sstream>
#include <string>

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
	return Rational(lhs.Numerator() * rhs.Denominator(),
					lhs.Denominator() * rhs.Numerator());
}

std::istream &operator>>(std::istream &stream, Rational &r)
{
	std::string numerator;
	std::getline(stream, numerator, '/');
	
	std::string denominator;
	std::getline(stream, denominator, ' ');
	
	if (numerator.empty() || denominator.empty())
		return stream;

	Rational new_r(stoi(numerator), stoi(denominator));

	r.SetNumerator(new_r.Numerator());
	r.SetDenominator(new_r.Denominator());

	return stream;
}

std::ostream &operator<<(std::ostream &stream, const Rational &r)
{
	stream << r.Numerator() << '/' << r.Denominator();

	return stream;
}

using namespace std;

int main()
{
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
	return 0;
}
