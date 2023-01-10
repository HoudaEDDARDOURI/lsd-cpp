#include <iostream>
using namespace std;

template <typename T>
T powrec(T a, int n)
{
	if(n == 0)
		return 1;
	else if(n%2==1)
		return a*powrec(a,(n-1)/2)*powrec(a,(n-1)/2);
	else 
		return powrec(a,n/2)*powrec(a,n/2);

}

int main()
{
	cout << powrec<float>(3.34,2) <<endl;
	cout << "pro : " << 3.34*3.34 <<endl; 
  return 0;
}
