#include<windows.h>
void paint(HWND);
LRESULT CALLBACK windProcedure(HWND, UINT, WPARAM, LPARAM);
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	WNDCLASSW wnd = { 0 };
	wnd.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wnd.lpszClassName = L"WindClass";
	wnd.lpfnWndProc = windProcedure;
	wnd.hInstance = hInstance;
	wnd.hCursor = LoadCursor(NULL,IDC_ARROW);

	if (!RegisterClass(&wnd)) 
		return -1;
	
	CreateWindowW(L"WindClass", L"Main Window", WS_VISIBLE | WS_OVERLAPPEDWINDOW, 100, 100, 600, 600, NULL, NULL, NULL, NULL);

	MSG msg = { 0 };
	
	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
LRESULT CALLBACK windProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg)
	{
	case WM_PAINT:
		paint(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default: 
		return DefWindowProc(hWnd, msg, wp, lp);
	}
}void paint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hDc;

	hDc = BeginPaint(hWnd, &ps);
	TextOut(hDc, 10, 10, L"Hello World", 11);
	EndPaint(hWnd, &ps);
}