#pragma once
#pragma comment(linker,"\"/manifestdependency:type='win32' \ name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <windowsx.h>
#include<exception>
#include<string>
#include<algorithm>
#include<fstream>


class App
{
	enum class BUT_ID
	{
		SEND,
		BACK,
		CANCEL,
		CB_LADDER,
		EDIT_LADDER,
		CB_BUS,
		EDIT_BUS,
		CB_SUP,
		EDIT_SUP,
		CB_LAUNCH,
		EDIT_LAUNCH,
		CB_WATER,
		EDIT_WATER,
		CB_STEP,
		EDIT_STEP,
		CB_FUEL,
		EDIT_FUEL,
		CB_HEAT,
		EDIT_HEAT,
		CB_OIL,
		EDIT_OIL,
		CB_DEICE,
		EDIT_DEICE,
		CB_LOADER,
		EDIT_LOADER,
		EDIT_AIRCRAFT,
		EDIT_PLACE,
		EDIT_BOARD
	};

public:
	explicit App();
	~App();

	int Run();

private:
	void init_window();
	void create_controls();

	static LRESULT CALLBACK aplication_proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK win_proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
	const std::wstring AppName{ L"Pulkovo ne horosho" }, ClassName{ L"App" };
	HWND hwnd{}, back{}, send{}, cancel{}, cbLadder{}, editLadder{}, cbBus{}, editBus{}, cbSup{}, editSup{}, cbLaunch{}, editLaunch{}, cbWater{}, editWater{}, cbStep{}, editStep{},
		cbFuel{}, editFuel{}, cbHeat{}, editHeat{}, cbOil{}, editOil{}, cbDeIce{}, editDeIce{}, cbLoader{}, editLoader{}, boadNum{}, aircraft{}, place{};
	PAINTSTRUCT ps{};
	RECT Rect{};
	HDC hdc{}, hCmpDC{};
	HBITMAP hBmp{};
	const int AppWeigh{ 500 }, AppHeigth{ 720 };
};

