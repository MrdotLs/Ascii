#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include <opencv2/opencv.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace std;
using namespace cv;

typedef struct {
    int width;
    int height;
    int channel;
    unsigned char *pixel;
}Imagedesc;


// void drawAscii(void) // from file
// {
   

//     char ramp[] = "MND8OZ$7I?+=~:,.. ";
//     int ramplegnth = 17;

//     int w,h,c;
//     int R,G,B;

//     int L; //luminance

//     int xstep, ystep;
//     int targetwidth, targetheight;

//     int index;

//     Imagedesc *imagedesc = (Imagedesc*)malloc(sizeof(Imagedesc));
//     imagedesc->pixel = stbi_load(rawImage, &w,&h,&c, 3);

//     if(imagedesc->pixel == NULL)
//     {
//         cout<<"failed";
//         return;
//     }

//     imagedesc->width = w;
//     imagedesc->height = h;
//     imagedesc->channel = c;

   

//     targetwidth = 100;
//     xstep = imagedesc->width / targetwidth;
//     ystep = xstep * 2;

//     for(size_t y = 0; y < imagedesc-> height; y += ystep)
//     {
//         for(size_t x = 0; x < imagedesc -> width; x += xstep)
//         {
//             index = (y * imagedesc->width + x) * 3;
//             R = imagedesc->pixel[index];
//             G = imagedesc->pixel[index + 1];
//             B = imagedesc->pixel[index + 2];
//             L = (int)(0.299*R + 0.587*G + 0.114*B);

//             int i = static_cast<int>((L/255.0)*(ramplegnth - 1));
//             char characters = ramp[i];

//             std::cout<<characters;
//         }
//         std::cout<< '\n';
//     }
//     stbi_image_free(imagedesc->pixel);
//     free(imagedesc);
// }


void DrawAscii(Mat image)
{
    char ramp[] = "MND8OZ$7I?+=~:,.. ";
    int ramplegnth = 17;

    int w,h,c;
    int R,G,B;

    int L; //luminance

    int xstep, ystep;
    int targetwidth, targetheight;

    int index;
   
    targetwidth = 100;
    xstep = image.cols / targetwidth;
    ystep = xstep * 2;

    for(size_t y = 0; y < image.rows; y += ystep)
    {
        for(size_t x = 0; x < image.cols; x += xstep)
        {
            index = (y * image.cols + x) * 3;
            R = image.data[index];
            G = image.data[index + 1];
            B = image.data[index + 2];
            L = (int)(0.299*R + 0.587*G + 0.114*B);

            int i = static_cast<int>((L/255.0)*(ramplegnth - 1));
            char characters = ramp[i];

            std::cout<<characters;
        }
        std::cout<< '\n';
    }

}

int main(void)
{
    Mat myImage;                                                                    
    VideoCapture cap(0);
    
 
    if(!cap.isOpened())
    {
        std::cout<<"Camera Failed";
        return -1;
    }

    namedWindow("Video player");


    while(true)
    {
        cap >> myImage;
        if(myImage.empty())break;
      
        imshow("Video player", myImage);
        char delay = (char)waitKey(25);

        DrawAscii(myImage);

        if((char)waitKey(25) == 27) break;
    }

    cap.release();
    destroyAllWindows();
    
    return 0;
}