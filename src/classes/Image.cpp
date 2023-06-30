#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION

#include "Image.hpp"

#include "../utils/utils.hpp"
#include "../../lib/stb/stb_image.h"
#include "../../lib/stb/stb_image_write.h"
#include "../../lib/stb/stb_image_resize.h"

Image::Image(const char* filename)
{
	if (!read(filename))
		utils::throwErrorAndExit("Unable to read image.");
	size = (std::size_t)(width * height * channels);
}

Image::~Image()
{
	stbi_image_free(data);
}

bool Image::read(const char* filename)
{
	data = stbi_load(filename, &width, &height, &channels, 0);
	return data != nullptr;
}

void Image::resize(std::int32_t output_w, std::int32_t output_h)
{
	// Reserve memory
	const std::size_t data_size = (std::size_t)(output_w * output_h * channels);
	std::uint8_t* output_data = new std::uint8_t[data_size];

	// Resize image
	stbir_resize_uint8(data, width, height, 0, output_data, output_w, output_h, 0, channels);

	// Assign new data and correct image attributes
	memcpy_s(data, size, output_data, data_size);
	width = output_w;
	height = output_h;
	size = (std::size_t)(output_w * output_h * channels);

	// Free memory
	delete[] output_data;
}
