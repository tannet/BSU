#undef UNICODE
#include <windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int m = 10, n = 10;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hMainWnd;
	char szClassName[] = "My Class";
	MSG msg;
	WNDCLASSEX wc;

	// ��������� ��������� ������ ���� WNDCLASS
	wc.cbSize = sizeof(wc);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	// ������������ ����� ����
	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Cannot register class", "Error", MB_OK);
		return 0;
	};

	//������� �������� ���� ����������
	hMainWnd = CreateWindow(
		szClassName,         // ��������� �� ������ ������������������� ����� ������
		"A Hello1 Application",// ��������� �� ������ ��������� ����
		WS_OVERLAPPEDWINDOW, // ����� ����
		CW_USEDEFAULT,       // �������������� ���������� ����
		0,                   // ������������ ���������� ����
		CW_USEDEFAULT,       // ������ ����
		0,                   // ������ ����
		(HWND)NULL,          // ���������� ������������� ����
		(HMENU)NULL,         // ���������� ���� ����
		(HINSTANCE)hInstance,// ���������� ���������� ����������
		NULL               // ��������� �� �������������� ������ ����
		);

	if (!hMainWnd)
	{
		MessageBox(NULL, "Cannot create main window", "Error", MB_OK);
		return 0;
	};

	//�������� ����
	ShowWindow(hMainWnd, SW_SHOW);
	UpdateWindow(hMainWnd);

	// ���� ��������� ��������� �� �������� ����������
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT ps;
	RECT rect;
	/*int x, y;*/
	static int sx, sy;
	
	switch (uMsg)
	{
	/*case WM_CREATE:
		HPEN Pen1 = CreatePen(PS_SOLID, 1, RGB(200, 0, 50));
		HBRUSH hBR = CreateSolidBrush(RGB(255, 0, 255));
		break;*/

	case WM_SIZE:
		sx = LOWORD(lParam); //������ ����
		sy = HIWORD(lParam); //������ ����
		break;


	case WM_PAINT:
	{
		hDC = BeginPaint(hWnd, &ps);

		GetClientRect(hWnd, &rect);

		//�����������
		MoveToEx(hDC, 0, sy / 2, NULL);
		LineTo(hDC, sx, sy / 2);
		//���������
		MoveToEx(hDC, sx / 2, 0, NULL);
		LineTo(hDC, sx / 2, sy);
		
		//�������� ����� �������
		HBRUSH hBR = CreateSolidBrush(RGB(255, 0, 255));

		SelectObject(hDC, hBR);
		Rectangle(hDC, 30, 30, sx / 2 - 30, sy / 2 - 30); 
		TextOut(hDC, sx / 4 - 20, sy / 2 - 20, "Rectangle", 10);
		Ellipse(hDC, 30, sy / 2 + 30, sx / 2 - 30, sy - 30); 
		TextOut(hDC, sx / 4 - 20, sy - 20, "Ellipse", 8);
		Pie(hDC, sx / 2 + 30, 30, sx - 30, sy / 2 - 30, sx * 3 / 4, 30, sx * 5 / 8, 20); 
		TextOut(hDC, sx * 3 / 4 - 20, sy / 2 - 20, "Pie", 4);
		//����
		HPEN Pen1 = CreatePen(PS_SOLID, 1, RGB(200, 0, 50));
		SelectObject(hDC, Pen1);
		MoveToEx(hDC, sx / 2 + 30, sy * 3 / 4 , NULL);
		LineTo(hDC, sx * 3 / 4, sy / 2 + 30);
		LineTo(hDC, sx - 30, sy * 3 / 4);
		LineTo(hDC, sx * 3 / 4, sy - 30);
		LineTo(hDC, sx / 2 + 30, sy * 3 / 4);
		TextOut(hDC, sx * 3 / 4 - 20, sy - 20, "Diamond", 10);
		//�������� ������������ ���������
		DeleteObject(hBR);
		DeleteObject(Pen1);

		EndPaint(hWnd, &ps);
		break;
	}

	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	return 0;
}