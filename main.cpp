#include <vector>
#include <fstream>
#include "lib/renderer.h"

int main(void) {
    int w = 256;
    int h = 256;

    std::vector<pixel> framebuffer(w * h);

    pixel sky        = { 20,  24,  45, 255 };
    pixel moon_glow  = {245, 240, 200, 255 };
    pixel grass      = { 40,  75,  45, 255 };
    pixel wall_dark  = { 85,  90, 105, 255 };
    pixel wall_base  = {110, 115, 135, 255 };
    pixel roof_blue  = { 45,  75, 140, 255 };
    pixel door_wood  = { 70,  40,  25, 255 };
    pixel gold_light = {255, 205,  75, 255 };

    //fill the whole frame white :) for immersion idk
    fill_rect(framebuffer, w, h, 0, 0, w - 1, h - 1, sky);

    std::vector<Shapes> scene;

    scene.push_back(Circle{205, 45, 22, moon_glow});
    scene.push_back(Rectangle{0, 200, 255, 255, grass});

    scene.push_back(Rectangle{88, 115, 168, 200, wall_base});
    scene.push_back(Rectangle{ 88, 107, 100, 114, wall_base});
    scene.push_back(Rectangle{106, 107, 118, 114, wall_base});
    scene.push_back(Rectangle{124, 107, 136, 114, wall_base});
    scene.push_back(Rectangle{142, 107, 154, 114, wall_base});
    scene.push_back(Rectangle{160, 107, 168, 114, wall_base});

    scene.push_back(Rectangle{52, 90, 88, 200, wall_dark});
    scene.push_back(Triangle{46, 50, 94, 90, roof_blue});

    scene.push_back(Rectangle{168, 90, 204, 200, wall_dark});
    scene.push_back(Triangle{162, 50, 210, 90, roof_blue});

    scene.push_back(Rectangle{113, 85, 143, 114, wall_dark});
    scene.push_back(Triangle{107, 45, 149, 85, roof_blue});

    scene.push_back(Rectangle{114, 165, 142, 200, door_wood});
    scene.push_back(Circle{128, 165, 14, door_wood});

    scene.push_back(Rectangle{ 66, 115,  74, 135, gold_light});
    scene.push_back(Circle{ 70, 115,   4, gold_light});
    scene.push_back(Rectangle{182, 115, 190, 135, gold_light});
    scene.push_back(Circle{186, 115,   4, gold_light});
    scene.push_back(Rectangle{125,  95, 131, 107, gold_light});

    render(framebuffer, w, h, scene);

    save_ppm(framebuffer, w, h, "images/castle.ppm");
    return 0;
}