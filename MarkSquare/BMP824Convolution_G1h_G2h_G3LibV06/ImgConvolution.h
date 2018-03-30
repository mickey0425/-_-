//ImgConvolution.h
#include "ReadMask.h"
#include "BMP_Structure.h"

void BMP_Convolution8_ZeroPadding(BMPDataStructure *In8bBMP,
                                  BMPDataStructure *OutConvolutionBMP,
                                  MaskStructure *Maskdata);
//29-15行 

void BMP_Convolution8_Shrink(BMPDataStructure *In8bBMP,
                             BMPDataStructure *OutConvolutionBMP,
                             MaskStructure *Maskdata);
//29-15行  

void BMP_Convolution8_AveragePadding(BMPDataStructure *In8bBMP,
                                     BMPDataStructure *OutConvolutionBMP,
                                     MaskStructure *Maskdata,
                                     int numAvgLine);
//31-15行 

void ImgConvolution8_ZeroPadding(unsigned char *srcPixelBMP,
                                 int imgWidth, 
                                 int imgHeight,
                                 float *mask, 
                                 int maskWidthOdd, 
                                 int maskHeightOdd,
                                 unsigned char *destPixelBMP);
//49-30行    
   
void ImgConvolution8_Shrink(unsigned char *srcPixelBMP,
                            int imgWidth, 
                            int imgHeight,
                            float *mask, 
                            int maskWidthOdd,
                            int maskHeightOdd,
                            unsigned char *destPixelBMP);
//48-29行 

void ImgConvolution8_AveragePadding(unsigned char *srcPixelBMP,
                                    int imgWidth, 
                                    int imgHeight,
                                    float *mask, 
                                    int maskWidthOdd, 
                                    int maskHeightOdd,
                                    int numAvgLine,
                                    unsigned char *destPixelBMP);
//52-31行 

void ImgTemp_AveragePadding(unsigned char *paddingBMP,
                            int paddWidth, 
                            int paddHeight,
                            int maskWidthOdd, 
                            int maskHeightOdd,
                            int numAvgLine);
//55-34行
