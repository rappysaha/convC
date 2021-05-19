#ifndef __CONV_H__
#define __CONV_H__

#include <stdio.h>
#include <stint.h>
#include <float.h>

#include "img.h"

#define SUCCESS 1
#define FAILURE 0 

int NormalizeImg(uint8_t NrmVal, float NrmImg[][][]);

#endif