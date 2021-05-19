#ifndef __CONV_H__
#define __CONV_H__

#include <stdio.h>
#include <stdint.h>
#include <float.h>

#define ImgWidth 10
#define ImgHeight 10
#define ImgDepth 3

#define SUCCESS 1
#define FAILURE 0 

int NormalizeImg(uint8_t NrmVal, float NrmImg[ImgHeight][ImgWidth][ImgDepth], uint8_t OrigImg[ImgHeight][ImgWidth][ImgDepth]);

#endif