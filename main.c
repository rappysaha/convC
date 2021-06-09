
#include <stdio.h>
#include "conv.h"
#include "img.h"


int main ()
{
    float NrmImg[ImgHeight][ImgWidth][ImgDepth]={0};
    float ConvImg[ImgHeight/stride][ImgWidth/stride]={0};
    NormalizeImg(255,NrmImg,img);

    printf ("test GCC\n");

    #if 0
    printf("img[1][1][0]=%d img[1][1][1]=%d img[1][1][2]=%d\n", img[1][1][0],img[1][1][1],img[1][1][2]);

    printf("test_val[1][1][0]=%f\n", NrmImg[1][1][0]);
    printf("test_val[1][1][1]=%f\n", NrmImg[1][1][2]);
    printf("test_val[1][1][2]=%f\n", NrmImg[1][1][3]);
    
    convImgFunc(stride, NrmImg,filter3d,ConvImg);
    #endif
    convolution2d_naive(10, 10, 
                         3, 3,
                         3, 3);

   return 0; 
}