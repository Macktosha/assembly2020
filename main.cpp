#include "App.h"
using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevIntance, LPSTR lpCmdLine, int nCmdShow)
{
	App app{};
	return app.Run();
}