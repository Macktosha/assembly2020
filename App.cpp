#include "App.h"
#include <stdexcept>



App::App()
{
	using std::string;
	using std::wstring;
	try
	{
		this->init_window();
		this->create_controls();
	}
	catch (const std::exception & e)
	{
		string expt_data = e.what();

		MessageBox(nullptr, wstring(begin(expt_data), end(expt_data)).c_str(), L"Error", MB_ICONERROR | MB_OK);
		ExitProcess(EXIT_FAILURE);
	}
}

App::~App()
{
}

int App::Run()
{
	MSG msg{};
	ShowWindow(this->hwnd, SW_SHOWDEFAULT);
	UpdateWindow(this->hwnd);

	while (GetMessage(&msg, nullptr, NULL, NULL)) {
		DispatchMessage(&msg);
		TranslateMessage(&msg);
	}
	return static_cast<int>(msg.wParam);
}

void App::init_window()
{
	using std::runtime_error;
	using namespace std::string_literals;

	WNDCLASSEX wc{ sizeof(WNDCLASSEX) };
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hInstance = GetModuleHandle(nullptr);
	wc.lpfnWndProc = App::aplication_proc;
	wc.lpszClassName = this->ClassName.c_str();
	wc.lpszMenuName = nullptr;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc))
		throw runtime_error("Error, can't register window class!");

	RECT windowRC{ 0, 0, this->AppWeigh, this->AppHeigth };
	AdjustWindowRect(&windowRC, WS_OVERLAPPEDWINDOW, false);

	if (!(this->hwnd = CreateWindowEx(0,
		wc.lpszClassName,
		this->AppName.c_str(),
		WS_DLGFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MINIMIZE,
		(GetSystemMetrics(SM_CXSCREEN) - windowRC.right) / 2,
		(GetSystemMetrics(SM_CXSCREEN) - windowRC.bottom) / 4,
		windowRC.right, windowRC.bottom,
		nullptr, nullptr, nullptr, this)))
		throw runtime_error("Error, can't create main window");
}

