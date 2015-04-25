//работает для чисел n <= 48
#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter n: n = ";
	cin >> n;

	__asm
	{
		mov ecx, n
		sub ecx, 2
		mov eax, 1
		mov ebx, 1
		cmp n, 2
		jg calculation
		mov n, 1
		jmp ending	
	calculation :
		mov edx, ebx
		add ebx, eax
		mov eax, edx
		loop calculation
		mov n, ebx
	ending :
	}

	cout << n;

	system("pause");
	return 0;
}