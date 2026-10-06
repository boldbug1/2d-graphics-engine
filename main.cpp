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

void fill_circle(std::vector<pixel>& fb, int w, int h, int cx, int cy, int r, pixel color) {
    for (int y = cy - r; y <= cy + r; y++) {
        for (int x = cx - r; x <= cx + r; x++) {
            int dx = x - cx;
            int dy = y - cy;
            if (dx*dx + dy*dy <= r*r) {
                setpixel(fb, w, h, x, y, color);
            }
        }
    }
}

void fill_rect(std::vector<pixel>& fb,int w,int h,int sx,int sy,int ex,int ey,pixel color){
    for(int y = sy;y <=ey;y++){
        for(int x=sx;x<=ex;x++){
            setpixel(fb,w,h,x,y,color);
        }
    }
}

void fill_triangle(std::vector<pixel>& fb,int w,int h,int sx,int sy,int ex, int ey,pixel color){
    int cx = (sx+ex)/2;
    for(int y=sy;y<=ey;y++){
        int half = (ex - sx) / 2 * (y - sy) / (ey - sy);
        for(int x=cx-half;x<=cx+half;x++){
            setpixel(fb,w,h,x,y,color);
        }
    }
}

int main(void){
    int w = 256;
    int h = 256;

    std::vector<pixel> framebuffer(w*h);

    //fill the whole frame white :) for immersion idk
    for(int y = 0; y < h;y++){
        for(int x = 0;x < w;x++){
            setpixel(framebuffer,w,h,x,y,{255,255,255,255});
        }
    }

    setpixel(framebuffer, w, h, 10, 10, {255, 0, 0, 255});
    fill_circle(framebuffer,w,h,50,50,50,{0,255,0,255});
    fill_rect(framebuffer,w,h,50,50,100,100,{255,0,255,255});
    fill_triangle(framebuffer,w,h,30,150,89,216,{255,0,0,255});

    //write headers (ppm)
    std::ofstream out("image.ppm", std::ios::binary);
    out << "P6\n" << w << " " << h << "\n255\n";

    //write every pixel to ppm image file
    for (const pixel& p : framebuffer) {
    out.write(reinterpret_cast<const char*>(&p.r), 1);
    out.write(reinterpret_cast<const char*>(&p.g), 1);
    out.write(reinterpret_cast<const char*>(&p.b), 1);
}


}