void App::create_controls()
{
	using std::runtime_error;
	using namespace std::string_literals;

	if (!(this->send = CreateWindowEx(0, L"Button", L"SEND",
		WS_CHILD | WS_VISIBLE,
		this->AppWeigh - 150, this->AppHeigth - 100, 70, 40,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::SEND), nullptr, nullptr)))
		throw runtime_error("Error, can't create button");

	if (!(this->cancel = CreateWindowEx(0, L"Button", L"CANCEL",
		WS_CHILD | WS_VISIBLE,
		this->AppWeigh - 450, this->AppHeigth - 100, 70, 40,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::CANCEL), nullptr, nullptr)))
		throw runtime_error("Error, can't create button");

	//****


	if (!CreateWindowEx(0, L"static", L"Ladder",
		WS_CHILD | WS_VISIBLE,
		this->AppWeigh - 450, this->AppHeigth - 700, 70, 25,
		this->hwnd, nullptr, nullptr, nullptr))
		throw runtime_error("Error, can't create button");

	if (!(this->cbLadder = CreateWindowEx(0, L"combobox", L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWN,
		this->AppWeigh - 300, this->AppHeigth - 700, 70, 40,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::CB_LADDER), nullptr, nullptr)))
		throw runtime_error("Error, can't create button");
	SendMessage(cbLadder, CB_ADDSTRING, 0, (LPARAM)L"Yes");
	SendMessage(cbLadder, CB_ADDSTRING, 0, (LPARAM)L"No");
	SendMessage(cbLadder, CB_SETCURSEL, 1, 0);

	/*if (!(this->editLadder = CreateWindowEx(0, L"Edit", L"",
		WS_CHILD | WS_BORDER | WS_VISIBLE | ES_NUMBER | ES_LEFT,
		this->AppWeigh - 150, this->AppHeigth - 700, 70, 25,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_LADDER), nullptr, nullptr)))
		throw runtime_error("Error, can't create x1 edit button");*/

	//*****

	if (!CreateWindowEx(0, L"static", L"Bus",
		WS_CHILD | WS_VISIBLE,
		this->AppWeigh - 450, this->AppHeigth - 670, 70, 25,
		this->hwnd, nullptr, nullptr, nullptr))
		throw runtime_error("Error, can't create button");

	if (!(this->cbBus = CreateWindowEx(0, L"combobox", L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWN,
		this->AppWeigh - 300, this->AppHeigth - 670, 70, 40,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::CB_BUS), nullptr, nullptr)))
		throw runtime_error("Error, can't create button");
	SendMessage(cbBus, CB_ADDSTRING, 0, (LPARAM)L"Yes");
	SendMessage(cbBus, CB_ADDSTRING, 0, (LPARAM)L"No");
	SendMessage(cbBus, CB_SETCURSEL, 1, 0);

	/*if (!(this->editBus = CreateWindowEx(0, L"Edit", L"",
		WS_CHILD | WS_BORDER | WS_VISIBLE | ES_NUMBER | ES_LEFT,
		this->AppWeigh - 150, this->AppHeigth - 670, 70, 25,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_BUS), nullptr, nullptr)))
		throw runtime_error("Error, can't create x1 edit button");*/

	/**/

	if (!CreateWindowEx(0, L"static", L"Launch",
		WS_CHILD | WS_VISIBLE,
		this->AppWeigh - 450, this->AppHeigth - 640, 70, 25,
		this->hwnd, nullptr, nullptr, nullptr))
		throw runtime_error("Error, can't create button");

	if (!(this->cbLaunch = CreateWindowEx(0, L"combobox", L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWN,
		this->AppWeigh - 300, this->AppHeigth - 640, 70, 40,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::CB_LAUNCH), nullptr, nullptr)))
		throw runtime_error("Error, can't create button");
	SendMessage(cbLaunch, CB_ADDSTRING, 0, (LPARAM)L"Yes");
	SendMessage(cbLaunch, CB_ADDSTRING, 0, (LPARAM)L"No");
	SendMessage(cbLaunch, CB_SETCURSEL, 1, 0);


	/*if (!(this->editLaunch = CreateWindowEx(0, L"Edit", L"",
		WS_CHILD | WS_BORDER | WS_VISIBLE | ES_NUMBER | ES_LEFT,
		this->AppWeigh - 150, this->AppHeigth - 640, 70, 25,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_LAUNCH), nullptr, nullptr)))
		throw runtime_error("Error, can't create x1 edit button");*/


	//***

	if (!(this->cbWater = CreateWindowEx(0, L"combobox", L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWN,
		this->AppWeigh - 300, this->AppHeigth - 610, 70, 40,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::CB_WATER), nullptr, nullptr)))
		throw runtime_error("Error, can't create button");
	SendMessage(cbWater, CB_ADDSTRING, 0, (LPARAM)L"Yes");
	SendMessage(cbWater, CB_ADDSTRING, 0, (LPARAM)L"No");
	SendMessage(cbWater, CB_SETCURSEL, 1, 0);

	/*if (!(this->editWater = CreateWindowEx(0, L"Edit", L"",
		WS_CHILD | WS_BORDER | WS_VISIBLE | ES_NUMBER | ES_LEFT,
		this->AppWeigh - 150, this->AppHeigth - 610, 70, 25,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_WATER), nullptr, nullptr)))
		throw runtime_error("Error, can't create x1 edit button");*/

	if (!CreateWindowEx(0, L"static", L"Water",
		WS_CHILD | WS_VISIBLE,
		this->AppWeigh - 450, this->AppHeigth - 610, 70, 25,
		this->hwnd, nullptr, nullptr, nullptr))
		throw runtime_error("Error, can't create button");

	/**/

	if (!(this->cbSup = CreateWindowEx(0, L"combobox", L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWN,
		this->AppWeigh - 300, this->AppHeigth - 580, 70, 40,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::CB_SUP), nullptr, nullptr)))
		throw runtime_error("Error, can't create button");
	SendMessage(cbSup, CB_ADDSTRING, 0, (LPARAM)L"Yes");
	SendMessage(cbSup, CB_ADDSTRING, 0, (LPARAM)L"No");
	SendMessage(cbSup, CB_SETCURSEL, 1, 0);

	if (!CreateWindowEx(0, L"static", L"Energy",
		WS_CHILD | WS_VISIBLE,
		this->AppWeigh - 450, this->AppHeigth - 580, 70, 25,
		this->hwnd, nullptr, nullptr, nullptr))
		throw runtime_error("Error, can't create button");

	/*if (!(this->editSup = CreateWindowEx(0, L"Edit", L"",
		WS_CHILD | WS_BORDER | WS_VISIBLE | ES_NUMBER | ES_LEFT,
		this->AppWeigh - 150, this->AppHeigth - 580, 70, 25,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_SUP), nullptr, nullptr)))
		throw runtime_error("Error, can't create edit button");*/

	/****/

	if (!(this->cbStep = CreateWindowEx(0, L"combobox", L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWN,
		this->AppWeigh - 300, this->AppHeigth - 550, 70, 40,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::CB_STEP), nullptr, nullptr)))
		throw runtime_error("Error, can't create button");
	SendMessage(cbStep, CB_ADDSTRING, 0, (LPARAM)L"Yes");
	SendMessage(cbStep, CB_ADDSTRING, 0, (LPARAM)L"No");
	SendMessage(cbStep, CB_SETCURSEL, 1, 0);

	if (!CreateWindowEx(0, L"static", L"Step lad.",
		WS_CHILD | WS_VISIBLE,
		this->AppWeigh - 450, this->AppHeigth - 550, 70, 25,
		this->hwnd, nullptr, nullptr, nullptr))
		throw runtime_error("Error, can't create button");

	/*if (!(this->editStep = CreateWindowEx(0, L"Edit", L"",
		WS_CHILD | WS_BORDER | WS_VISIBLE | ES_NUMBER | ES_LEFT,
		this->AppWeigh - 150, this->AppHeigth - 550, 70, 25,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_STEP), nullptr, nullptr)))
		throw runtime_error("Error, can't create edit button");*/

	//******

	if (!(this->cbFuel = CreateWindowEx(0, L"combobox", L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWN,
		this->AppWeigh - 300, this->AppHeigth - 520, 70, 40,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::CB_FUEL), nullptr, nullptr)))
		throw runtime_error("Error, can't create button");
	SendMessage(cbFuel, CB_ADDSTRING, 0, (LPARAM)L"Yes");
	SendMessage(cbFuel, CB_ADDSTRING, 0, (LPARAM)L"No");
	SendMessage(cbFuel, CB_SETCURSEL, 1, 0);

	if (!CreateWindowEx(0, L"static", L"Fuel",
		WS_CHILD | WS_VISIBLE,
		this->AppWeigh - 450, this->AppHeigth - 520, 70, 25,
		this->hwnd, nullptr, nullptr, nullptr))
		throw runtime_error("Error, can't create button");

	/*if (!(this->editFuel = CreateWindowEx(0, L"Edit", L"",
		WS_CHILD | WS_BORDER | WS_VISIBLE | ES_NUMBER | ES_LEFT,
		this->AppWeigh - 150, this->AppHeigth - 520, 70, 25,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_FUEL), nullptr, nullptr)))
		throw runtime_error("Error, can't create edit button");*/

	//*****
	if (!(this->cbHeat = CreateWindowEx(0, L"combobox", L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWN,
		this->AppWeigh - 300, this->AppHeigth - 490, 70, 40,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::CB_HEAT), nullptr, nullptr)))
		throw runtime_error("Error, can't create button");
	SendMessage(cbHeat, CB_ADDSTRING, 0, (LPARAM)L"Yes");
	SendMessage(cbHeat, CB_ADDSTRING, 0, (LPARAM)L"No");
	SendMessage(cbHeat, CB_SETCURSEL, 1, 0);

	if (!CreateWindowEx(0, L"static", L"Heat",
		WS_CHILD | WS_VISIBLE,
		this->AppWeigh - 450, this->AppHeigth - 490, 70, 25,
		this->hwnd, nullptr, nullptr, nullptr))
		throw runtime_error("Error, can't create button");

	/*if (!(this->editHeat = CreateWindowEx(0, L"Edit", L"",
		WS_CHILD | WS_BORDER | WS_VISIBLE | ES_NUMBER | ES_LEFT,
		this->AppWeigh - 150, this->AppHeigth - 490, 70, 25,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_HEAT), nullptr, nullptr)))
		throw runtime_error("Error, can't create edit button");*/

	/*OIL*/

	if (!(this->cbOil = CreateWindowEx(0, L"combobox", L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWN,
		this->AppWeigh - 300, this->AppHeigth - 460, 70, 40,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::CB_OIL), nullptr, nullptr)))
		throw runtime_error("Error, can't create button");
	SendMessage(cbOil, CB_ADDSTRING, 0, (LPARAM)L"Yes");
	SendMessage(cbOil, CB_ADDSTRING, 0, (LPARAM)L"No");
	SendMessage(cbOil, CB_SETCURSEL, 1, 0);

	if (!CreateWindowEx(0, L"static", L"Oil",
		WS_CHILD | WS_VISIBLE,
		this->AppWeigh - 450, this->AppHeigth - 460, 70, 25,
		this->hwnd, nullptr, nullptr, nullptr))
		throw runtime_error("Error, can't create button");

	/*if (!(this->editOil = CreateWindowEx(0, L"Edit", L"",
		WS_CHILD | WS_BORDER | WS_VISIBLE | ES_NUMBER | ES_LEFT,
		this->AppWeigh - 150, this->AppHeigth - 460, 70, 25,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_OIL), nullptr, nullptr)))
		throw runtime_error("Error, can't create edit button");*/

	//*DE-ICING

	if (!(this->cbDeIce = CreateWindowEx(0, L"combobox", L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWN,
		this->AppWeigh - 300, this->AppHeigth - 430, 70, 40,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::CB_DEICE), nullptr, nullptr)))
		throw runtime_error("Error, can't create button");
	SendMessage(cbDeIce, CB_ADDSTRING, 0, (LPARAM)L"Yes");
	SendMessage(cbDeIce, CB_ADDSTRING, 0, (LPARAM)L"No");
	SendMessage(cbDeIce, CB_SETCURSEL, 1, 0);

	if (!CreateWindowEx(0, L"static", L"De-Ice",
		WS_CHILD | WS_VISIBLE,
		this->AppWeigh - 450, this->AppHeigth - 430, 70, 25,
		this->hwnd, nullptr, nullptr, nullptr))
		throw runtime_error("Error, can't create button");

	/*if (!(this->editDeIce = CreateWindowEx(0, L"Edit", L"",
		WS_CHILD | WS_BORDER | WS_VISIBLE | ES_NUMBER | ES_LEFT,
		this->AppWeigh - 150, this->AppHeigth - 430, 70, 25,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_DEICE), nullptr, nullptr)))
		throw runtime_error("Error, can't create edit button");*/

	//**LOADER

	if (!(this->cbLoader = CreateWindowEx(0, L"combobox", L"",
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWN,
		this->AppWeigh - 300, this->AppHeigth - 400, 70, 40,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::CB_LOADER), nullptr, nullptr)))
		throw runtime_error("Error, can't create button");
	SendMessage(cbLoader, CB_ADDSTRING, 0, (LPARAM)L"Yes");
	SendMessage(cbLoader, CB_ADDSTRING, 0, (LPARAM)L"No");
	SendMessage(cbLoader, CB_SETCURSEL, 1, 0);

	if (!CreateWindowEx(0, L"static", L"Loader",
		WS_CHILD | WS_VISIBLE,
		this->AppWeigh - 450, this->AppHeigth - 400, 70, 25,
		this->hwnd, nullptr, nullptr, nullptr))
		throw runtime_error("Error, can't create button");

	/*if (!(this->editLoader = CreateWindowEx(0, L"Edit", L"",
		WS_CHILD | WS_BORDER | WS_VISIBLE | ES_NUMBER | ES_LEFT,
		this->AppWeigh - 150, this->AppHeigth - 400, 70, 25,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_LOADER), nullptr, nullptr)))
		throw runtime_error("Error, can't create edit button");*/

	//******
	if (!CreateWindowEx(0, L"static", L"Flight №",
		WS_CHILD | WS_VISIBLE,
		this->AppWeigh - 450, this->AppHeigth - 300, 70, 25,
		this->hwnd, nullptr, nullptr, nullptr))
		throw runtime_error("Error, can't create button");

	if (!(this->boadNum = CreateWindowEx(0, L"Edit", L"",
		WS_CHILD | WS_BORDER | WS_VISIBLE  | ES_LEFT,
		this->AppWeigh - 200, this->AppHeigth - 300, 100, 25,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_BOARD), nullptr, nullptr)))
		throw runtime_error("Error, can't create edit button");

	if (!CreateWindowEx(0, L"static", L"Aircraft",
		WS_CHILD | WS_VISIBLE,
		this->AppWeigh - 450, this->AppHeigth - 250, 70, 25,
		this->hwnd, nullptr, nullptr, nullptr))
		throw runtime_error("Error, can't create button");

	if (!(this->aircraft = CreateWindowEx(0, L"Edit", L"",
		WS_CHILD | WS_BORDER | WS_VISIBLE  | ES_LEFT,
		this->AppWeigh - 200, this->AppHeigth - 250, 100, 25,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_AIRCRAFT), nullptr, nullptr)))
		throw runtime_error("Error, can't create edit button");

	if (!CreateWindowEx(0, L"static", L"Place",
		WS_CHILD | WS_VISIBLE,
		this->AppWeigh - 450, this->AppHeigth - 200, 70, 25,
		this->hwnd, nullptr, nullptr, nullptr))
		throw runtime_error("Error, can't create button");

	if (!(this->place = CreateWindowEx(0, L"Edit", L"",
		WS_CHILD | WS_BORDER | WS_VISIBLE  | ES_LEFT,
		this->AppWeigh - 200, this->AppHeigth - 200, 100, 25,
		this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_PLACE), nullptr, nullptr)))
		throw runtime_error("Error, can't create edit button");


}

