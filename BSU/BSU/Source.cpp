#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	Base object;
	Base *p;
	Heritor h_object;

	p = &object;
	p->function();

	p = &h_object;
	p->function();

	system("pause");
	return 0;
}