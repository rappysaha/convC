
#include <stdio.h>
#include "conv.h"
#include "img.h"


int main ()
{
    float testArr[ImgHeight][ImgWidth][ImgDepth]={0};
    NormalizeImg(255,testArr,img);

    printf ("test GCC\n");

    #if 0
    printf("img[1][1][0]=%d img[1][1][1]=%d img[1][1][2]=%d\n", img[1][1][0],img[1][1][1],img[1][1][2]);

    printf("test_val[1][1][0]=%f\n", testArr[1][1][0]);
    printf("test_val[1][1][1]=%f\n", testArr[1][1][2]);
    printf("test_val[1][1][2]=%f\n", testArr[1][1][3]);
    #endif

    
   return 0; 
}