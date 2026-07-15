#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <windows.h>
#include <stdio.h>

void pixel(int topR, int topG, int topB, int bottomR, int bottomG, int bottomB);

int main(){
    int width,height,channels;
     unsigned char *image = stbi_load(
        "image.jpg",
        &width,
        &height,
        &channels,
        3
    );

    if (image == NULL)
    {
        printf("Image not loaded\n");
        return 1;
    }

    printf("Width: %d\n", width);
    printf("Height: %d\n", height);


    int j=0;
    int i=0;
    for(i;i<height;){
            j=i*width*3; //width is pixel width because of that we have to multipy it by 3 because one pixle has 3 value
            for(j;j<width*(i+1)*3;){
                    int rt,gt,bt,rb,gb,bb=0;
                            rt=image[j];
                            gt=image[j+1];
                            bt=image[j+2];
                            rb=image[j+3];
                            gb=image[j+4];
                            bb=image[j+5];
                            j=j+6;
                            pixel(rt,gt,bt,rb,gb,bb);


            }
            printf("\n");
             i++;


    }
    stbi_image_free(image);

    return 0;
}

void pixel(int topR, int topG, int topB, int bottomR, int bottomG, int bottomB)
{
    printf("\x1b[38;2;%d;%d;%dm", topR, topG, topB);       // foreground (top)
    printf("\x1b[48;2;%d;%d;%dm", bottomR, bottomG, bottomB); // background (bottom)
    printf("*");
    printf("\x1b[0m"); // reset color
}




