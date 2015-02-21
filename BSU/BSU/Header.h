#include <iostream>
using namespace std;
class Base
{
public:
	virtual void function()
	{
		cout << "Base class" << endl;
	}
};

class Heritor : public Base
{
	void function()
	{
		cout << "Heritor class" << endl;
	}
};