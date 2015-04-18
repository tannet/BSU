#undef UNICODE
#include <string>

#include <stdio.h>
#include <windows.h>
using namespace std;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
char szClassName[] = "ClassName";

int m = 4, n=3;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE HPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	sscanf_s(lpCmdLine, " %d %d", &n, &m);
	//n=3; m=4;
	HWND hWnd;
	MSG msg;
	WNDCLASS wcApp;

	// Заполняем структуру класса окна 
	wcApp.lpszClassName = szClassName;
	wcApp.hInstance = hInstance;
	wcApp.lpfnWndProc = WndProc;
	wcApp.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcApp.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcApp.lpszMenuName = 0;
	wcApp.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcApp.style = CS_HREDRAW | CS_VREDRAW;
	wcApp.cbClsExtra = 0;
	wcApp.cbWndExtra = 0;

	// Регистрируем класс окна
	if (!RegisterClass(&wcApp)){
		MessageBox(NULL, "Class hasn't been registered", "RegisterClass", MB_OK);
		return 0;
	}

	hWnd = CreateWindow(szClassName, "Simple Windows Program", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, 0, hInstance, 0);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&msg, 0, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (uMsg) {
	case WM_PAINT:
	{
		RECT rect;
		GetClientRect(hWnd, &rect);
		int logx = rect.right / (3 * m - 2);
		int logy = rect.bottom / (3 * n - 2);
		hdc = BeginPaint(hWnd, &ps);
		// drawing code
		for (int i = 1; i<m + 1; i++)
		{
			MoveToEx(hdc, logx / 2 + (i - 1) * 3 * logx, logy, NULL);
			LineTo(hdc, logx / 2 + (i - 1) * 3 * logx, rect.bottom - logy);
		}
		for (int i = 1; i<n + 1; i++)
		{
			MoveToEx(hdc, logx, logy / 2 + (i - 1) * 3 * logy, NULL);
			LineTo(hdc, rect.right - logx, logy / 2 + (i - 1) * 3 * logy);
		}

		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<m; j++)
			{

				HBRUSH hbr = CreateSolidBrush(RGB(rand() % 250, rand() % 250, rand() % 250));
				SelectObject(hdc, hbr);
				Ellipse(hdc, 3 * j*logx, 3 * i*logy, 3 * j*logx + logx, 3 * i*logy + logy);
				DeleteObject(hbr);
			}

		}

		EndPaint(hWnd, &ps);
		break; }
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return (DefWindowProc(hWnd, uMsg, wParam, lParam));
	}
	return (0);
}
