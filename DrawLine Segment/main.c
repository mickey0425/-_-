#include <stdio.h>
#include <stdlib.h>
#include "PointDataStructure.h"
#include "BMP_Structure.h"

int main(int argc, char *argv[])
{
    int i;
    char Input_LeftBMP_Name[200], Input_RightBMP_Name[200],Input_MPPS_Name[200],Output_BMP_Name[200], temp[200];
    MPPSet *MPPS = (MPPSet*)malloc(sizeof(MPPSet));
    Point2D *StartingPoint = (Point2D*)malloc(sizeof(Point2D));
    ColorDegreeSet *ColorDegreeSet_Ptr = (ColorDegreeSet*)malloc(sizeof(ColorDegreeSet));
    
    BMPDataStructure *BMPInput = (BMPDataStructure*)malloc(sizeof(BMPDataStructure));
    BMPDataStructure *BMPInput2 = (BMPDataStructure*)malloc(sizeof(BMPDataStructure));
    BMPDataStructure *BMPLeftImg = (BMPDataStructure*)malloc(sizeof(BMPDataStructure));
    BMPDataStructure *BMPRightImg = (BMPDataStructure*)malloc(sizeof(BMPDataStructure));
    BMPDataStructure *BMPOutputImg = (BMPDataStructure*)malloc(sizeof(BMPDataStructure));
    //宣告BMP資料結構     
    
    Read_Input_Coefficient("IOPathCoefficient.txt", Input_LeftBMP_Name, Input_RightBMP_Name, Input_MPPS_Name, Output_BMP_Name, StartingPoint, ColorDegreeSet_Ptr);
    //讀取輸入參數文字檔 
    
    sprintf(temp, "%s", Input_LeftBMP_Name);
    //左圖BMP路徑+檔名 
    
    if(Read_BMPImgFile(temp, BMPInput))
    {
        BMPInput->BMPHeaderDataPtr->bPixel = bPiexl_0_Delete(BMPInput->BMPHeaderDataPtr->biWidth,
                                                            BMPInput->BMPHeaderDataPtr->biHeight,
                                                            BMPInput->BMPHeaderDataPtr->bPixel,
                                                            BMPInput->BMPHeaderDataPtr->biBitCount);
    }//輸入BMP寬度非4的倍數 除0操作 
    
    sprintf(temp, "%s", Input_RightBMP_Name);
    //右圖BMP路徑+檔名 
    
    if(Read_BMPImgFile(temp, BMPInput2))
    {
        BMPInput2->BMPHeaderDataPtr->bPixel = bPiexl_0_Delete(BMPInput2->BMPHeaderDataPtr->biWidth,
                                                              BMPInput2->BMPHeaderDataPtr->biHeight,
                                                              BMPInput2->BMPHeaderDataPtr->bPixel,
                                                              BMPInput2->BMPHeaderDataPtr->biBitCount);
    }//輸入BMP寬度非4的倍數 除0操作 
    
    int ImgHeight = BMPInput->BMPHeaderDataPtr->biHeight;
    int ImgWidth = BMPInput->BMPHeaderDataPtr->biWidth;
    int ImgHeight2 = BMPInput2->BMPHeaderDataPtr->biHeight;
    int ImgWidth2 = BMPInput2->BMPHeaderDataPtr->biWidth;
    //宣告參數指向輸入圖片寬高 
    
    Create_BMP_DS_Set54Header(BMPLeftImg,ImgWidth,ImgHeight,8,1);
    Create_BMP_DS_Set54Header(BMPRightImg,ImgWidth2,ImgHeight2,8,1);
    //創造左右灰階圖記憶體空間 
    
    if(BMPInput->BMPHeaderDataPtr->biBitCount==24)
    {
        Img24CGTo8G(BMPInput,BMPLeftImg);
        Img24CGTo8G(BMPInput2,BMPRightImg);
    }//24bits轉8bits灰階 
    else if(BMPInput->BMPHeaderDataPtr->biBitCount==8)
    {
        Img8CGTo8G(BMPInput,BMPLeftImg);
        Img8CGTo8G(BMPInput2,BMPRightImg);
    }//8bits轉8bits灰階 
    
    sprintf(temp, "%s", Input_MPPS_Name);
    //配對點對路徑+檔名 
    
    ReadMPPSet(temp,MPPS);
    //讀取配對點對資訊 
    
    DrawImgMatching2(BMPLeftImg, BMPRightImg, BMPOutputImg, MPPS, StartingPoint, ColorDegreeSet_Ptr->LineColor_B, ColorDegreeSet_Ptr->LineColor_G, ColorDegreeSet_Ptr->LineColor_R);
    //執行繪製配對點對線段函式 
    
    BMPOutputImg->BMPHeaderDataPtr->bPixel = bPiexl_0_Recovery(BMPOutputImg->BMPHeaderDataPtr->biWidth,
                                                               BMPOutputImg->BMPHeaderDataPtr->biHeight,
                                                               BMPOutputImg->BMPHeaderDataPtr->bPixel,
                                                               BMPOutputImg->BMPHeaderDataPtr->biBitCount);
    //BMP補0函式 
    
    sprintf(temp, "%s", Output_BMP_Name);
    //輸出BMP路徑+檔名 
    
    Write_BMPImgFile(temp, BMPOutputImg);
    //輸出配對點對線段BMP圖檔 
    
    BMP_DS_free(BMPInput);
    BMP_DS_free(BMPInput2);
    BMP_DS_free(BMPLeftImg);
    BMP_DS_free(BMPRightImg);
    BMP_DS_free(BMPOutputImg);
    Free_MPPSet(MPPS);
    //釋放記憶體空間 
    
    system("PAUSE");	
    return 0;
}
