#include "Window.h"
#include "Header.h"
#include "Vector.h"
#include "Matrix.h"

#define ID_BUTTON 1
#define ID_LINEAR 2

void outputPointGroup(Group pointGroup, HWND hWnd)
{
	CreateWindow(TEXT("STATIC"), wGroupName(pointGroup).c_str(),
		WS_VISIBLE | WS_CHILD,
		430, 430, 100, 20,
		hWnd, (HMENU)NULL, NULL, NULL);
}


LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE: {

		CreateWindow(TEXT("BUTTON"), TEXT("Identify"),
			WS_VISIBLE | WS_CHILD,
			540, 430, 80, 20,
			hWnd, (HMENU) ID_BUTTON, NULL, NULL);


		HMENU hMenubar = CreateMenu();
		HMENU hGeometry = CreateMenu();

		AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hGeometry, L"Geometry");


		AppendMenu(hGeometry, MF_STRING, NULL, L"Linear");
		AppendMenu(hGeometry, MF_STRING, NULL, L"Trigonal Planar");
		AppendMenu(hGeometry, MF_STRING, NULL, L"Tetrahedral");
		AppendMenu(hGeometry, MF_STRING, NULL, L"Trigonal Bipyramidal");
		AppendMenu(hGeometry, MF_STRING, NULL, L"Octahedral");



		SetMenu(hWnd, hMenubar);


		break;
	}
	case WM_COMMAND:
	{
		if (LOWORD(wParam) == ID_BUTTON)
		{
			//All of these need some sort of Vector parameter. Currently defaults to 0 vectors.
			Structure geometry{ Linear }; //arbitrary definition for testing
			switch (geometry)
			{
			case (Linear):
			{
				Group pointGroup{ linear_identifier()};
				outputPointGroup(pointGroup, hWnd);
				break;
			}
			case (Trigonal_planar):
			{
				Group pointGroup{ trigonal_planar_identifier() };
				outputPointGroup(pointGroup, hWnd);
				break;
			}
			case (Tetrahedral):
			{
				Group pointGroup{ tetrahedral_identifier() };
				outputPointGroup(pointGroup, hWnd);
				break;
			}
			case (Trigonal_bipyramidal):
			{
				Group pointGroup{ trigonal_bipyramidal_identifier() };
				outputPointGroup(pointGroup, hWnd);
				break;
			}
			case (Octahedral):
			{
				Group pointGroup{ octahedral_identifier() };
				outputPointGroup(pointGroup, hWnd);
				break;
			}
			}
		}

		break;
	}
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}



Window::Window()
	: m_hInstance(GetModuleHandle(nullptr))
{
	const wchar_t* CLASS_NAME = L"Window Class";


	WNDCLASS wndClass = {};
	wndClass.lpszClassName = CLASS_NAME;
	wndClass.hInstance = m_hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.lpfnWndProc = WindowProc;

	RegisterClass(&wndClass);

	DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

	int width = 640;
	int height = 480;

	RECT rect;
	rect.left = 250;
	rect.top = 250;
	rect.right = rect.left + width;
	rect.bottom = rect.top + height;

	AdjustWindowRect(&rect, style, false);


	m_hWnd = CreateWindowEx(
		0,
		CLASS_NAME,
		L"Point Group Identifier",
		style,
		rect.left,
		rect.top,
		rect.right - rect.left,
		rect.bottom - rect.top,
		NULL,
		NULL,
		m_hInstance,
		NULL
	);

	ShowWindow(m_hWnd, SW_SHOW);
}

Window::~Window()
{
	const wchar_t* CLASS_NAME = L"Window Class";

	UnregisterClass(CLASS_NAME, m_hInstance);
}

bool Window::ProcessMessages()
{
	MSG msg = {};
	
	while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
		{
			return false;
		}


		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return true;
}


