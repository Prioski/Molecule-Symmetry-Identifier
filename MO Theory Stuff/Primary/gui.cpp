#include "gui.h"

#include "../Imgui/imgui.h"
#include "../Imgui/imgui_impl_dx9.h"
#include "../Imgui/imgui_impl_win32.h"
#include "identifier.h"

void gui::PeriodicTable(Element& a_x, bool& popup)
{
	ImGui::SetNextWindowPos(ImVec2(25, 25));
	ImGui::SetNextWindowSize(ImVec2(387, 213));
	ImGui::Begin("periodic table", &popup,
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoSavedSettings |
		ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_NoMove);


	gui::SelectElement(popup, a_x, Element(H), 5, 21);
	gui::SelectElement(popup, a_x, Element(He), 362, 21);

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
	case (Li): return "Li";
	case (He): return "He";
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
			if (ImGui::MenuItem("Linear", "Ctrl+2")) { currentGeom = Linear; }
			if (ImGui::MenuItem("Trigonal Planar", "Ctrl+3")) { currentGeom = Trigonal_planar; }
			if (ImGui::MenuItem("Tetrahedral", "Ctrl+4")) { currentGeom = Tetrahedral; }
			if (ImGui::MenuItem("Trigonal Bipyramidal", "Ctrl+5")) { currentGeom = Trigonal_bipyramidal; }
			if (ImGui::MenuItem("Octahedral", "Ctrl+6")) { currentGeom = Octahedral; }
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

	static Element* currentBasis{ &a_2 };

	switch (currentGeom)
	{
	case (Linear): {

		ImGui::SetCursorPos(ImVec2(20, 200));
		if (ImGui::Button(gui::ElementName(a_1), ImVec2(30, 30)))
		{
			currentBasis = &a_1;
			popup = true;
		}

		ImGui::SetCursorPos(ImVec2(WIDTH-50, 200));
		if (ImGui::Button(gui::ElementName(a_2), ImVec2(30, 30)))
		{
			currentBasis = &a_2;
			popup = true;
		}

	} break;
	case (Trigonal_planar): {
		ImGui::SetCursorPos(ImVec2(20, 200));
		if (ImGui::Button(gui::ElementName(a_1), ImVec2(30, 30)))
		{
			currentBasis = &a_1;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(WIDTH - 50, 200));
		if (ImGui::Button(gui::ElementName(a_2), ImVec2(30, 30)))
		{
			currentBasis = &a_2;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(200, 50));
		if (ImGui::Button(gui::ElementName(a_3), ImVec2(30, 30)))
		{
			currentBasis = &a_3;
			popup = true;
		}
	} break;
	case (Tetrahedral): {
		ImGui::SetCursorPos(ImVec2(20, 200));
		if (ImGui::Button(gui::ElementName(a_1), ImVec2(30, 30)))
		{
			currentBasis = &a_1;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(WIDTH - 50, 200));
		if (ImGui::Button(gui::ElementName(a_2), ImVec2(30, 30)))
		{
			currentBasis = &a_2;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(200, 50));
		if (ImGui::Button(gui::ElementName(a_3), ImVec2(30, 30)))
		{
			currentBasis = &a_3;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(200, 300));
		if (ImGui::Button(gui::ElementName(a_4), ImVec2(30, 30)))
		{
			currentBasis = &a_4;
			popup = true;
		}
	} break;
	case (Trigonal_bipyramidal): {
		ImGui::SetCursorPos(ImVec2(20, 200));
		if (ImGui::Button(gui::ElementName(a_1), ImVec2(30, 30)))
		{
			currentBasis = &a_1;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(WIDTH - 50, 200));
		if (ImGui::Button(gui::ElementName(a_2), ImVec2(30, 30)))
		{
			currentBasis = &a_2;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(200, 50));
		if (ImGui::Button(gui::ElementName(a_3), ImVec2(30, 30)))
		{
			currentBasis = &a_3;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(200, 300));
		if (ImGui::Button(gui::ElementName(a_4), ImVec2(30, 30)))
		{
			currentBasis = &a_4;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(100, 100));
		if (ImGui::Button(gui::ElementName(a_5), ImVec2(30, 30)))
		{
			currentBasis = &a_5;
			popup = true;
		}
	} break;
	case (Octahedral): {
		ImGui::SetCursorPos(ImVec2(20, 200));
		if (ImGui::Button(gui::ElementName(a_1), ImVec2(30, 30)))
		{
			currentBasis = &a_1;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(WIDTH - 50, 200));
		if (ImGui::Button(gui::ElementName(a_2), ImVec2(30, 30)))
		{
			currentBasis = &a_2;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(200, 50));
		if (ImGui::Button(gui::ElementName(a_3), ImVec2(30, 30)))
		{
			currentBasis = &a_3;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(200, 300));
		if (ImGui::Button(gui::ElementName(a_4), ImVec2(30, 30)))
		{
			currentBasis = &a_4;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(100, 100));
		if (ImGui::Button(gui::ElementName(a_5), ImVec2(30, 30)))
		{
			currentBasis = &a_5;
			popup = true;
		}
		ImGui::SetCursorPos(ImVec2(100, 300));
		if (ImGui::Button(gui::ElementName(a_6), ImVec2(30, 30)))
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