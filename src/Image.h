#pragma once

struct Image {
    uint8_t *data = nullptr;
    size_t size = 0;
    int width{};
    int height{};
    int channels{};

    explicit Image(const char *filename);

    ~Image();

    bool read(const char *filename);

    static void resize(Image &img, int output_w, int output_h);
};
