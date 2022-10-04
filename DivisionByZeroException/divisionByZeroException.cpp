#include <cfenv>
#include <iostream>

using namespace std;

void TurnOnFloatingExceptions()

{

	unsigned int cw;

	// Note : same result with controlfp

	cw = _control87(0, 0) & MCW_EM;

	cw &= ~(_EM_INVALID | _EM_ZERODIVIDE | _EM_OVERFLOW);

	_control87(cw, MCW_EM);

}

int main()
{
	float one = 1.0;
	float zero = 0.0;

	TurnOnFloatingExceptions();

	// control
	cout << "four divided by two " << 4 / 2 << endl;

	// test cases
	cout << "one divided by zero " << one/zero << endl;
	cout << "zero divided by zero " << zero/zero << endl;

	cout << "After test cases " << endl;
}
