#include <iostream>
using namespace std;

template <typename T>
T multiply(T x, T y)
{
	return x*y;
}

int main()
{
	std::cout << multiply<int>(2,3) << '\n';
	cout << multiply<double>(1.2,3) << '\n';
	
	return 0;
}
