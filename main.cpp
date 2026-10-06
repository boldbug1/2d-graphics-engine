#include <iostream>
#include <cstdint>
#include <vector>
#include <fstream>

struct pixel{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

void setpixel(std::vector<pixel>& fb , int w, int h,int x, int y,pixel color){
    if ((x < 0 || x > w-1) || (y < 0 || y > h -1)){
        return;
    }
    
    fb[y * w + x] =  color;
}



int main(void){
    int w = 256;
    int h = 256;

    std::vector<pixel> framebuffer(w*h);

    setpixel(framebuffer, w, h, 10, 10, {255, 0, 0, 255});

    std::ofstream out("image.ppm", std::ios::binary);
    out << "P6\n" << w << " " << h << "\n255\n";

    for (const pixel& p : framebuffer) {
    out.write(reinterpret_cast<const char*>(&p.r), 1);
    out.write(reinterpret_cast<const char*>(&p.g), 1);
    out.write(reinterpret_cast<const char*>(&p.b), 1);
}
}