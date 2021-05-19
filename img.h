/**
Saving temporary image
*/

#ifndef __IMG_H__
#define __IMG_H__

#include <stdio.h>
#include <stdint.h>

#define ImgWidth 10
#define ImgHeight 10
#define ImgDepth 3

uint8_t img[ImgHeight][ImgWidth][ImgDepth]={
    {{3, 4, 2}, {0, 20, 9}, {23, 12, 23}, {34,62,75}, {90,100,20}, {34,52,78}, {75,34,56}, {21,34,89},{72,89,10},{21,55,77}},
    {{13, 4, 56}, {5, 3, 5}, {1, 4, 9},{33,22,11},{77,32,100},{200,20,30},{11,22,33},{,100,150,43},{211,33,66},{89,78,99}},
    {{11,22,33},{22,54,56},{23,24,25},{21,240,100},{123,44,70},{43,78,100},{35,213,11},{111,124,50},{32,56,90},{10,222,200}},
    {{},{},{},{},{},{},{},{},{},{}},
    {{},{},{},{},{},{},{},{},{},{}},
    {{},{},{},{},{},{},{},{},{},{}},
    {{},{},{},{},{},{},{},{},{},{}},
    {{},{},{},{},{},{},{},{},{},{}},
    {{},{},{},{},{},{},{},{},{},{}},
    {{},{},{},{},{},{},{},{},{},{}}
    };



#endif
