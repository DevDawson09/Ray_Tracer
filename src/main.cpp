#include <cstdint>
#include <fstream>
#include <iostream>
#include <math.h>
#include <vector>
#include <array>

#include "Ray.h"
#include "Sphere.h"
#include "Vector3D.h"

static int checkIntersections(const Ray& ray, const std::vector<Sphere>& Scene) {


    double t {0.0};
    Vector3D Point {};
    for (const Sphere& Object : Scene) {
        t= 0.0;
        while (t < 100) {
            Point = ray.at(t);

            const double Distance = sqrt(
                (Point.get_xpos() - Object.Centre.get_xpos()) * (Point.get_xpos() - Object.Centre.get_xpos()) +
                   (Point.get_ypos() - Object.Centre.get_ypos()) * (Point.get_ypos() - Object.Centre.get_ypos()) +
                   (Point.get_zpos() - Object.Centre.get_zpos()) * (Point.get_zpos() - Object.Centre.get_zpos()));

            if (Distance < Object.radius ) {
                return 2;
            }
            if (Distance == Object.radius) {
                return 1;
            }

            t += 0.1;
        }
    }
    return 0;

}


int main() {
    std::ofstream outputFile {"../Output.ppm"};

    constexpr int SCREEN_WIDTH {400};
    constexpr int SCREEN_HEIGHT {225};
    const Vector3D Camera {0,0,0};
    const std::vector<Sphere> Scene {
        {.radius = 1, .Centre = Vector3D{0,0,-5}},
        {.radius = 2, .Centre = Vector3D{3, 1, -2}},
        {.radius = 2, .Centre = Vector3D{-3,-1, -4}}
    };

    std::array<int, 3> RGB {0,0,0};

    outputFile << "P3" << '\n';
    outputFile << SCREEN_WIDTH << ' ' << SCREEN_HEIGHT << "\n255\n";



    for (int row {0}; row < SCREEN_HEIGHT; row++) {
        for (int column {0}; column < SCREEN_WIDTH; column++) {
            Vector3D pixel {((2*(column+0.5f)-SCREEN_WIDTH)/9)/25,((2*(row+0.5f)-SCREEN_HEIGHT)/9)/-25,-1}; // NOLINT(*-narrowing-conversions)
            Ray ray {Camera,(pixel - Camera).normalisation()};

            int numOfIntersection {checkIntersections(ray, Scene)};

            if (numOfIntersection > 0) {
                RGB = {255, 0, 0};
                outputFile << 255 - (round(static_cast<float>(row)/SCREEN_HEIGHT * 128) + round(static_cast<float>(column)/SCREEN_WIDTH * 128)) << ' ' << 0 << ' ' << round(static_cast<float>(column)/SCREEN_WIDTH * 128) + round(static_cast<float>(row)/SCREEN_HEIGHT * 128) << '\n';
            } else {
                RGB = {0,0,0};
                outputFile << RGB[0] << ' ' << RGB[1] << ' ' << RGB[2] << '\n';
            }

            //outputFile << round((ray.getDirection().get_xpos() + 1.0f)/2 * 255)<< ' ' << round((ray.getDirection().get_ypos() + 1)/2 * 255) << ' ' << round((ray.getDirection().get_zpos() + 1.0f) / 2.0f * 255) << '\n';
            //Tinker with any 255 and 128 values to change results.
        }
    }
    outputFile.close();


    return 0;
}
