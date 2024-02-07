#include "gui.h"

#include "../Imgui/imgui.h"
#include "../Imgui/imgui_impl_dx9.h"
#include "../Imgui/imgui_impl_win32.h"
#include "identifier.h"

typedef struct
{
	DWORD R;
	DWORD G;
	DWORD B;
	DWORD A;
}RGBA;
RGBA red = { 255,0,0,255 };
static void DrawStrokeText(int x, int y, RGBA* color, const char* str)
{
	ImFont a;
	std::string utf_8_1 = std::string(str);
	std::string utf_8_2 = (utf_8_1);
	ImGui::GetForegroundDrawList()->AddText(ImVec2(x, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetForegroundDrawList()->AddText(ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetForegroundDrawList()->AddText(ImVec2(x - 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetForegroundDrawList()->AddText(ImVec2(x + 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetForegroundDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), utf_8_2.c_str());
}
static void DrawNewText(int x, int y, RGBA* color, const char* str)
{
	//	ImFont a;
	//ImGuiIO& io = ImGui::GetIO();
		//ImFont* pFont = io.Fonts->AddFontFromFileTTF("sansation.ttf", 10.0f);
		//a.FontSize = 5.f;
	std::string utf_8_1 = std::string(str);
	std::string utf_8_2 = (utf_8_1);
	ImGui::GetForegroundDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), utf_8_2.c_str());
}
static void DrawRect(int x, int y, int w, int h, RGBA* color, int thickness)
{
	ImGui::GetForegroundDrawList()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), 0, 0, thickness);
}
static void DrawFilledRect(int x, int y, int w, int h, RGBA* color)
{
	ImGui::GetForegroundDrawList()->AddRectFilled(ImVec2(x, y - 1), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 0, 0);
	ImGui::GetForegroundDrawList()->AddRectFilled(ImVec2(x, y + 1), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 0, 0);
	ImGui::GetForegroundDrawList()->AddRectFilled(ImVec2(x - 1, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 0, 0);
	ImGui::GetForegroundDrawList()->AddRectFilled(ImVec2(x + 1, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 0, 0);
	ImGui::GetForegroundDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), 0, 0);
}
static void DrawFilledRectIMCol(int x, int y, int w, int h, ImU32 col)
{
	ImGui::GetForegroundDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), col, 0, 0);
}
static void DrawCircleFilled(int x, int y, int radius, RGBA* color, int segments)
{
	ImGui::GetForegroundDrawList()->AddCircleFilled(ImVec2(x, y), radius, ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), segments);
}
static void DrawCircle(int x, int y, int radius, RGBA* color, int segments)
{
	ImGui::GetForegroundDrawList()->AddCircle(ImVec2(x, y), radius, ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), segments);
}
static void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, RGBA* color, float thickne)
{
	ImGui::GetForegroundDrawList()->AddTriangle(ImVec2(x1, y1), ImVec2(x2, y2), ImVec2(x3, y3), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), thickne);
}
static void DrawTriangleFilled(int x1, int y1, int x2, int y2, int x3, int y3, RGBA* color)
{
	ImGui::GetForegroundDrawList()->AddTriangleFilled(ImVec2(x1, y1), ImVec2(x2, y2), ImVec2(x3, y3), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)));
}
static void DrawLine(int x1, int y1, int x2, int y2, RGBA* color, int thickness)
{
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), thickness);
}
static void DrawCornerBox(int x, int y, int w, int h, int borderPx, RGBA* color)
{
	DrawFilledRect(x + borderPx, y, w / 3, borderPx, color); //top 
	DrawFilledRect(x + w - w / 3 + borderPx, y, w / 3, borderPx, color); //top 
	DrawFilledRect(x, y, borderPx, h / 3, color); //left 
	DrawFilledRect(x, y + h - h / 3 + borderPx * 2, borderPx, h / 3, color); //left 
	DrawFilledRect(x + borderPx, y + h + borderPx, w / 3, borderPx, color); //bottom 
	DrawFilledRect(x + w - w / 3 + borderPx, y + h + borderPx, w / 3, borderPx, color); //bottom 
	DrawFilledRect(x + w + borderPx, y, borderPx, h / 3, color);//right 
	DrawFilledRect(x + w + borderPx, y + h - h / 3 + borderPx * 2, borderPx, h / 3, color);//right 
}

