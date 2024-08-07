# Software Renderer

My self-developed pure C++ renderer based on the TinyRenderer(https://github.com/ssloy/tinyrenderer and https://github.com/MrZz233/tinyrenderer_notes). 

It is a software renderer that implements the whole graphics pipeline, including rasterization, shading, and texturing. The renderer is designed to be simple and easy to understand, so it is a good project for beginners to learn computer graphics.

## Example Images

![framebuffer](images/framebuffer.jpg)

## Features

- Rasterization
- Shading
- Texturing
- Z-buffering

## Build

Create a build file folder in the directory:
```bash
mkdir build
```

Enter the build file folder:
```bash
cd build
```

Running cmake file:
```bash
cmake ..
```
    
Compile the project:
```bash
make
```

Run the project (the parameter `../obj/boggie` is the path of the obj file):
```bash
./SoftwareRenderer ../obj/boggie
```