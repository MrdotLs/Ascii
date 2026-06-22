#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stb_image.h>

using namespace std;

typedef struct {
    int width;
    int height;
    int channel;
    unsigned char *pixel;
}Imagedesc;


int maint(void)
{
    char ramp[] = "@%#*+=-:.";

    int w,h,c;
    int R,G,B;
    int L; //luminance

    int xstep, ystep;
    int targetwidth, targetheight;

    int index;

    Imagedesc *imagedesc = (Imagedesc*)malloc(sizeof(Imagedesc));
    imagedesc->pixel = stbi_load("", &w,&h,&c, 3);

    if(imagedesc->pixel == NULL)
    {
        return EXIT_FAILURE;
    }

    imagedesc->width = w;
    imagedesc->height = h;
    imagedesc->channel = c;

    L = 0.299 * R + 0.587 * G + 0.114 * B;

    xstep = targetwidth/targetheight;
    ystep = xstep * 2;

    for(size_t y = 0; y < imagedesc-> height; y += ystep)
    {
        for(size_t x = 0; x < imagedesc -> width; x += xstep)
        {
            index = (x*imagedesc->width + y)*imagedesc->channel;
            int i = static_cast<int>(index);
            char c = ramp[i];
        }
    }







}