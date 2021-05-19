#include "conv.h"

/*
image normalization
We want to divide every image pixel by 255 so that the value can be within
0-1.
*/

int NormalizeImg(uint8_t NrmVal, float NrmImg[ImgHeight][ImgWidth][ImgDepth], uint8_t OrigImg[ImgHeight][ImgWidth][ImgDepth])
{
    uint16_t h, w, d;
    
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


/**
 * convolution operation  
*/

int convImgFunc(uint8_t strd, float NrmImg[ImgHeight][ImgWidth][ImgDepth], float filter[fHeight][fWidth][fDepth], float conv_img[ImgHeight/stride][ImgWidth/stride])
{
    uint16_t h, w, d, fh, fw;
    float sum=0;
    uint16_t cIH = ImgHeight/stride;
    uint16_t cIW = ImgWidth/stride;

    CONV_Debug(("cIH= %d  cIW= %d\n",cIH,cIW));
    cIH =0; cIW =0;

    for (h=0; h<ImgHeight; h+=strd)
    {
        cIW=0;
        for (w=0; w<ImgWidth; w+=strd)
        {
            for (fh=0; fh<fHeight; fh++)
            {
                for (fw = 0; fw < fWidth; fw++)
                {
                    for (d = 0; d < ImgDepth; d++)
                    {
                        sum += NrmImg[h][w][d]*filter[fh][fw][d];
                    }
                }
            }
            conv_img[cIH][cIW]=sum;
            cIW++;
            sum =0;
        }
        cIH++;
    }
    CONV_Debug(("After storing,\n cIH= %d  cIW= %d\n",cIH,cIW));
    return SUCCESS;
}




