#include <vector>
#include <fstream>
#include "lib/renderer.h"

int main(void) {
    int w = 16;
    int h = 16;

    std::vector<pixel> framebuffer(w * h);
    pixel black = {0,0,0,255};
    pixel white = {255,255,255,255};

    fill_rect(framebuffer,w,h,{0,0},{16,16},white);

    draw_line(framebuffer, w, h, {0,0},  {10,4},  black);   
    draw_line(framebuffer, w, h, {10,8}, {0,12},  black);   
    draw_line(framebuffer, w, h, {2,0},  {5,14},  black);
    draw_line(framebuffer, w, h, {3,0},  {3,10},  black);  

    save_ppm(framebuffer, w, h, "images/line.ppm");
    return 0;
}