void gui::PeriodicTable(Element& a_x, bool& popup)
{
	ImGui::SetNextWindowPos(ImVec2(57, 79));
	ImGui::SetNextWindowSize(ImVec2(387, 222));
	ImGui::Begin("Periodic Table", &popup,
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoSavedSettings |
		ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_NoMove);

	//period 1
	gui::SelectElement(popup, a_x, Element(H), 5, 21);
	gui::SelectElement(popup, a_x, Element(He), 362, 21);

	//period 2
	gui::SelectElement(popup, a_x, Element(Li), 5, 42);
	gui::SelectElement(popup, a_x, Element(Be), 26, 42);
	gui::SelectElement(popup, a_x, Element(B), 257, 42);
	gui::SelectElement(popup, a_x, Element(C), 278, 42);
	gui::SelectElement(popup, a_x, Element(N), 299, 42);
	gui::SelectElement(popup, a_x, Element(O), 320, 42);
	gui::SelectElement(popup, a_x, Element(F), 341, 42);
	gui::SelectElement(popup, a_x, Element(Ne), 362, 42);

	//period 3
	gui::SelectElement(popup, a_x, Element(Na), 5, 63);
	gui::SelectElement(popup, a_x, Element(Mg), 26, 63);
	gui::SelectElement(popup, a_x, Element(Al), 257, 63);
	gui::SelectElement(popup, a_x, Element(Si), 278, 63);
	gui::SelectElement(popup, a_x, Element(P), 299, 63);
	gui::SelectElement(popup, a_x, Element(S), 320, 63);
	gui::SelectElement(popup, a_x, Element(Cl), 341, 63);
	gui::SelectElement(popup, a_x, Element(Ar), 362, 63);

	//period 4 (thank God for iteration)
	for (int i{ 19 }; i <= 36; i++)
		gui::SelectElement(popup, a_x, static_cast<Element>(i), (i - 19) * 21 + 5, 84);


	//period 5
	for (int i{ 37 }; i <= 54; i++)
		gui::SelectElement(popup, a_x, static_cast<Element>(i), (i - 37) * 21 + 5, 105);

	//period 6
	for (int i{55}; i <= static_cast<int>(Element(Rn)); i++)
		gui::SelectElement(popup, a_x, static_cast<Element>(i), (i - 55) * 21 + 5, 126);
	
	//period 7
	for (int i{static_cast<int>(Element(Fr))}; i <= static_cast<int>(Element(Og)); i++)
		gui::SelectElement(popup, a_x, static_cast<Element>(i), (i - static_cast<int>(Element(Fr))) * 21 + 5, 147);

	//Lanthanide Series
	for (int i{ static_cast<int>(Element(La)) }; i <= static_cast<int>(Element(Yb)); i++)
		gui::SelectElement(popup, a_x, static_cast<Element>(i), (i - static_cast<int>(Element(La))) * 21 + 47, 173);

	//Actinide Series
	for (int i{ static_cast<int>(Element(Ac)) }; i <= static_cast<int>(Element(No)); i++)
		gui::SelectElement(popup, a_x, static_cast<Element>(i), (i - static_cast<int>(Element(Ac))) * 21 + 47, 194);

	ImGui::End();
}

void gui::SelectElement(bool& popup, Element& a_x, Element element, int x, int y)
{
	ImGui::SetCursorPos(ImVec2(x, y));
	if (ImGui::Button(gui::ElementName(element), ImVec2(20, 20)))
	{
		a_x = element;
		popup = false;
	}
}

