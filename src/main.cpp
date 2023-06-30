#pragma warning(disable: 6385)

#include <iostream>
#include <algorithm>

#include "classes/Vector.hpp"
#include "classes/Image.hpp"
#include "utils/utils.hpp"
#include "settings/brightness_map.hpp"

int main(int argc, char** argv)
{
	// Note:
	// Throughout the project X will correspond with the WIDTH and Y with the HEIGHT

	// Character width divided by character height (font dependent)
	const float WIDTH_FACTOR = 2.f;

	// Determine image filepath
	std::string path;
	if (argc >= 2)
	{
		path = argv[1];
	}
	else
	{
		std::cout << "Filepath: ";
		std::cin >> path;
	}

	// Read image
	Image img(path.c_str());

	// TODO: Maximize console window

	// Get size of console window
	Vector2 windowSize{};
	utils::getCurrentWindowSize(windowSize);

	// Calculate new image size
	const float scale = std::max<float>((img.width * WIDTH_FACTOR / (windowSize.x - 1.f)), img.height / windowSize.y);
	Vector2 size = { (img.width / scale * WIDTH_FACTOR), (img.height / scale) };

	// Resize image
	img.resize(size.x, size.y);

	// Get gray-values of image
	float* brightness = new float[img.size / img.channels];
	for (std::size_t i = 0; i < img.size; i += img.channels)
	{
		const std::size_t pos = i / img.channels;

		brightness[pos] = 0.f;
		for (std::int32_t j = 0; j < img.channels; ++j)
			brightness[pos] += (float) img.data[i + j];

		brightness[pos] /= 3.f * 255.f;
	}

	// Print image to console
	for (std::size_t i = 0; i < img.size / img.channels; ++i)
	{
		if (i % img.width == 0)
			std::cout << std::endl;
		std::cout << CHAR_BRIGHTNESS_MAP.lower_bound(brightness[i])->second;
	}

	delete[] brightness;

	utils::pause();

	return EXIT_SUCCESS;
}
