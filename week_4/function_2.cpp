#include <algorithm>
#include <vector>

class FunctionPart
{
public:
	FunctionPart(char operation, double value) :
		_operation(operation),
		_value(value)
	{}
	
	double Apply(double source_value) const
	{
		if (_operation == '+') {
			return source_value + _value;
		} else if (_operation == '-') {
			return source_value - _value;
		} else if (_operation == '*') {
			return source_value * _value;
		} else if (_operation == '/') {
			return source_value / _value;
		}
	}

	void Invert()
	{
		if (_operation == '+') {
			_operation = '-';
		} else if (_operation == '-') {
			_operation = '+';
		} else if (_operation == '*') {
			_operation = '/';
		} else if (_operation == '/') {
			_operation = '*';
		}
	}	

private:
	char _operation;
	double _value { 0 };
};

class Function
{
public:
	void AddPart(char operation, double value)
	{
		parts.push_back(FunctionPart(operation, value));
	}

	double Apply(double value) const
	{
		for (const auto &part : parts) {
			value = part.Apply(value);
		}

		return value;
	}

	void Invert()
	{
		for (auto &part : parts) {
			part.Invert();
		}

		std::reverse(begin(parts), end(parts));
	}

private:
	std::vector<FunctionPart> parts;
};
