//#include <stack>
//#include <iostream>
//using namespace std;
//
//template<class T, class C = std::stack<T> > class Queue
//{
//protected:
//	C first_stack;
//	C second_stack;
//public:
//	void moveToSecond()
//	{
//		for (int i = first_stack.size(); i > 0; i--)
//		{
//			second_stack.push(first_stack.top());
//			first_stack.pop();
//		}
//	}
//
//	void moveToFirst()
//	{
//		for (int i = second_stack.size(); i > 0; i--)
//		{
//			first_stack.push(second_stack.top());
//			second_stack.pop();
//		}
//	}
//	void push(const T& val) 
//	{ 
//		first_stack.push(val); 
//	}
//
//	void pop()
//	{
//		if (empty()) return;
//		if (second_stack.empty())
//		{
//			moveToSecond();
//			second_stack.pop();
//		}
//		else second_stack.pop();
//	}
//
//	bool empty()
//	{
//		if (first_stack.empty() && second_stack.empty())
//		{
//			return true;
//		}
//		else return false;
//	}
//
//	long int size_of_stack()
//	{
//		return first_stack.size() + second_stack.size();
//	}
//
//	T& front()
//	{
//		if (second_stack.empty()) 
//		{ 
//			moveToSecond(); 
//		}
//		return second_stack.top();
//	}
//
//};
//
//int main()
//{
//	Queue <int> Q;
//
//	Q.push(99);
//	Q.push(32);
//	Q.push(45);
//	Q.push(10);
//
//	cout << "Start number of elements: " << Q.size_of_stack() << endl;
//	cout << "Is empty? " << Q.empty() << endl;
//	cout << "Front element: " << Q.front() << endl;
//	Q.pop();
//	Q.pop();
//	Q.pop();
//	cout << "Number of elements in the end: " << Q.size_of_stack() << endl;
//
//	system("pause");
//	return 0;
//}