#include <vector>
#include <fstream>
#include "renderer.h"


int main(void){
    int w = 256;
    int h = 256;
    pixel orange = {255, 165, 0, 255};
    pixel pink   = {255, 150, 170, 255};
    pixel black  = {0, 0, 0, 255};
    pixel green  = {80, 200, 80, 255};

    std::vector<pixel> framebuffer(w*h);

    //fill the whole frame white :) for immersion idk
    fill_rect(framebuffer, w, h, 0, 0, w-1, h-1, {255,255,255,255});


    save_ppm(framebuffer,w,h,"images/image.ppm");

}