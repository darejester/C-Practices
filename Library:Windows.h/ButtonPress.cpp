#include <iostream>
#include <Windows.h>

using namespace std;


int main()
{
	while (1)
	{
		if (GetKeyState('A') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
		{
			// Do stuff
			cout << "A is pressed" << endl;
			
		}
		else if (GetKeyState('S') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
		{
			// Do stuff
			cout << "S is pressed" << endl;
		}
		/*else
		{
			cout << "nothing is pressed" << endl;
		}*/
	}
	
	return 0;
}