const char* gui::ElementName(Element element)
{
	switch (element)
	{
	case (H): return "H";
	case (He): return "He";

	case (Li): return "Li";
	case (Be): return "Be";
	case (B): return "B";
	case (C): return "C";
	case (N): return "N";
	case (O): return "O";
	case (F): return "F";
	case (Ne): return "Ne";

	case (Na): return "Na";
	case (Mg): return "Mg";
	case (Al): return "Al";
	case (Si): return "Si";
	case (P): return "P";
	case (S): return "S";
	case (Cl): return "Cl";
	case (Ar): return "Ar";
		
	case (K): return "K";
	case (Ca): return "Ca";
	case (Sc): return "Sc";
	case (Ti): return "Ti";
	case (V): return "V";
	case (Cr): return "Cr";
	case (Mn): return "Mn";
	case (Fe): return "Fe";
	case (Co): return "Co";
	case (Ni): return "Ni";
	case (Cu): return "Cu";
	case (Zn): return "Zn";
	case (Ga): return "Ga";
	case (Ge): return "Ge";
	case (As): return "As";
	case (Se): return "Se";
	case (Br): return "Br";
	case (Kr): return "Kr";

	case (Rb): return "Rb";
	case (Sr): return "Sr";
	case (Y): return "Y";
	case (Zr): return "Zr";
	case (Nb): return "Nb";
	case (Mo): return "Mo";
	case (Tc): return "Tc";
	case (Ru): return "Ru";
	case (Rh): return "Rh";
	case (Pd): return "Pd";
	case (Ag): return "Ag";
	case (Cd): return "Cd";
	case (In): return "In";
	case (Sn): return "Sn";
	case (Sb): return "Sb";
	case (Te): return "Te";
	case (I): return "I";
	case (Xe): return "Xe";

	case (Cs): return "Cs";
	case (Ba): return "Ba";
	case (Lu): return "Lu";
	case (Hf): return "Hf";
	case (Ta): return "Ta";
	case (W): return "W";
	case (Re): return "Re";
	case (Os): return "Os";
	case (Ir): return "Ir";
	case (Pt): return "Pt";
	case (Au): return "Au";
	case (Hg): return "Hg";
	case (Tl): return "Tl";
	case (Pb): return "Pb";
	case (Bi): return "Bi";
	case (Po): return "Po";
	case (At): return "At";
	case (Rn): return "Rn";

	case (Fr): return "Fr";
	case (Ra): return "Ra";
	case (Lr): return "Lr";
	case (Rf): return "Rf";
	case (Db): return "Db";
	case (Sg): return "Sg";
	case (Bh): return "Bh";
	case (Hs): return "Hs";
	case (Mt): return "Mt";
	case (Ds): return "Ds";
	case (Rg): return "Rg";
	case (Cn): return "Cn";
	case (Nh): return "Nh";
	case (Fl): return "Fl";
	case (Mc): return "Mc";
	case (Lv): return "Lv";
	case (Ts): return "Ts";
	case (Og): return "Og";

	case (La): return "La";
	case (Ce): return "Ce";
	case (Pr): return "Pr";
	case (Nd): return "Nd";
	case (Pm): return "Pm";
	case (Sm): return "Sm";
	case (Eu): return "Eu";
	case (Gd): return "Gd";
	case (Tb): return "Tb";
	case (Dy): return "Dy";
	case (Ho): return "Ho";
	case (Er): return "Er";
	case (Tm): return "Tm";
	case (Yb): return "Yb";
	
	case (Ac): return "Ac";
	case (Th): return "Th";
	case (Pa): return "Pa";
	case (U): return "U";
	case (Np): return "Np";
	case (Pu): return "Pu";
	case (Am): return "Am";
	case (Cm): return "Cm";
	case (Bk): return "Bk";
	case (Cf): return "Cf";
	case (Es): return "Es";
	case (Fm): return "Fm";
	case (Md): return "Md";
	case (No): return "No";

	default: return "Undefined";
	}
}


extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(
	HWND window,
	UINT message,
	WPARAM wideParameter,
	LPARAM longParameter
);

long __stdcall WindowProcess(
	HWND window,
	UINT message,
	WPARAM wideParameter,
	LPARAM longParameter)
{
	if (ImGui_ImplWin32_WndProcHandler(window, message, wideParameter, longParameter))
		return true;

	switch (message)
	{
	case WM_SIZE: {
		if (gui::device && wideParameter != SIZE_MINIMIZED)
		{
			gui::presentParameters.BackBufferWidth = LOWORD(longParameter);
			gui::presentParameters.BackBufferHeight = HIWORD(longParameter);
			gui::ResetDevice();
		}
	}return 0;

	case WM_SYSCOMMAND: {
		if ((wideParameter & 0xfff0) == SC_KEYMENU)
			return 0;
	}break;

	case WM_DESTROY: {
		PostQuitMessage(0);
	}return 0;

	case WM_LBUTTONDOWN: {
		gui::position = MAKEPOINTS(longParameter);
	}return 0;

	case WM_MOUSEMOVE: {
		if (wideParameter == MK_LBUTTON)
		{
			const auto points = MAKEPOINTS(longParameter);
			auto rect = RECT();

			GetWindowRect(gui::window, &rect);

			rect.left += points.x - gui::position.x;
			rect.top += points.y - gui::position.y;

			if (gui::position.x >= 0 &&
				gui::position.x <= gui::WIDTH &&
				gui::position.y >= 0 && gui::position.y <= 19)
				SetWindowPos(
					gui::window,
					HWND_TOPMOST,
					rect.left,
					rect.top,
					0, 0,
					SWP_SHOWWINDOW | SWP_NOSIZE | SWP_NOZORDER
				);
		}
	}
	}
	return DefWindowProcW(window, message, wideParameter, longParameter);
}

void gui::CreateHWindow(
	const char* windowName,
	const char* className) noexcept
{
	windowClass.cbSize = sizeof(WNDCLASSEXA);
	windowClass.style = CS_CLASSDC;
	windowClass.lpfnWndProc = WindowProcess;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = GetModuleHandleA(0);
	windowClass.hIcon = 0;
	windowClass.hCursor = 0;
	windowClass.hbrBackground = 0;
	windowClass.lpszMenuName = 0;
	windowClass.lpszClassName = className;
	windowClass.hIconSm = 0;

	RegisterClassExA(&windowClass);

	window = CreateWindowA(
		className,
		windowName,
		WS_POPUP,
		100,
		100,
		WIDTH,
		HEIGHT,
		0,
		0,
		windowClass.hInstance,
		0
		);

	ShowWindow(window, SW_SHOWDEFAULT);
	UpdateWindow(window);
}

void gui::DestroyWindow() noexcept
{
	DestroyWindow(window);
	UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
}

bool gui::CreateDevice() noexcept
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);

	if (!d3d)
		return false;

	ZeroMemory(&presentParameters, sizeof(presentParameters));

	presentParameters.Windowed = TRUE;
	presentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	presentParameters.BackBufferFormat = D3DFMT_UNKNOWN;
	presentParameters.EnableAutoDepthStencil = TRUE;
	presentParameters.AutoDepthStencilFormat = D3DFMT_D16;
	presentParameters.PresentationInterval = D3DPRESENT_INTERVAL_ONE;

	if (d3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		window,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&presentParameters,
		&device) < 0)
		return false;
	
	return true;
}

void gui::ResetDevice() noexcept
{
	ImGui_ImplDX9_InvalidateDeviceObjects();

	const auto result = device->Reset(&presentParameters);

	if (result == D3DERR_INVALIDCALL)
		IM_ASSERT(0);

	ImGui_ImplDX9_CreateDeviceObjects();
}

void gui::DestroyDevice() noexcept
{
	if (device)
	{
		device->Release();
		device = nullptr;
	}

	if (d3d)
	{
		d3d->Release();
		d3d = nullptr;
	}
}

