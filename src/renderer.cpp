#include "renderer.h"
#include <fstream>


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

void save_ppm(const std::vector<pixel>& fb, int w, int h, const char* path) {
    std::ofstream out(path,std::ios::binary);

    if(!out){
        std::cerr << "Error while opening file:save_ppm failed";
    }

    out << "P6\n" << w << " " << h << "\n255\n";

    for (const pixel& p : fb) {
    out.write(reinterpret_cast<const char*>(&p.r), 1);
    out.write(reinterpret_cast<const char*>(&p.g), 1);
    out.write(reinterpret_cast<const char*>(&p.b), 1);
    }
}
