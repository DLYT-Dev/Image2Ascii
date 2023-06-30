#include "utils.hpp"

#include <Windows.h>
#include <iostream>

void utils::getCurrentWindowSize(Vector2& size)
{
	CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo{};
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleScreenBufferInfo);

	size.x = (float)(consoleScreenBufferInfo.srWindow.Right - consoleScreenBufferInfo.srWindow.Left + 1);
	size.y = (float)(consoleScreenBufferInfo.srWindow.Bottom - consoleScreenBufferInfo.srWindow.Top + 1);
}

void utils::pause()
{
	std::cin.ignore();
	std::cin.get();
}

void utils::throwError(const std::string& message)
{
	std::cout << _F_RED("[!] ") << message << std::endl;
}

void utils::throwErrorAndExit(const std::string& message)
{
	throwError(message);
	pause();
	std::exit(EXIT_FAILURE);
}
