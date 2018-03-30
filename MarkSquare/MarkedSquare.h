#include"PointDataStructure.h"

void MarkedCorner(int imgWidth ,int imgHeight,unsigned char *GreyImgPtr, unsigned char *OutputImgPtr, int *CMapPtr,char Blue,char Green,char Red);

void DrawLine(unsigned char *InputImgPtr,int imgWidth ,int imgHeight, unsigned char *OutputImgPtr, int x, int d,char Blue,char Green,char Red);

void MarkedRectangle(int imgWidth, int imgHeight, unsigned char *GreyImgPtr, unsigned char *OutputImgPtr, PointSet *PS, int R1, int R2, char Blue, char Green, char Red);

void MarkedCornerSet_SP(int imgWidth ,int imgHeight,unsigned char *GreyImgPtr, unsigned char *OutputImgPtr, PointSet *PS,int R,char Blue,char Green,char Red);

void MarkedCornerSet_V2(int imgWidth ,int imgHeight,unsigned char *GreyImgPtr, unsigned char *OutputImgPtr, PointSet *PS,int MaskWidth,int MaskHeight,int *Blue,int *Green,int *Red,int ColorNum);
