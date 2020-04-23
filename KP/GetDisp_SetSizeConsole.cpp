#include "__Get_SetSizeConsole__.hpp"
#include <cstdint>
void GetDisplayInfo(const HWND& consoleWindow)
{
	HMONITOR objmonitor = MonitorFromWindow(consoleWindow, MONITOR_DEFAULTTONEAREST);
	if (objmonitor)
	{
		MONITORINFO infoDisplay{ sizeof(infoDisplay) };
		if (::GetMonitorInfo(objmonitor, &infoDisplay))
		{
			uint16_t x = static_cast<uint16_t>(((infoDisplay.rcWork.left + infoDisplay.rcWork.right) >> 1) - (infoDisplay.rcWork.right >> 1));
			uint16_t y = static_cast<uint16_t>(((infoDisplay.rcWork.top + infoDisplay.rcWork.bottom) >> 1) - (infoDisplay.rcWork.bottom >> 1));

			SetWindowPos(consoleWindow, nullptr, x, y, infoDisplay.rcWork.right, infoDisplay.rcWork.bottom, SWP_NOZORDER | SWP_NOOWNERZORDER);
		}
	}
};

const COORD ConsoleSize(void)
{
	SetWindowLong(GetConsoleWindow(), GWL_STYLE, GetWindowLong(GetConsoleWindow(), GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
	COORD WorkSize_maxWindow_(GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE)));
	WorkSize_maxWindow_.X -= 4; WorkSize_maxWindow_.Y -= 2;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), WorkSize_maxWindow_);
	GetDisplayInfo(GetConsoleWindow());
	return WorkSize_maxWindow_;
};