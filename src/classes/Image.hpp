#pragma once

#include <iostream>

struct Image
{
	std::uint8_t* data{};
	std::size_t size{};
	std::int32_t width{};
	std::int32_t height{};
	std::int32_t channels{};

	Image(const char* filename);
	~Image();

	bool read(const char* filename);

	void resize(std::int32_t output_w, std::int32_t output_h);
};
