#include<iostream>
#include<math.h>
#include<conio.h>
#include<map>
#include <algorithm>
#include<utility>
#include<stdbool.h>
using namespace std;

float func(float x)
{
	return x * x * x + 7 * x - 7;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	float a, b, c, e;
	float x[20];
	int i = 1;
	cout << "a="; cin >> a;
	cout << "\nb="; cin >> b;
	cout << "\ne="; cin >> e;
	c = (a + b) / 2;
	cout << "\nc=" << c;
	cout << "\nf(c)=" << func(c) << endl;
	x[0] = c;
	while ((fabs(b - a) >= e) && (fabs(func(a)-func(b)) >= e))
	{
		if (func(a)*func(c) < 0)
			b = c;
		else
			a = c;
		c = (a + b) / 2;
		cout << "\nc=" << c << endl;
		cout << "f(c)=" << func(c) << endl;
		x[i] = c;
		i++;
	}	

	float min = fabs(func(x[1]));
	for (int j = 0; j < i-1; ++j)
	{
		if (fabs(func(x[j])) < min)
		{
			min = x[j];
		}
	}
	char str[32];
	sprintf(str, " %3.10f ", min);
	cout << "\nОтвет х="<<str<< " при f(x)="<< func(min) << endl;
}