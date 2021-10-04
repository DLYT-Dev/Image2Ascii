#include <Windows.h>
#include "Utils.h"

void Utils::GetCurrentWindowSize(Vector2 &size) {
    CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleScreenBufferInfo);

    size.x = (float) (consoleScreenBufferInfo.srWindow.Right - consoleScreenBufferInfo.srWindow.Left + 1);
    size.y = (float) (consoleScreenBufferInfo.srWindow.Bottom - consoleScreenBufferInfo.srWindow.Top + 1);
}


