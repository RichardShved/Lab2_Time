#include "pch.h"
#include "Time.h"
#include <iostream>
#include <string>

using namespace std;
Time::Time()
{
	hours = 0; min = 0; sec = 0;
}
Time::Time(int hours, int min, int sec)
{
	hours = 0; min = 0; sec = 0;
}
void Time::setHours(unsigned h) {
	if (h >= 0 && h < 24) {
		hours = h;
	}
}
char Time::getHours() {
	return hours;
}
void Time::setMin(unsigned m) {
	if (m >= 0 && m < 60)
		min = m;
}
char Time::getMin() {
	return min;
}
void Time::setSec(unsigned s) {
	if (s >= 0 && s < 60)
		sec = s;
}
char Time::getSec() {
	return sec;
}
void Time::setTime(unsigned h, unsigned m, unsigned s) {
	setHours(h);
	setMin(m);
	setSec(s);
}

float Time::toSec() const {
	float s, h, m;
	h = hours * 60 * 60;
	m = min * 60;
	s = sec + h + m;
	return s;
}

float Time::toMin() {
	float s, h, m;
	h = hours * 60;
	s = sec / 60.0;
	m = min + h + s;
	return m;
}
float Time::toHours() {
	float s, h, m;
	s = sec / 60.0 / 60.0;
	m = min / 60.0;
	h = hours + m + s;
	return h;
}

Time secToTime(unsigned s)
{
	Time a(0, 0, 0);
	a.setHours((s / 3600) % 24);
	a.setMin((s % 3600) / 60);
	a.setSec(s % 60);
	return a;
}

void Time::addSec(unsigned n, Time obj) {
	int s, h, m;
	float temp;
	temp = obj.toSec();
	temp = temp + n;
	obj = secToTime(temp);
	this->sec = obj.sec;
	/*if (s > 60)
	{
		s = s % 60;
		m = min + 1;
		if (m > 60) {
			m = m % 60;
			h = hours + 1;
			if (h > 24) {
				h = h % 24;

			}

		}

	}*/
}
void Time::addMin(unsigned n) {
	int s, h;
	char m;
	s = sec;
	m = min + n;
	if (m > 60) {
		m = m % 60;
		h = hours + 1;
		if (h > 24) {
			h = hours % 24;

		}
	}
}
void Time::addHours(unsigned n) {
	int s, h, m;
	s = sec;
	m = min;
	h = hours + n;
	if (h > 24) {
		h = h % 24;

	}
}

Time Time::operator +(Time  obj) {
	Time fun(0, 0, 0);
	float temp, temp2;
	temp = this->toSec();
	temp2 = obj.toSec();
	temp += temp2;
	fun = secToTime(temp);
	return fun;

}

Time Time::operator -(Time  obj) {
	Time fun(0, 0, 0);
	float temp, temp2;
	temp = this->toSec();
	temp2 = obj.toSec();
	temp = abs(temp - temp2);
	fun = secToTime(temp);
	return fun;
}

string Time::to_String()
{
	string temp;
	temp = to_string(this->getHours()) + ":" + to_string(this->getMin()) + ":" + to_string(this->getSec());
	return temp;
}

bool Time::operator > (const Time & obj) {
	bool a;
	if (hours > obj.hours) {

		a = true;
	}
	else
	{
		a = false;
	}
	if (hours == obj.hours) {
		if (min > obj.min) {
			a = true;
		}
		else {
			a = false;
		}
		if (min == obj.min) {
			if (sec > obj.sec) {
				a = true;
			}
			else {
				a = false;
			}
		}
	}
	return a;
}

bool Time::operator == (const Time & obj) {
	bool a;
	if ((hours == obj.hours) || (min == obj.min) || (sec == obj.sec)) {
		a = true;
	}
	else {
		a = false;
	}
	return a;
}

bool  Time::operator < (const Time & obj) {
	bool a;
	if (hours < obj.hours) {

		a = true;
	}
	else
	{
		a = false;
	}
	if (hours == obj.hours) {
		if (min < obj.min) {
			a = true;
		}
		else {
			a = false;
		}
		if (min == obj.min) {
			if (sec < obj.sec) {
				a = true;
			}
			else {
				a = false;
			}
		}
	}
	return a;
}

void Time::checkOper(bool f) {
	if (f == true) {
		cout << "проверка сравнеия : true " << endl;
	}
	else {
		cout << "проверка сравнеия : false " << endl;
	}
}