void gui::CreatImGui() noexcept
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ::ImGui::GetIO();

	io.IniFilename = NULL;

	ImGui::StyleColorsDark();

	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX9_Init(device);
}

void gui::DestroyImGui() noexcept
{
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}

void gui::BeginRender() noexcept
{
	MSG message;
	while (PeekMessage(&message, 0, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
}

void gui::EndRender() noexcept 
{
	ImGui::EndFrame();

	device->SetRenderState(D3DRS_ZENABLE, FALSE);
	device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
	device->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);

	device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_RGBA(0, 0, 0, 255), 1.0f, 0);

	if (device->BeginScene() >= 0)
	{
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		device->EndScene();
	}

	const auto result = device->Present(0, 0, 0, 0);

	if (result == D3DERR_DEVICELOST && device->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
		ResetDevice();
}

void gui::Render() noexcept
{
	ImGui::SetNextWindowPos({ 0, 0 });
	ImGui::SetNextWindowSize({ WIDTH, HEIGHT });
	ImGui::Begin(
		"Molecule Symmetry Identifier",
		&exit,
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoSavedSettings |
		ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_MenuBar |
		ImGuiWindowFlags_NoMove
	);

	static bool pressedIdentify = false;
	static Structure geometry{ Linear };
	static Structure currentGeom{ Linear };


	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("Geometry"))
		{
			if (ImGui::MenuItem("Linear", "")) { currentGeom = Linear; }
			if (ImGui::MenuItem("Trigonal Planar", "")) { currentGeom = Trigonal_planar; }
			if (ImGui::MenuItem("Tetrahedral", "")) { currentGeom = Tetrahedral; }
			if (ImGui::MenuItem("Trigonal Bipyramidal", "")) { currentGeom = Trigonal_bipyramidal; }
			if (ImGui::MenuItem("Octahedral", "")) { currentGeom = Octahedral; }
			ImGui::EndMenu();
		}
		ImGui::EndMenuBar();
	}


	static bool popup = false;

	static Element a_1{ H };
	static Element a_2{ H };
	static Element a_3{ H };
	static Element a_4{ H };
	static Element a_5{ H };
	static Element a_6{ H };

	static Element* currentBasis{ &a_1 };

	RGBA colour{40, 40, 40, 255};


	switch (currentGeom)
	{
	case (Linear): {

		if (!popup)
			DrawLine(160, 190, 340, 190, &colour, 10);

		ImGui::SetCursorPos(ImVec2(120, 175));
		if (ImGui::Button((std::string(gui::ElementName(a_1)) + "##1").c_str(), ImVec2(30, 30)))
		{
			currentBasis = &a_1;
			popup = true;
		}

		ImGui::SetCursorPos(ImVec2(350, 175));
		if (ImGui::Button((std::string(gui::ElementName(a_2)) + "##2").c_str(), ImVec2(30, 30)))
		{
			currentBasis = &a_2;
			popup = true;
		}

	} break;
	case (Trigonal_planar): {

		if (!popup)
		{
			DrawLine(250, 190, 250, 100, &colour, 10); //a1

			DrawLine(250, 190, 328, 235, &colour, 10); //a2

			DrawLine(250, 190, 172, 235, &colour, 10); //a3
		}

		ImGui::SetCursorPos(ImVec2(235, 60));
		if (ImGui::Button((std::string(gui::ElementName(a_1)) + "##1").c_str(), ImVec2(30, 30)))
		{
			currentBasis = &a_1;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(335, 233));
		if (ImGui::Button((std::string(gui::ElementName(a_2)) + "##2").c_str(), ImVec2(30, 30)))
		{
			currentBasis = &a_2;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(135, 233));
		if (ImGui::Button((std::string(gui::ElementName(a_3)) + "##3").c_str(), ImVec2(30, 30)))
		{
			currentBasis = &a_3;
			popup = true;
		}
	} break;
	case (Tetrahedral): {

		if (!popup)
		{
			DrawLine(250, 190, 250, 100, &colour, 10); //a1

			DrawLine(250, 190, 335, 220, &colour, 10); //a2

			DrawLine(250, 190, 191, 258, &colour, 10); //a3

			DrawLine(250, 190, 165, 221, &colour, 10); //a4
		}
		
		ImGui::SetCursorPos(ImVec2(235, 60));
		if (ImGui::Button((std::string(gui::ElementName(a_1)) + "##1").c_str(), ImVec2(30, 30)))
		{
			currentBasis = &a_1;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(343, 213));
		if (ImGui::Button((std::string(gui::ElementName(a_2)) + "##2").c_str(), ImVec2(30, 30)))
		{
			currentBasis = &a_2;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(159, 262));
		if (ImGui::Button((std::string(gui::ElementName(a_3)) + "##3").c_str(), ImVec2(30, 30)))
		{
			currentBasis = &a_3;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(127, 215));
		if (ImGui::Button((std::string(gui::ElementName(a_4)) + "##4").c_str(), ImVec2(30, 30)))
		{
			currentBasis = &a_4;
			popup = true;
		}
	} break;
	case (Trigonal_bipyramidal): {

		if (!popup)
		{
			DrawLine(250, 190, 250, 100, &colour, 10); //a1

			DrawLine(250, 190, 340, 190, &colour, 10); //a2

			DrawLine(250, 190, 250, 280, &colour, 10); //a5

			DrawLine(250, 190, 165, 159, &colour, 10); //a3 set as 70 degrees counterclockwise from a1

			DrawLine(250, 190, 165, 221, &colour, 10); //a4 set as 110 degrees counterclockwise from a1
		}

		ImGui::SetCursorPos(ImVec2(235, 60));
		if (ImGui::Button((std::string(gui::ElementName(a_1)) + "##1").c_str(), ImVec2(30, 30)))
		{
			currentBasis = &a_1;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(350, 175));
		if (ImGui::Button((std::string(gui::ElementName(a_2)) + "##2").c_str(), ImVec2(30, 30)))
		{
			currentBasis = &a_2;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(127, 137));
		if (ImGui::Button((std::string(gui::ElementName(a_3)) + "##3").c_str(), ImVec2(30, 30)))
		{
			currentBasis = &a_3;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(127, 213));
		if (ImGui::Button((std::string(gui::ElementName(a_4)) + "##4").c_str(), ImVec2(30, 30)))
		{
			currentBasis = &a_4;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(235, 290));
		if (ImGui::Button((std::string(gui::ElementName(a_5)) + "##5").c_str(), ImVec2(30, 30)))
		{
			currentBasis = &a_5;
			popup = true;
		}
	} break;
	case (Octahedral): {

		if (!popup)
		{
			DrawLine(250, 190, 250, 100, &colour, 10); //a1

			DrawLine(250, 190, 250, 280, &colour, 10); //a6

			DrawLine(250, 190, 335, 159, &colour, 10); //a2 set as 70 degrees clockwise from a1

			DrawLine(250, 190, 335, 221, &colour, 10); //a3 set as 110 degrees clockwise from a1

			DrawLine(250, 190, 165, 159, &colour, 10); //a5 set as 70 degrees counterclockwise from a1

			DrawLine(250, 190, 165, 221, &colour, 10); //a4 set as 110 degrees counterclockwise from a1
		}

		ImGui::SetCursorPos(ImVec2(235, 60));
		if (ImGui::Button((std::string(gui::ElementName(a_1)) + "##1").c_str(), ImVec2(30, 30)))
		{
			currentBasis = &a_1;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(343, 137));
		if (ImGui::Button((std::string(gui::ElementName(a_2)) + "##2").c_str(), ImVec2(30, 30)))
		{
			currentBasis = &a_2;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(343, 213));
		if (ImGui::Button((std::string(gui::ElementName(a_3)) + "##3").c_str(), ImVec2(30, 30)))
		{
			currentBasis = &a_3;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(127, 137));
		if (ImGui::Button((std::string(gui::ElementName(a_4)) + "##4").c_str(), ImVec2(30, 30)))
		{
			currentBasis = &a_4;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(127, 213));
		if (ImGui::Button((std::string(gui::ElementName(a_5)) + "##5").c_str(), ImVec2(30, 30)))
		{
			currentBasis = &a_5;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(235, 290));
		if (ImGui::Button((std::string(gui::ElementName(a_6)) + "##6").c_str(), ImVec2(30, 30)))
		{
			currentBasis = &a_6;
			popup = true;
		}
	} break;
	}

	if (popup)
	{
		gui::PeriodicTable(*currentBasis, popup);
	}

	/*
	
	static char a_1[2];
	static char a_2[2];
	static char a_3[2];
	static char a_4[2];
	static char a_5[2];
	static char a_6[2];
	
	switch (currentGeom)
	{
	case (Linear): {
		ImGui::PushItemWidth(15);
		ImGui::InputText("Atom 1", a_1, 2);
		ImGui::PushItemWidth(15);
		ImGui::InputText("Atom 2", a_2, 2);
		break;
	}
	case (Trigonal_planar): {
		ImGui::PushItemWidth(15);
		ImGui::InputText("Atom 1", a_1, 2);
		ImGui::PushItemWidth(15);
		ImGui::InputText("Atom 2", a_2, 2);
		ImGui::PushItemWidth(15);
		ImGui::InputText("Atom 3", a_3, 2);
		break;
	}
	case (Tetrahedral): {
		ImGui::PushItemWidth(15);
		ImGui::InputText("Atom 1", a_1, 2);
		ImGui::PushItemWidth(15);
		ImGui::InputText("Atom 2", a_2, 2);
		ImGui::PushItemWidth(15);
		ImGui::InputText("Atom 3", a_3, 2);
		ImGui::PushItemWidth(15);
		ImGui::InputText("Atom 4", a_4, 2);
		break;
	}
	case (Trigonal_bipyramidal): {
		ImGui::PushItemWidth(15);
		ImGui::InputText("Atom 1", a_1, 2);
		ImGui::PushItemWidth(15);
		ImGui::InputText("Atom 2", a_2, 2);
		ImGui::PushItemWidth(15);
		ImGui::InputText("Atom 3", a_3, 2);
		ImGui::PushItemWidth(15);
		ImGui::InputText("Atom 4", a_4, 2);
		ImGui::PushItemWidth(15);
		ImGui::InputText("Atom 5", a_5, 2);
		break;
	}
	case (Octahedral): {
		ImGui::PushItemWidth(15);
		ImGui::InputText("Atom 1", a_1, 2);
		ImGui::PushItemWidth(15);
		ImGui::InputText("Atom 2", a_2, 2);
		ImGui::PushItemWidth(15);
		ImGui::InputText("Atom 3", a_3, 2);
		ImGui::PushItemWidth(15);
		ImGui::InputText("Atom 4", a_4, 2);
		ImGui::PushItemWidth(15);
		ImGui::InputText("Atom 5", a_5, 2);
		ImGui::PushItemWidth(15);
		ImGui::InputText("Atom 6", a_6, 2);
		break;
	}
	}
	*/
	static Vector<2> linearVector{};
	static Vector<3> trigonalPlanarVector{};
	static Vector<4> tetrahedralVector{};
	static Vector<5> trigonalBipyramidalVector{};
	static Vector<6> octahedralVector{};


	ImGui::SetCursorPos(ImVec2(gui::WIDTH - 90, gui::HEIGHT - 30));
	if (ImGui::Button("Identify", ImVec2(80, 20)))
	{
		pressedIdentify = true;
		geometry = currentGeom;

		switch (geometry)
		{
		case (Linear): {
			linearVector = Vector<2>({ static_cast<int>(a_1), static_cast<int>(a_2) });
		} break;
		case (Trigonal_planar): {
			trigonalPlanarVector = Vector<3>({ static_cast<int>(a_1), static_cast<int>(a_2), static_cast<int>(a_3) });
		} break;
		case (Tetrahedral): {
			tetrahedralVector = Vector<4>({ static_cast<int>(a_1), static_cast<int>(a_2), static_cast<int>(a_3), static_cast<int>(a_4) });
		} break;
		case (Trigonal_bipyramidal): {
			trigonalBipyramidalVector = Vector<5>({ static_cast<int>(a_1), static_cast<int>(a_2), static_cast<int>(a_3), static_cast<int>(a_4), static_cast<int>(a_5) });
		} break;
		case (Octahedral):
			octahedralVector = Vector<6>({ static_cast<int>(a_1), static_cast<int>(a_2), static_cast<int>(a_3), static_cast<int>(a_4), static_cast<int>(a_5), static_cast<int>(a_6) });
		}
	}

	/*
	ImGui::SetCursorPos(ImVec2(gui::WIDTH - 90, gui::HEIGHT - 30));
	if (ImGui::Button("Identify", ImVec2(80, 20)))
	{
		pressedIdentify = true;
		geometry = currentGeom;

		switch (geometry)
		{
		case (Linear): {
			linearVector = Vector<2>({ static_cast<int>(a_1[0]), static_cast<int>(a_2[0]) });
		} break;
		case (Trigonal_planar):{
			trigonalPlanarVector = Vector<3>( { static_cast<int>(a_1[0]), static_cast<int>(a_2[0]), static_cast<int>(a_3[0]) });
		} break;
		case (Tetrahedral): {
			tetrahedralVector = Vector<4>({ static_cast<int>(a_1[0]), static_cast<int>(a_2[0]), static_cast<int>(a_3[0]), static_cast<int>(a_4[0]) });
		} break;
		case (Trigonal_bipyramidal): {
			trigonalBipyramidalVector = Vector<5>({ static_cast<int>(a_1[0]), static_cast<int>(a_2[0]), static_cast<int>(a_3[0]), static_cast<int>(a_4[0]), static_cast<int>(a_5[0]) });
		} break;
		case (Octahedral):
			octahedralVector = Vector<6>({ static_cast<int>(a_1[0]), static_cast<int>(a_2[0]), static_cast<int>(a_3[0]), static_cast<int>(a_4[0]), static_cast<int>(a_5[0]), static_cast<int>(a_6[0])});
		}
	}
	*/
	if (pressedIdentify) 
	{
		switch (geometry)
		{
		case (Linear):
		{
			Group pointGroup{ linear_identifier(linearVector) };
			ImGui::SetCursorPos(ImVec2( 10, gui::HEIGHT - 27));
			ImGui::Text(GroupName(pointGroup), ImVec2(100, 20));
			break;
		}
		case (Trigonal_planar):
		{
			Group pointGroup{ trigonal_planar_identifier(trigonalPlanarVector) };
			ImGui::SetCursorPos(ImVec2(10, gui::HEIGHT - 27));
			ImGui::Text(GroupName(pointGroup));
			break;
		}
		case (Tetrahedral):
		{
			Group pointGroup{ tetrahedral_identifier(tetrahedralVector) };
			ImGui::SetCursorPos(ImVec2(10, gui::HEIGHT - 27));
			ImGui::Text(GroupName(pointGroup));
			break;
		}
		case (Trigonal_bipyramidal):
		{
			Group pointGroup{ trigonal_bipyramidal_identifier(trigonalBipyramidalVector) };
			ImGui::SetCursorPos(ImVec2(10, gui::HEIGHT - 27));
			ImGui::Text(GroupName(pointGroup));
			break;
		}
		case (Octahedral):
		{
			Group pointGroup{ octahedral_identifier(octahedralVector) };
			ImGui::SetCursorPos(ImVec2(10, gui::HEIGHT - 27));
			ImGui::Text(GroupName(pointGroup));
			break;
		}
		}
	}

	ImGui::End();
}