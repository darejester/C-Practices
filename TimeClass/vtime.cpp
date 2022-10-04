#include ".\VTime.h" // This works but is freaky!   I will leave it in so we can talk.

#include <iostream>
#include "VTime.h"

using namespace std;

// Adds a specified number of seconds onto the time.
void VTime::addSeconds(int a_seconds)
{
	m_secSinceMid += a_seconds;
}
VTime VTime::operator +(int a_seconds)
{
	VTime tmp(getHours(), getMinutes(), getSeconds());
	tmp.addSeconds(a_seconds);
	return tmp;
}
VTime VTime::operator -(VTime t)
{
	VTime tmp(getHours(), getMinutes(), getSeconds());
	tmp.addSeconds(-t.m_secSinceMid);
	return tmp;
}
void VTime::getTime()
{

	int x;
	time_t t;
	struct tm nowLocal;
	t = time(NULL);

	nowLocal = *localtime(&t);

	x = (nowLocal.tm_hour * 60 * 60) + (nowLocal.tm_min * 60) + (nowLocal.tm_sec);

	m_secSinceMid = x;
}
// Gets the time as an ASCII string
string VTime::getASCIITime()
{
	char buff[128];

	// We will get a special error on this.  I wanted to discuss the error and therefore left this code in.
	sprintf_s(buff, "%2.2d:%2.2d:%2.2d", getHours(), getMinutes(), getSeconds());

	return buff;
}
