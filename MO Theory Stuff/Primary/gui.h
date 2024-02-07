#pragma once
#include <d3d9.h>
#include "identifier.h"


namespace gui
{
	constexpr int WIDTH = 500;
	constexpr int HEIGHT = 400;

	inline bool exit = true;

	inline HWND window = nullptr;
	inline WNDCLASSEXA windowClass = {};

	inline POINTS position = {};

	inline PDIRECT3D9 d3d = nullptr;
	inline LPDIRECT3DDEVICE9 device = nullptr;
	inline D3DPRESENT_PARAMETERS presentParameters = {};

	void CreateHWindow(
		const char* windowName,
		const char* className) noexcept;
	void DestroyWindow() noexcept;

	bool CreateDevice() noexcept;
	void ResetDevice() noexcept;
	void DestroyDevice() noexcept;

	void CreatImGui() noexcept;
	void DestroyImGui() noexcept;

	void BeginRender() noexcept;
	void EndRender() noexcept;
	void Render() noexcept;

	//Options

	void PeriodicTable(Element& a_x, bool& popup);
	void SelectElement(bool& popup, Element& a_x, Element element, int x, int y);
	const char* ElementName(Element element = Element(Li));
}
