#pragma once

#include <string>

#include "colorstream.hpp"
#include "../classes/Vector.hpp"

namespace utils
{
	void getCurrentWindowSize(Vector2& size);

	void pause();
	void throwError(const std::string& message);
	void throwErrorAndExit(const std::string& message);
}
