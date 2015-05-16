
#include <iostream>
using namespace std;

int main()
{
	int n;
	double x, y;
	cout << "Enter numbers: n = "; 
	cin >> n; 
	cout << "x = "; 
	cin >> x; 
	cout << "y = "; 
	cin >> y;

	int a = -1;
	double sum1 = 0, sum2 = 0;
	double mult1 = 1, mult2 = 1, mult_i = 1;
	double num = 1, y1 = 1;
	/*for (int i = 1; i <= n; i++)
	{
		y1 *= y;
		sum1 += y1;
		mult1 *= sum1;
		num *= x * x;
		mult2 *= a*(num / mult1);
		sum2 = 1 + mult2;
		mult_i *= sum2;
	}*/

	_asm
	{
		    mov ecx, n //Поместили n в регистр счетчика
			cmp ecx, 0
			jne l

		l:
		
			fld y1 // Добавить в стек
			fld y
			fmul
			fstp y1 // Убрать из стека и освободить память
		
			fld sum1
			fld y1
			fadd
			fstp sum1
		
			fld mult1
			fld sum1
			fmul
			fstp mult1
		
			fld num
			fld x
			fmul
			fld x
			fmul
			fstp num
		
			fld mult2
			fild a
			fmul
			fld num
			fmul
			fld mult1
			fdiv
			fstp mult2
		
			fld mult2
			fld1
			fadd
			fstp sum2
		
			fld sum2
			fld mult_i
			fmul
			fstp mult_i

			loop l
	}
	
	cout << "The result is: " << mult_i << endl;
	
	system("pause");
	return 0;
}