#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION

#include <iostream>
#include "Image.h"
#include "stb_image.h"
#include "stb_image_write.h"
#include "stb_image_resize.h"

Image::Image(const char *filename) {
    if (read(filename))
        size = width * height * channels;
    else
        throw std::invalid_argument("Unable to read image.");
}

Image::~Image() {
    stbi_image_free(data);
}

bool Image::read(const char *filename) {
    data = stbi_load(filename, &width, &height, &channels, 0);
    return data != nullptr;
}

void Image::resize(Image &img, int output_w, int output_h) {
    auto *output_data = (unsigned char *) (malloc(output_w * output_h * img.channels));
    stbir_resize_uint8(img.data, img.width, img.height, 0, output_data, output_w, output_h, 0, img.channels);
    img.width = output_w;
    img.height = output_h;
    img.data = output_data;
    img.size = output_w * output_h * img.channels;
}