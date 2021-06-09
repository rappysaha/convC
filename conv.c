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

/**
 * stride : indicates the window moving per pixel
*/
// int convDDRImgFunc(S_VidFrmPropertise *s_VidFrmPrp, uint8_t strd, float filter[fHeight][fWidth][fDepth])
// {
//     uint16_t h, w, d, fh, fw;
//     uint16_t cIH = s_VidFrmPrp->FrmHeight / strd;
//     uint16_t cIW = s_VidFrmPrp->FrmWidth / strd;

//     for (h=0; h< s_VidFrmPrp->FrmHeight; h+=strd)
//     {
//         cIW=0;
//         for (w=0; w< s_VidFrmPrp->FrmWidth; w+= strd)
//         {
//             for (fh=0; fh<fHeight; fh++)
//             {
//                 for (fw = 0; fw < fWidth; fw++)
//                 {
//                     for (d = 0; d < ImgDepth; d++)
//                     {
//                         sum += NrmImg[h][w][d]*filter[fh][fw][d];
//                     }
//                 }
//             }
//             conv_img[cIH][cIW]=sum;
//             cIW++;
//             sum =0;
//         }
//         cIH++;
//     }
// }

//const fp_t* input_channel,
// fp_t* output_channel,
// const fp_t* kernel, 
// , const fp_t bias
void convolution2d_naive(const uint16_t height, const uint16_t width, 
                         const uint16_t kernel_height, const uint16_t kernel_width,
                         const uint16_t stride_height, const uint16_t stride_width) {


   int32_t channel_row, channel_column;
   int32_t kernel_row, kernel_column;
   int32_t height_crop = kernel_height/2;
   int32_t width_crop = kernel_width/2;

int32_t kernel_pos, pixel_pos;
//    fp_t pixel;

   int32_t output_channel_row = 0;
   int32_t output_channel_column = 0;

   uint16_t output_channel_width = (width - kernel_width)/stride_width + 1;


   for(channel_row = height_crop; channel_row < height-height_crop; channel_row+=stride_height) {
       for(channel_column = width_crop; channel_column < width - width_crop; channel_column += stride_width) {
        //    pixel = 0.0;

           for(kernel_row = 0; kernel_row < kernel_height; kernel_row++) {
               for(kernel_column = 0; kernel_column < kernel_width; kernel_column++) {
                   kernel_pos = kernel_row*kernel_width + kernel_column;
                   pixel_pos = width*(channel_row-height_crop+kernel_row) + channel_column-width_crop+kernel_column;
                   printf("kernel_pos = %d   pixel_pos= %d \n\r",kernel_pos,pixel_pos);
                //    pixel += kernel[kernel_row*kernel_width + kernel_column] *
                            // input_channel[width*(channel_row-height_crop+kernel_row) + channel_column-width_crop+kernel_column];
               }
           }

        //    pixel += bias;
        //    output_channel[output_channel_row*output_channel_width+output_channel_column] = pixel;
           output_channel_column++;

       }
       output_channel_row++;
       output_channel_column = 0;
   }

}

