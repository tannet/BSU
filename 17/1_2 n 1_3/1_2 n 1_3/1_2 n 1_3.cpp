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
	case WM_SIZE:
		sx = LOWORD(lParam); //������ ����
		sy = HIWORD(lParam); //������ ����


	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);

		//��������� �����
		//for (x = 0; x < sx; x += sx / 10)
		//{
		//	MoveToEx(hDC, x, 0, NULL);
		//	LineTo(hDC, x, sy);
		//}
		//for (y = 0; y < sy; y += sy / 10)
		//{
		//	MoveToEx(hDC, 0, y, NULL);
		//	LineTo(hDC, sx, y);
		//}

		GetClientRect(hWnd, &rect);

		//������������� � ������(1_2)
		Rectangle(hDC, 10, 10, sx - 10, sy - 10);

		Ellipse(hDC, 0, 0, sx, sy);

		//����� ������ (1_3)
		DrawText(hDC, "Text", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		DrawText(hDC, "Text", -1, &rect, DT_SINGLELINE | DT_LEFT | DT_TOP);
		DrawText(hDC, "Text", -1, &rect, DT_SINGLELINE | DT_RIGHT | DT_TOP);
		DrawText(hDC, "Text", -1, &rect, DT_SINGLELINE | DT_LEFT | DT_BOTTOM);
		DrawText(hDC, "Text", -1, &rect, DT_SINGLELINE | DT_RIGHT | DT_BOTTOM);

		EndPaint(hWnd, &ps);
		break;

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