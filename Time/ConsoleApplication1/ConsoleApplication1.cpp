#include "pch.h"
#include <iostream>
#include "Time.h"
#include <fstream>

using namespace std;
int main()
{	
	setlocale(LC_ALL, "rus");
	Time  obj1(0, 0, 0), obj2(0, 0, 0), obj3(0, 0, 0);
	Time ob;
	string s;
	Time *ob1=new Time;
	Time obj[3];
	bool a;
	ofstream fout;
	
	obj[0].addSec(20,obj[0]);
	ob1->setTime(10,10,10);
	obj2.setTime(1, 1, 1);
	obj1.setTime(20, 51, 31);
	cout << obj1.to_String() << endl;

	cout << "В часах :" << obj1.toHours() << endl;
	cout << "В минутах :" << obj1.toMin() << endl;
	cout << "В секундах :" << obj1.toSec() << endl;

	obj1.addSec(11, obj1);
	cout << obj1.to_String() << endl;

	obj2.setTime(9, 9, 9);

	obj3 = obj1 + obj2;
	cout << "Сложение: " << obj3.to_String() << endl;

	obj3 = obj1 - obj2;
	cout << "Вычитание: " << obj3.to_String() << endl;

	//больше
	if (obj1 > obj2) {
		a = true;
	}
	else {
		a = false;
	}
	obj1.checkOper(a);


	//меньше
	if (obj1 < obj2) {
		a = true;
	}
	else {
		a = false;
	}
	obj1.checkOper(a);


	//равно
	if (obj1 == obj2) {
		a = true;
	}
	else {
		a = false;
	}
	obj1.checkOper(a);


	system("pause");

}