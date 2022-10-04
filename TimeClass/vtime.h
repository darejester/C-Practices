#pragma once
#pragma warning(disable : 4996)
#include <string>
#include <ctime>
#

using namespace std;

class VTime
{
public:

	// Constructor for this class.  We allow the user to initially set the stime or it will be set to zero.
	VTime(int a_hours = 0, int a_minutes = 0, int a_seconds = 0)
	{
		m_secSinceMid = (60 * 60 * a_hours) + (60 * a_minutes) + (a_seconds);
	}
	// Accessor functions.
	int getHours()
	{
		return (m_secSinceMid / 60) / 60;
	}
	int getMinutes()
	{
		return (m_secSinceMid / 60) % 60;
	}
	int getSeconds()
	{
		return m_secSinceMid % 60;
	}
	void setHours(int hrs)
	{
		int tmp = getHours();
		tmp = tmp * 60 * 60;
		m_secSinceMid -= tmp;
		m_secSinceMid += (hrs * 60 * 60);
	}
	void setMinutes(int min)
	{
		int tmp = getMinutes();
		tmp = tmp * 60;
		m_secSinceMid -= tmp;
		m_secSinceMid += (min * 60);
	}
	void setSeconds(int sec)
	{
		int tmp = getSeconds();
		m_secSinceMid -= tmp;
		m_secSinceMid += (sec);
	}

	// A function to add a specified number of seconds to the time.
	void addSeconds(int a_seconds);

	// Plus operator to add seconds onto the time.
	VTime operator +(int a_seconds);

	// Minus operator to subtract seconds from the time
	VTime operator -(VTime t);

	// Get current time
	void getTime();

	// Gets the time as an ASCII string.
	string getASCIITime();

private:

	int m_secSinceMid;

};
