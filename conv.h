#ifndef __CONV_H__
#define __CONV_H__

#include <stdio.h>
#include <stdint.h>
#include <float.h>

#include "common.h"
#include "debug.h"

int NormalizeImg(uint8_t NrmVal, float NrmImg[ImgHeight][ImgWidth][ImgDepth], uint8_t OrigImg[ImgHeight][ImgWidth][ImgDepth]);

int convImgFunc(uint8_t strd, float NrmImg[ImgHeight][ImgWidth][ImgDepth], float filter[fHeight][fWidth][fDepth], float conv_img[ImgHeight/stride][ImgWidth/stride]);

#endif