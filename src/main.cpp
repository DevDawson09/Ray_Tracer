#include <fstream>
#include <iostream>
#include <math.h>

#include "Ray.h"
#include "Vector3D.h"


int main() {
    std::ofstream outputFile {"../Output.ppm"};

    constexpr int SCREEN_WIDTH {400};
    constexpr int SCREEN_HEIGHT {225};
    const Vector3D Camera {0,0,0};


    outputFile << "P3" << '\n';
    outputFile << SCREEN_WIDTH << ' ' << SCREEN_HEIGHT << "\n255\n";


    for (int row {0}; row < SCREEN_HEIGHT; row++) {
        for (int column {0}; column < SCREEN_WIDTH; column++) {
            Vector3D pixel {((2*(column+0.5f)-SCREEN_WIDTH)/9)/25,((2*(row+0.5f)-SCREEN_HEIGHT)/9)/-25,-1}; // NOLINT(*-narrowing-conversions)
            Ray ray {Camera,(pixel - Camera).normalisation()};


            outputFile << round((ray.getDirection().get_xpos() + 1.0f)/2 * 255)<< ' ' << round((ray.getDirection().get_ypos() + 1)/2 * 255) << ' ' << round((ray.getDirection().get_zpos() + 1.0f) / 2.0f * 255) << '\n';

            //Tinker with any 255 and 128 values to change results.
            //outputFile << 255 - (round(static_cast<float>(row)/SCREEN_HEIGHT * 128) + round(static_cast<float>(column)/SCREEN_WIDTH * 128)) << ' ' << 0 << ' ' << round(static_cast<float>(column)/SCREEN_WIDTH * 128) + round(static_cast<float>(row)/SCREEN_HEIGHT * 128) << '\n';
        }
    }
    outputFile.close();


    return 0;
}
