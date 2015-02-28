#include<iostream>
#include<vector>
#include<deque>
#include<iterator>
#include<list>
using namespace std;

template<class T>
typename T::const_iterator func(const T& cont)
{
	T::const_iterator r;
	T::const_iterator b = cont.begin();
	T::const_iterator e = --cont.end();
	for (e; e != b; --e)
	{
		for (r = e - 1; r >= b; --r)
		{
			if (*e == *r)
			{
				return e;
			}
		}
	}
}

int main()
{
	deque<double> v;
	v.push_back(13);
	v.push_back(2);
	v.push_back(6.25);
	v.push_back(6.25);
	v.push_back(28.3);
	v.push_back(13);
	deque<double>::const_iterator it; 
	it = func(v); 
	cout << *it << endl; 
	vector<int> vect;
	vect.push_back(1);
	vect.push_back(28);
	vect.push_back(28);
	vect.push_back(4.2);
	vect.push_back(5.2);
	vect.push_back(28.3);
	vector<int>::const_iterator i;
	i = func(vect);
	cout << *i << endl;
	system("pause");
	return 0;
}