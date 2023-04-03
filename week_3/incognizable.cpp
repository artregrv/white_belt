class Incognizable
{
public:
	Incognizable()
	{};
	Incognizable(int first) :
		 _first(first)
	{};
	Incognizable(int first, int second) : 
		_first(first), _second(second)
	{};

private:
	int _first { 0 };
	int _second { 0 };
};

int main() {
	Incognizable a;
	Incognizable b = {};
	Incognizable c = {0};
	Incognizable d = {0, 1};

	return 0;
}
