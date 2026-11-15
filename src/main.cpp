#include <fstream>
#include <iostream>
#include <math.h>


int main() {
    std::ofstream outputFile {"../Output.ppm"};

    constexpr int SCREEN_WIDTH {400};
    constexpr int SCREEN_HEIGHT {225};

    outputFile << "P3" << '\n';
    outputFile << SCREEN_WIDTH << ' ' << SCREEN_HEIGHT << "\n255\n";


    for (int row {0}; row < SCREEN_HEIGHT; ++row) {
        for (int column {0}; column < SCREEN_WIDTH; ++column) {
            //Tinker with any 255 and 128 values to change results.
            outputFile << 255 - round(static_cast<float>(row)/SCREEN_HEIGHT * 128) << ' ' << 128 << ' ' << 255 - round(static_cast<float>(column)/SCREEN_WIDTH * 128) << '\n';
        }
    }



    outputFile.close();
    return 0;
}
