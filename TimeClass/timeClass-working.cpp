#include <iostream>
#include "VTime.h"

using namespace std;

int main()
{
	VTime t(12, 61, 60);
	VTime x(12, 60, 50);
	cout << t.getASCIITime() << endl;

	//cout << t.getHours() << endl;
	//cout << t.getMinutes() << endl;
	//cout << t.getSeconds() << endl;

	t.addSeconds(70);
	cout << t.getASCIITime() << endl;

	t = t - x;
	cout << t.getASCIITime() << endl;

	t.setHours(22);
	cout << t.getASCIITime() << endl;

	t.setMinutes(59);
	cout << t.getASCIITime() << endl;

	t.setSeconds(59);
	cout << t.getASCIITime() << endl;

	t.getTime();
	cout << "current time: " << t.getASCIITime() << endl;

}


///see picture for -operator
//set allows user to set hour,minutes,or seconds?
