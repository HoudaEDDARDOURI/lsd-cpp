#include <iostream>
using namespace std;

template <typename T>
T powiter(T a, int n)
{
	int res = 1;
	while(n>0)
	{
		if(n%2 == 1)
		{
			res = res * a;
			a = a * a;
		}
		else
		{
			a = a * a ;
		}
		n = n/2; 
	}
	return res;
}

int main()
{
	cout << "result : " << powiter<double>(3.2,2) << endl;
	cout << " 3.2 ** 2 est : "<< 3.2*3.2 <<endl;
	
	return 0;
}