LRESULT App::aplication_proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	App* pApp;
	if (uMsg == WM_NCCREATE) {
		pApp = static_cast<App*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);
		SetLastError(0);
		if (!SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pApp))) {
			if (GetLastError() != 0)
				return false;
		}
	}
	else
	{
		pApp = reinterpret_cast<App*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
	}
	if (pApp)
	{
		pApp->hwnd = hwnd;
		return pApp->win_proc(hwnd, uMsg, wParam, lParam);
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

LRESULT App::win_proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_PAINT:
		{
			GetClientRect(hwnd, &Rect);
			hdc = BeginPaint(hwnd, &ps);

			// Создание теневого контекста для двойной буферизации
			hCmpDC = CreateCompatibleDC(hdc);
			hBmp = CreateCompatibleBitmap(hdc, Rect.right - Rect.left,
				Rect.bottom - Rect.top);
			SelectObject(hCmpDC, hBmp);

			// Закраска фоновым цветом
			LOGBRUSH br;
			br.lbStyle = BS_SOLID;
			br.lbColor = RGB(176, 226, 255);
			HBRUSH brush;
			brush = CreateBrushIndirect(&br);
			FillRect(hCmpDC, &Rect, brush);
			DeleteObject(brush);

			// Копируем изображение из теневого контекста на экран
			SetStretchBltMode(hdc, COLORONCOLOR);
			BitBlt(hdc, 0, 0, Rect.right - Rect.left, Rect.bottom - Rect.top, hCmpDC, 0, 0, SRCCOPY);

			// Удаляем объекты
			DeleteDC(hCmpDC);
			DeleteObject(hBmp);

			EndPaint(hwnd, &ps);
		}
		return 0;

		case WM_COMMAND:
		{
			switch (static_cast<App::BUT_ID>(LOWORD(wParam)))
			{
			case App::BUT_ID::SEND:

			{

				std::fstream file("svo.txt", std::ios::out);
				std::wstring text{};
				int x = 0;
				text.resize(MAX_PATH);

				int i = SendMessage(cbLadder, CB_GETCURSEL, 0, 0);

				x = 0;

				if (i == 1)
				{
					file << x << std::endl;

				}
				else {

					GetWindowText(this->editLadder, &text[0], MAX_PATH);
					text.erase(remove(begin(text), end(text), 0), end(text));
					x = std::stoi(text);

					file << x << std::endl;
				}
				text.erase(begin(text), end(text));

				/******/


				text.resize(MAX_PATH);
				i = SendMessage(cbBus, CB_GETCURSEL, 0, 0);

				x = 0;
				if (i == 1)
				{
					file << x << std::endl;

				}
				else {
					GetWindowText(this->editBus, &text[0], MAX_PATH);
					text.erase(remove(begin(text), end(text), 0), end(text));
					x = std::stoi(text);

					file << x << std::endl;
				}
				text.erase(begin(text), end(text));

				//***

				text.resize(MAX_PATH);
				i = SendMessage(cbLaunch, CB_GETCURSEL, 0, 0);

				x = 0;
				if (i == 1)
				{
					file << x << std::endl;

				}
				else {
					GetWindowText(this->editLaunch, &text[0], MAX_PATH);
					text.erase(remove(begin(text), end(text), 0), end(text));
					x = std::stoi(text);

					file << x << std::endl;
				}
				text.erase(begin(text), end(text));
				//******

				text.resize(MAX_PATH);
				i = SendMessage(cbSup, CB_GETCURSEL, 0, 0);

				x = 0;
				if (i == 1)
				{
					file << x << std::endl;

				}
				else {
					GetWindowText(this->editSup, &text[0], MAX_PATH);
					text.erase(remove(begin(text), end(text), 0), end(text));
					x = std::stoi(text);

					file << x << std::endl;
				}
				text.erase(begin(text), end(text));
				//****
				text.resize(MAX_PATH);
				i = SendMessage(cbWater, CB_GETCURSEL, 0, 0);

				x = 0;
				if (i == 1)
				{
					file << x << std::endl;

				}
				else {
					GetWindowText(this->editWater, &text[0], MAX_PATH);
					text.erase(remove(begin(text), end(text), 0), end(text));
					x = std::stoi(text);

					file << x << std::endl;
				}
				text.erase(begin(text), end(text));


				//***
				text.resize(MAX_PATH);
				i = SendMessage(cbStep, CB_GETCURSEL, 0, 0);

				x = 0;
				if (i == 1)
				{
					file << x << std::endl;

				}
				else {
					GetWindowText(this->editStep, &text[0], MAX_PATH);
					text.erase(remove(begin(text), end(text), 0), end(text));
					x = std::stoi(text);

					file << x << std::endl;
				}
				text.erase(begin(text), end(text));
				//****
				text.resize(MAX_PATH);
				i = SendMessage(cbFuel, CB_GETCURSEL, 0, 0);

				x = 0;
				if (i == 1)
				{
					file << x << std::endl;

				}
				else {
					GetWindowText(this->editFuel, &text[0], MAX_PATH);
					text.erase(remove(begin(text), end(text), 0), end(text));
					x = std::stoi(text);

					file << x << std::endl;
				}
				text.erase(begin(text), end(text));
				//****
				text.resize(MAX_PATH);
				i = SendMessage(cbHeat, CB_GETCURSEL, 0, 0);

				x = 0;
				if (i == 1)
				{
					file << x << std::endl;

				}
				else {
					GetWindowText(this->editHeat, &text[0], MAX_PATH);
					text.erase(remove(begin(text), end(text), 0), end(text));
					x = std::stoi(text);

					file << x << std::endl;
				}
				text.erase(begin(text), end(text));
				//******
				text.resize(MAX_PATH);
				i = SendMessage(cbOil, CB_GETCURSEL, 0, 0);

				x = 0;
				if (i == 1)
				{
					file << x << std::endl;

				}
				else {
					GetWindowText(this->editOil, &text[0], MAX_PATH);
					text.erase(remove(begin(text), end(text), 0), end(text));
					x = std::stoi(text);

					file << x << std::endl;
				}
				text.erase(begin(text), end(text));
				//*****
				text.resize(MAX_PATH);
				i = SendMessage(cbDeIce, CB_GETCURSEL, 0, 0);

				x = 0;
				if (i == 1)
				{
					file << x << std::endl;

				}
				else {
					GetWindowText(this->editDeIce, &text[0], MAX_PATH);
					text.erase(remove(begin(text), end(text), 0), end(text));
					x = std::stoi(text);

					file << x << std::endl;
				}
				text.erase(begin(text), end(text));
				//*****
				text.resize(MAX_PATH);
				i = SendMessage(cbLoader, CB_GETCURSEL, 0, 0);

				x = 0;
				if (i == 1)
				{
					file << x << std::endl;

				}
				else {
					GetWindowText(this->editLoader, &text[0], MAX_PATH);
					text.erase(remove(begin(text), end(text), 0), end(text));
					x = std::stoi(text);

					file << x << std::endl;
				}
				text.erase(begin(text), end(text));
				file.close();

				//***
				text.resize(MAX_PATH);
				GetWindowText(this->boadNum, &text[0], MAX_PATH);
				text.erase(remove(begin(text), end(text), 0), end(text));
				x = 0;
				if (text.empty())
				{

					MessageBox(this->hwnd, L"Fill flight #!", L"Information", MB_OK | MB_ICONINFORMATION);
					break;

				}
				else
				{

					std::wofstream f("svo1.txt", std::wios::out);
					f << text << std::endl;
					f.close();
				}
				text.erase(begin(text), end(text));

				text.resize(MAX_PATH);
				GetWindowText(this->aircraft, &text[0], MAX_PATH);
				text.erase(remove(begin(text), end(text), 0), end(text));
				x = 0;
				if (text.empty())
				{

					MessageBox(this->hwnd, L"Fill aircraft type #!", L"Information", MB_OK | MB_ICONINFORMATION);
					break;

				}
				else
				{

					std::wofstream f("svo1.txt", std::wios::app);
					f << text << std::endl;
					f.close();
				}
				text.erase(begin(text), end(text));


				text.resize(MAX_PATH);
				GetWindowText(this->place, &text[0], MAX_PATH);
				text.erase(remove(begin(text), end(text), 0), end(text));
				x = 0;
				if (text.empty())
				{

					MessageBox(this->hwnd, L"Fill place of an aircraft!", L"Information", MB_OK | MB_ICONINFORMATION);
					break;

				}
				else
				{

					std::wofstream f("svo1.txt", std::wios::app);
					f << text << std::endl;
					f.close();
				}
				text.erase(begin(text), end(text));
				MessageBox(this->hwnd, L"Await the response from air company", L"Information", MB_OK | MB_ICONINFORMATION);
			}
			break;
			case App::BUT_ID::CB_BUS:
			{
				if (HIWORD(wParam) == CBN_SELENDOK) {
					int i = SendMessage(cbBus, CB_GETCURSEL, 0, 0);
					if (i == 0) {
						if (!(this->editBus = CreateWindowEx(0, L"Edit", L"",
							WS_CHILD | WS_BORDER | WS_VISIBLE | ES_NUMBER | ES_LEFT,
							this->AppWeigh - 150, this->AppHeigth - 670, 70, 25,
							this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_BUS), nullptr, nullptr)))
							throw "Error, can't create edit button";
					}
				}
				UpdateWindow(hwnd);
			}
			break;

			case App::BUT_ID::CB_DEICE:
			{
				if (HIWORD(wParam) == CBN_SELENDOK) {
					int i = SendMessage(cbDeIce, CB_GETCURSEL, 0, 0);
					if (i == 0) {
						if (!(this->editDeIce = CreateWindowEx(0, L"Edit", L"",
							WS_CHILD | WS_BORDER | WS_VISIBLE | ES_NUMBER | ES_LEFT,
							this->AppWeigh - 150, this->AppHeigth - 430, 70, 25,
							this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_DEICE), nullptr, nullptr)))
							throw "Error, can't create edit button";
					}
				}
				UpdateWindow(hwnd);
			}
			break;

			case App::BUT_ID::CB_FUEL:
			{
				if (HIWORD(wParam) == CBN_SELENDOK) {
					int i = SendMessage(cbFuel, CB_GETCURSEL, 0, 0);
					if (i == 0) {
						if (!(this->editFuel = CreateWindowEx(0, L"Edit", L"",
							WS_CHILD | WS_BORDER | WS_VISIBLE | ES_NUMBER | ES_LEFT,
							this->AppWeigh - 150, this->AppHeigth - 520, 70, 25,
							this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_FUEL), nullptr, nullptr)))
							throw "Error, can't create edit button";
					}
				}
				UpdateWindow(hwnd);
			}
			break;

			case App::BUT_ID::CB_HEAT:
			{
				if (HIWORD(wParam) == CBN_SELENDOK) {
					int i = SendMessage(cbHeat, CB_GETCURSEL, 0, 0);
					if (i == 0) {
						if (!(this->editHeat = CreateWindowEx(0, L"Edit", L"",
							WS_CHILD | WS_BORDER | WS_VISIBLE | ES_NUMBER | ES_LEFT,
							this->AppWeigh - 150, this->AppHeigth - 490, 70, 25,
							this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_HEAT), nullptr, nullptr)))
							throw "Error, can't create edit button";
					}
				}
				UpdateWindow(hwnd);
			}
			break;

			case App::BUT_ID::CB_LADDER:
			{
				if (HIWORD(wParam) == CBN_SELENDOK) {
					int i = SendMessage(cbLadder, CB_GETCURSEL, 0, 0);
					if (i == 0) {
						if (!(this->editLadder = CreateWindowEx(0, L"Edit", L"",
							WS_CHILD | WS_BORDER | WS_VISIBLE | ES_NUMBER | ES_LEFT,
							this->AppWeigh - 150, this->AppHeigth - 700, 70, 25,
							this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_LADDER), nullptr, nullptr)))
							throw "Error, can't create edit button";
					}
				}
				UpdateWindow(hwnd);
			}
			break;

			case App::BUT_ID::CB_LAUNCH:
			{
				if (HIWORD(wParam) == CBN_SELENDOK) {
					int i = SendMessage(cbLaunch, CB_GETCURSEL, 0, 0);
					if (i == 0) {
						if (!(this->editLaunch = CreateWindowEx(0, L"Edit", L"",
							WS_CHILD | WS_BORDER | WS_VISIBLE | ES_NUMBER | ES_LEFT,
							this->AppWeigh - 150, this->AppHeigth - 640, 70, 25,
							this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_LAUNCH), nullptr, nullptr)))
							throw "Error, can't create edit button";
					}
				}
				UpdateWindow(hwnd);
			}
			break;

			case App::BUT_ID::CB_LOADER:
			{
				if (HIWORD(wParam) == CBN_SELENDOK) {
					int i = SendMessage(cbLoader, CB_GETCURSEL, 0, 0);
					if (i == 0) {
						if (!(this->editLoader = CreateWindowEx(0, L"Edit", L"",
							WS_CHILD | WS_BORDER | WS_VISIBLE | ES_NUMBER | ES_LEFT,
							this->AppWeigh - 150, this->AppHeigth - 400, 70, 25,
							this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_LOADER), nullptr, nullptr)))
							throw "Error, can't create edit button";
					}
				}
				UpdateWindow(hwnd);
			}
			break;

			case App::BUT_ID::CB_OIL:
			{
				if (HIWORD(wParam) == CBN_SELENDOK) {
					int i = SendMessage(cbOil, CB_GETCURSEL, 0, 0);
					if (i == 0) {
						if (!(this->editOil = CreateWindowEx(0, L"Edit", L"",
							WS_CHILD | WS_BORDER | WS_VISIBLE | ES_NUMBER | ES_LEFT,
							this->AppWeigh - 150, this->AppHeigth - 460, 70, 25,
							this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_OIL), nullptr, nullptr)))
							throw "Error, can't create edit button";
					}
				}
				UpdateWindow(hwnd);
			}
			break;

			case App::BUT_ID::CB_STEP:
			{
				if (HIWORD(wParam) == CBN_SELENDOK) {
					int i = SendMessage(cbStep, CB_GETCURSEL, 0, 0);
					if (i == 0) {
						if (!(this->editStep = CreateWindowEx(0, L"Edit", L"",
							WS_CHILD | WS_BORDER | WS_VISIBLE | ES_NUMBER | ES_LEFT,
							this->AppWeigh - 150, this->AppHeigth - 550, 70, 25,
							this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_STEP), nullptr, nullptr)))
							throw "Error, can't create edit button";
					}
				}
				UpdateWindow(hwnd);
			}
			break;

			case App::BUT_ID::CB_SUP:
			{
				if (HIWORD(wParam) == CBN_SELENDOK) {
					int i = SendMessage(cbSup, CB_GETCURSEL, 0, 0);
					if (i == 0) {
						if (!(this->editSup = CreateWindowEx(0, L"Edit", L"",
							WS_CHILD | WS_BORDER | WS_VISIBLE | ES_NUMBER | ES_LEFT,
							this->AppWeigh - 150, this->AppHeigth - 580, 70, 25,
							this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_SUP), nullptr, nullptr)))
							throw "Error, can't create edit button";
					}
				}
				UpdateWindow(hwnd);
			}
			break;

			case App::BUT_ID::CB_WATER:
			{
				if (HIWORD(wParam) == CBN_SELENDOK) {
					int i = SendMessage(cbWater, CB_GETCURSEL, 0, 0);
					if (i == 0) {
						if (!(this->editWater = CreateWindowEx(0, L"Edit", L"",
							WS_CHILD | WS_BORDER | WS_VISIBLE | ES_NUMBER | ES_LEFT,
							this->AppWeigh - 150, this->AppHeigth - 610, 70, 25,
							this->hwnd, reinterpret_cast<HMENU>(App::BUT_ID::EDIT_WATER), nullptr, nullptr)))
							throw "Error, can't create edit button";
					}
				}
				UpdateWindow(hwnd);
			}
			break;

			case App::BUT_ID::CANCEL:
			{
				PostQuitMessage(0);
			}
			break;


			}


				
						
		}
		return 0;

		case WM_DESTROY:
		{
			PostQuitMessage(0);
		}
		return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
