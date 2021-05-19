#include "conv.h"

/*
image normalization
We want to divide every image pixel by 255 so that the value can be within
0-1.
*/

int NormalizeImg(uint8_t NrmVal, float NrmImg[ImgHeight][ImgWidth][ImgDepth], uint8_t OrigImg[ImgHeight][ImgWidth][ImgDepth])
{
    uint8_t h, w, d;
    
    for (h=0; h<ImgHeight; h++)
    {
        for (w=0; w<ImgWidth; w++)
        {
            for (d=0; d<ImgDepth; d++)
            {
                NrmImg[h][w][d] = (float) OrigImg[h][w][d] / (float) NrmVal;
            }
        }
    }
    return SUCCESS;
}




// convolution operation