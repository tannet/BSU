#include<algorithm>
#include<deque>
#include<iostream>
#include<iterator>
#include<list>
#include<vector>
using namespace std;

template<class T> T& mergeSort(T& container)
{
	if (container.size() < 2)
	{
		return container;
	}

	T first, second;
    T::iterator it = container.begin();
    for(int i = 0; i < container.size(); i++)
    {
        if (i < (container.size() / 2)) 
		{
		    first.push_back(*it);
		}
        else second.push_back(*it);
        it++;
    }
    mergeSort(first);
    mergeSort(second);
    merge(first.begin(), first.end(), second.begin(), second.end(), container.begin());
}

int main()
{
	list<int> some_list;
	some_list.push_back(1);
	some_list.push_back(2);
	some_list.push_back(222);
	some_list.push_back(0);

	mergeSort(some_list);
	for (auto it : some_list) cout << it << " ";

	system("pause");
	return 0;
}