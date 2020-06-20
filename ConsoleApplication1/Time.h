#pragma once
#include <iostream>
#include <string>

using namespace std;
class Time
{
private:
	int hours;
	int min;
	int sec;
public:
	Time();
	Time(int hours, int min, int sec);
	void setHours(unsigned h);
	char getHours();
	void setMin(unsigned m);
	char getMin();
	void setSec(unsigned s);
	char getSec();
	void setTime(unsigned h, unsigned m, unsigned s);
	float toSec() const;
	float toMin();
	float toHours();
	void addSec(unsigned n, Time obj);
	void addMin(unsigned n);
	void addHours(unsigned n);
	string to_String();
	Time operator+(Time  obj);
	Time operator-(Time  obj);
	bool operator>(const Time & obj);
	bool operator==(const Time & obj);
	bool operator<(const Time & obj);
	void checkOper(bool f);
};