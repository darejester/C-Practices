#include <iostream>

using namespace std;

long long fib(long long);

int main()
{
	long long n;
	
	cout << "How many terms? : ";
	cin >> n;

	cout << endl << "Fibonnaci Series with "  << n << " terms:"<< endl;
	for (long long i = 1; i <= n; i++) 
	{
		cout  << fib(i) << " ";
	}
	return 0;
}

long long fib(long long n)
{
	if (n <= 1 ) 
	{
		return(n);
	}
	else 
	{
		return(fib(n - 1) + fib(n - 2));
	}
}
