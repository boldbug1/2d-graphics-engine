#pragma once
#include <iostream>
#include <cstdint>
#include <vector>
#include <fstream>

struct pixel{
    uint8_t r,g,b,a;
};

pixel blend(pixel dest, pixel src);
void setpixel(std::vector<pixel>& fb , int w, int h,int x, int y,pixel color);
void fill_circle(std::vector<pixel>& fb, int w, int h, int cx, int cy, int r, pixel color);
void fill_rect(std::vector<pixel>& fb,int w,int h,int sx,int sy,int ex,int ey,pixel color);
void fill_triangle(std::vector<pixel>& fb,int w,int h,int sx,int sy,int ex, int ey,pixel color);
void save_ppm(const std::vector<pixel>& fb, int w, int h, const char* path);
void fill_circle_aa(std::vector<pixel>& fb, int w, int h, int cx, int cy, int r, pixel color);
