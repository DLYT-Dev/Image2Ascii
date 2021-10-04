#include <iostream>
#include <map>
#include "Vector.h"
#include "Utils.h"
#include "Image.h"
#include "BrightnessMap.h"

int main() {

    // note:
    // throughout the project X will correspond with the WIDTH and Y with the HEIGHT


    // character width divided by character height (font dependent)
    const float widthFactor = 2.0f;

    // user-input (filepath)
    std::string path;
    std::cout << "filepath: ";
    std::cin >> path;

    // read image
    Image img(path.c_str());
    Vector2 imageSize = {(float) img.width, (float) img.height};

    // get size of console window
    Vector2 windowSize{};
    Utils::GetCurrentWindowSize(windowSize);

    // calculate new image size
    float scale = std::max((imageSize.x * widthFactor / (windowSize.x - 1.0f)), imageSize.y / windowSize.y);
    Vector2 size = {(imageSize.x / scale * widthFactor), (imageSize.y / scale)};

    // resize image
    Image::resize(img, (int) size.x, (int) size.y);

    // get gray-values of image
    float brightness[img.size / img.channels];
    for (int i = 0; i < img.size; i += img.channels) {
        int pos = i / img.channels;
        brightness[pos] = (float) img.data[i];
        brightness[pos] += (float) img.data[i + 1];
        brightness[pos] += (float) img.data[i + 2];
        brightness[pos] /= 3.0f * 255.0f;
    }

    // print image to console
    for (int i = 0; i < img.size / img.channels; ++i) {
        if (i % img.width == 0)
            std::cout << std::endl;
        std::cout << charBrightnessMap.lower_bound(brightness[i])->second;
    }

    // press enter to close program
    std::cin.ignore();
    std::cin.get();

    return EXIT_SUCCESS;
}
