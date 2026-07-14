#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <stdio.h>

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
            j=i*width;
            for(j;j<width*(i+1);){
                    for(int k=0;k<3;k++){
                            printf("%03d ",image[j+k]);

                    }
                    printf(" ");
                    j=j+3;


            }
             i++;


    }
    stbi_image_free(image);

    return 0;
}



