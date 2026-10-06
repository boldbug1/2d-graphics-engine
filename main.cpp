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

int main(void){
    int w = 256;
    int h = 256;

    std::vector<pixel> framebuffer(w*h);
}