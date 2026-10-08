# meow

A 2D software renderer written in C++ from scratch. No graphics libraries: the CPU fills a pixel array, and the program saves it as an image.

[Renders](https://github.com/boldbug1/meow/tree/main/images)

## Features

- Framebuffer with bounds-checked `setpixel`
- Alpha blending (semi-transparent shapes mix with what's underneath)
- Anti-aliased circles (4x4 sampling per pixel)
- Rectangles and lines (Bresenham, all directions)
- Scene as data: a `std::vector<std::variant<Circle, Rectangle, Triangle>>` drawn by `render()`
- PPM image output

## Build and run

```
g++ -std=c++17 -Wall -Wextra main.cpp src/renderer.cpp -o main
./main
```

The image is written to `images/`. PPM isn't previewed by most viewers, so open it with IrfanView or GIMP, or convert it: `magick images/castle.ppm images/castle.png`.

## Layout

```
lib/renderer.h     types and function declarations
src/renderer.cpp   rasterizer, blending, render()
main.cpp           builds a scene and saves it
```

## Roadmap

- [x] Framebuffer, shapes, PPM output
- [x] Alpha blending
- [x] Anti-aliased circles
- [x] Scene as a list of shapes
- [x] Line drawing (Bresenham)
- [ ] Scanline triangle fill (any triangle)
- [ ] Polygons
- [ ] Transforms (move, scale, rotate)
- [ ] Window and frame loop (SDL2)
- [ ] Save and load scenes from a file
