#include <vector>
#include <fstream>
#include "lib/renderer.h"


int main(void){
    int w = 256;
    int h = 256;


    std::vector<pixel> framebuffer(w*h);

    //fill the whole frame white :) for immersion idk
    fill_rect(framebuffer, w, h, 0, 0, w-1, h-1, {255,255,255,255});

    fill_circle(framebuffer, w, h, 100, 100, 60, {255, 0, 0, 128});
    fill_circle(framebuffer, w, h, 156, 100, 60, {0, 255, 0, 128});
    fill_circle(framebuffer, w, h, 128, 150, 60, {0, 0, 255, 128});


    save_ppm(framebuffer,w,h,"images/alpha.ppm");

}