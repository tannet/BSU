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

	// Заполняем структуру класса окна WNDCLASS
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

	// Регистрируем класс окна
	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Cannot register class", "Error", MB_OK);
		return 0;
	};

	//Создаем основное окно приложения
	hMainWnd = CreateWindow(
		szClassName,         // указатель на строку зарегистрированного имени класса
		"A Hello1 Application",// указатель на строку заголовка окна
		WS_OVERLAPPEDWINDOW, // стиль окна
		CW_USEDEFAULT,       // горизонтальная координата окна
		0,                   // вертикальная координата окна
		CW_USEDEFAULT,       // ширина окна
		0,                   // высота окна
		(HWND)NULL,          // дескриптор родительского окна
		(HMENU)NULL,         // дескриптор меню окна
		(HINSTANCE)hInstance,// дескриптор экземпляра приложения
		NULL               // указатель на дополнительные данные окна
		);

	if (!hMainWnd)
	{
		MessageBox(NULL, "Cannot create main window", "Error", MB_OK);
		return 0;
	};

	//Показать окно
	ShowWindow(hMainWnd, SW_SHOW);
	UpdateWindow(hMainWnd);

	// Цикл обработки сообщений до закрытия приложения
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
		sx = LOWORD(lParam); //ширина окна
		sy = HIWORD(lParam); //высота окна


	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);

		//РИСОВАНИЕ СЕТКИ
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

		//Прямоугольник и эллипс(1_2)
		Rectangle(hDC, 10, 10, sx - 10, sy - 10);

		Ellipse(hDC, 0, 0, sx, sy);

		//Вывод текста (1_3)
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