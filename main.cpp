#include <vector>
#include <fstream>
#include "lib/renderer.h"


int main(void){
    int w = 256;
    int h = 256;


    std::vector<pixel> framebuffer(w*h);

    //fill the whole frame white :) for immersion idk
    fill_rect(framebuffer, w, h, 0, 0, w-1, h-1, {255,255,255,255});

    fill_circle(framebuffer, w, h, 70, 128, 50,{255,165,0,255});
    fill_circle_aa(framebuffer, w, h, 186, 128, 50,{255,165,0,255});


    save_ppm(framebuffer,w,h,"images/aa.ppm");

}