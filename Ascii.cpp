#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace std;

typedef struct {
    int width;
    int height;
    int channel;
    unsigned char *pixel;
}Imagedesc;


int main(void)
{
    char ramp[] = "@%#*+=-:.";
    int ramplegnth = 9;

    int w,h,c;
    int R,G,B;
    int L; //luminance

    int xstep, ystep;
    int targetwidth, targetheight;

    int index;

    Imagedesc *imagedesc = (Imagedesc*)malloc(sizeof(Imagedesc));
    imagedesc->pixel = stbi_load("cat.jpg", &w,&h,&c, 3);

    if(imagedesc->pixel == NULL)
    {
        return EXIT_FAILURE;
    }

    imagedesc->width = w;
    imagedesc->height = h;
    imagedesc->channel = c;

   

    targetwidth = 100;
    xstep = imagedesc->width / targetwidth;
    ystep = xstep * 2;

    for(size_t y = 0; y < imagedesc-> height; y += ystep)
    {
        for(size_t x = 0; x < imagedesc -> width; x += xstep)
        {
            index = (y * imagedesc->width + x) * 3;
            R = imagedesc->pixel[index];
            G = imagedesc->pixel[index + 1];
            B = imagedesc->pixel[index + 2];
            L = (int)(0.299*R + 0.587*G + 0.114*B);

            int i = static_cast<int>((L/255.0)*(ramplegnth - 1));
            char characters = ramp[i];

            std::cout<<characters;
        }
        std::cout<< '\n';
    }
}