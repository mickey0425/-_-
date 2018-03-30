#include <stdio.h>
#include <stdlib.h>
#include "PointDataStructure.h"
#include "BMP_Structure.h"
#include "MarkedSquare.h"

int main(int argc, char *argv[])
{
	int i,j;
    char Input_LeftBMP_Name[200], PointSetName[200], Output_BMP_Name[200], temp[200];
    MPPSet *MPPSet_Ptr = (MPPSet*)malloc(sizeof(MPPSet));
    MarkRegion *MarkRegion_Ptr = (MarkRegion*)malloc(sizeof(MarkRegion));
    PointSet *PS = (PointSet *)malloc(sizeof(PointSet));
    PointSet *LeftPS = (PointSet *)malloc(sizeof(PointSet));
    BMPDataStructure *BMPInput = (BMPDataStructure*)malloc(sizeof(BMPDataStructure));
    BMPDataStructure *BMPGray = (BMPDataStructure*)malloc(sizeof(BMPDataStructure));
    BMPDataStructure *BMPLeftImg = (BMPDataStructure*)malloc(sizeof(BMPDataStructure));
    //宣告BMP資料結構     
    
    Read_Input_Coefficient("IOPathCoefficient.txt", Input_LeftBMP_Name,PointSetName,Output_BMP_Name, MarkRegion_Ptr);
    //讀取輸入參數文字檔 
   
   	printf("%s\n", Input_LeftBMP_Name);
   	printf("%s\n", PointSetName);
    printf("%s\n", Output_BMP_Name);
    printf("%d\n", MarkRegion_Ptr->RegionWidth);
    printf("%d\n", MarkRegion_Ptr->RegionHeight);
    printf("%d,%d,%d\n", MarkRegion_Ptr->Color_B, MarkRegion_Ptr->Color_G, MarkRegion_Ptr->Color_R);
    
   
   if(Read_BMPImgFile(Input_LeftBMP_Name, BMPInput))
    {
        BMPInput->BMPHeaderDataPtr->bPixel = bPiexl_0_Delete(BMPInput->BMPHeaderDataPtr->biWidth,
                                                            BMPInput->BMPHeaderDataPtr->biHeight,
                                                            BMPInput->BMPHeaderDataPtr->bPixel,
                                                            BMPInput->BMPHeaderDataPtr->biBitCount);
    }//輸入BMP寬度非4的倍數 除0操作 
    
    int ImgHeight = BMPInput->BMPHeaderDataPtr->biHeight;
    int ImgWidth = BMPInput->BMPHeaderDataPtr->biWidth;
    //宣告參數指向輸入圖片寬高 
    
	int RectangleWidthHalf = (MarkRegion_Ptr->RegionWidth)/2;
    //標示框的寬/2 
    int RectangleHeightHalf = (MarkRegion_Ptr->RegionHeight)/2;
    //標示框的高/2 
    
    Create_BMP_DS_Set54Header(BMPGray,ImgWidth,ImgHeight,8,1);
    Create_BMP_DS_Set54Header(BMPLeftImg,ImgWidth,ImgHeight,24,1);
    //創造左右灰階圖記憶體空間 
    
    if(BMPInput->BMPHeaderDataPtr->biBitCount==24)
    {
        Img24CGTo8G(BMPInput,BMPGray);
    }//24bits轉8bits灰階 
    else if(BMPInput->BMPHeaderDataPtr->biBitCount==8)
    {
        Img8CGTo8G(BMPInput,BMPGray);
    }//8bits轉8bits灰階 
    
    ReadFeaturePoint(PointSetName,LeftPS);
    //讀取指紋圖特徵點座標         
    //MarkedCornerSet(ImgWidth, ImgHeight, BMPGray->BMPHeaderDataPtr->bPixel, BMPLeftImg->BMPHeaderDataPtr->bPixel, LeftPS, 8, 0, 0, 255);
    MarkedRectangle(ImgWidth, ImgHeight, BMPGray->BMPHeaderDataPtr->bPixel, BMPLeftImg->BMPHeaderDataPtr->bPixel, LeftPS, RectangleWidthHalf, RectangleHeightHalf, MarkRegion_Ptr->Color_B, MarkRegion_Ptr->Color_G, MarkRegion_Ptr->Color_R);
                        
    BMPLeftImg->BMPHeaderDataPtr->bPixel = bPiexl_0_Recovery(BMPLeftImg->BMPHeaderDataPtr->biWidth,
                                                               BMPLeftImg->BMPHeaderDataPtr->biHeight,
                                                               BMPLeftImg->BMPHeaderDataPtr->bPixel,
                                                               BMPLeftImg->BMPHeaderDataPtr->biBitCount);
    //BMP補0函式 
    
    sprintf(temp, "%s", Output_BMP_Name);
    //輸出BMP路徑+檔名 
    
    Write_BMPImgFile(temp, BMPLeftImg);
    //輸出配對點對線段BMP圖檔 
    
    BMP_DS_free(BMPInput);
    BMP_DS_free(BMPGray);
    BMP_DS_free(BMPLeftImg);
    //釋放記憶體空間 
    
    system("PAUSE");	
    return 0;
}
