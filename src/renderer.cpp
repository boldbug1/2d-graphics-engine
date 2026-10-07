#include "../lib/renderer.h"
#include <fstream>



void setpixel(std::vector<pixel>& fb , int w, int h,int x, int y,pixel color){
    if ((x < 0 || x > w-1) || (y < 0 || y > h -1)){
        return;
    }
    fb[y * w + x] = blend(fb[y * w + x], color);
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

pixel blend(pixel dst, pixel src){
    pixel newcolor;
    newcolor.r = static_cast<uint8_t>((src.r * src.a + dst.r *(255-src.a)) / 255);
    newcolor.g = static_cast<uint8_t>((src.g * src.a + dst.g *(255-src.a)) / 255);  
    newcolor.b = static_cast<uint8_t>((src.b * src.a + dst.b *(255-src.a)) / 255);  
    newcolor.a = 255;
    return newcolor;
}

void fill_circle_aa(std::vector<pixel>& fb, int w, int h, int cx, int cy, int r, pixel color) {
    for (int y = cy - r -1; y <= cy + r+1; y++) {
        for (int x = cx - r - 1; x <= cx + r+1; x++) {
            int hits = 0;
            for(int i=0;i<4;i++){
                for(int j =0;j<4;j++){
                    float px = x + (i + 0.5f) / 4;
                    float py = y + (j + 0.5f) / 4;

                    float dx = px-cx;
                    float dy = py-cy;
                    if(dx*dx + dy*dy <= r*r)hits++;
                }
            }
            if (hits>0){
                pixel c = color;
                c.a = static_cast<uint8_t>(color.a * hits/16);
                setpixel(fb,w,h,x,y,c);
            }
        }
    }
}
