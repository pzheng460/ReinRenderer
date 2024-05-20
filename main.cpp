#include <iostream>
#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

int main(int argc, char **argv) {
    TGAImage image(100, 100, TGAImage::RGB); // 100*100的图像，每像素三个字节存储RGB值
    image.set(52, 41, red); // 把（52，41）位置的像素设置为红色
    image.flip_vertically(); // 我希望原点在左下角，所以翻转一下
    image.write_tga_file("output.tga"); // 写入文件
    return 0;
}
