#ifndef __CONV_H__
#define __CONV_H__

#include <stdio.h>
#include <stdint.h>
#include <float.h>

#include "common.h"
#include "debug.h"

typedef struct
{
    uint8_t *pMEMADDR;
    uint16_t FrmHeight;
    uint16_t FrmWidth;
    uint16_t BytePerPixel;
} S_VidFrmPropertise;

int NormalizeImg(uint8_t NrmVal, float NrmImg[ImgHeight][ImgWidth][ImgDepth], uint8_t OrigImg[ImgHeight][ImgWidth][ImgDepth]);

int convImgFunc(uint8_t strd, float NrmImg[ImgHeight][ImgWidth][ImgDepth], float filter[fHeight][fWidth][fDepth], float conv_img[ImgHeight/stride][ImgWidth/stride]);

void convolution2d_naive(const uint16_t height, const uint16_t width, 
                         const uint16_t kernel_height, const uint16_t kernel_width,
                         const uint16_t stride_height, const uint16_t stride_width);
#endif