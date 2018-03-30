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
    //�ŧiBMP��Ƶ��c     
    
    Read_Input_Coefficient("IOPathCoefficient.txt", Input_LeftBMP_Name,PointSetName,Output_BMP_Name, MarkRegion_Ptr);
    //Ū����J�ѼƤ�r�� 
   
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
    }//��JBMP�e�׫D4������ ��0�ާ@ 
    
    int ImgHeight = BMPInput->BMPHeaderDataPtr->biHeight;
    int ImgWidth = BMPInput->BMPHeaderDataPtr->biWidth;
    //�ŧi�Ѽƫ��V��J�Ϥ��e�� 
    
	int RectangleWidthHalf = (MarkRegion_Ptr->RegionWidth)/2;
    //�Хܮت��e/2 
    int RectangleHeightHalf = (MarkRegion_Ptr->RegionHeight)/2;
    //�Хܮت���/2 
    
    Create_BMP_DS_Set54Header(BMPGray,ImgWidth,ImgHeight,8,1);
    Create_BMP_DS_Set54Header(BMPLeftImg,ImgWidth,ImgHeight,24,1);
    //�гy���k�Ƕ��ϰO����Ŷ� 
    
    if(BMPInput->BMPHeaderDataPtr->biBitCount==24)
    {
        Img24CGTo8G(BMPInput,BMPGray);
    }//24bits��8bits�Ƕ� 
    else if(BMPInput->BMPHeaderDataPtr->biBitCount==8)
    {
        Img8CGTo8G(BMPInput,BMPGray);
    }//8bits��8bits�Ƕ� 
    
    ReadFeaturePoint(PointSetName,LeftPS);
    //Ū�������ϯS�x�I�y��         
    //MarkedCornerSet(ImgWidth, ImgHeight, BMPGray->BMPHeaderDataPtr->bPixel, BMPLeftImg->BMPHeaderDataPtr->bPixel, LeftPS, 8, 0, 0, 255);
    MarkedRectangle(ImgWidth, ImgHeight, BMPGray->BMPHeaderDataPtr->bPixel, BMPLeftImg->BMPHeaderDataPtr->bPixel, LeftPS, RectangleWidthHalf, RectangleHeightHalf, MarkRegion_Ptr->Color_B, MarkRegion_Ptr->Color_G, MarkRegion_Ptr->Color_R);
                        
    BMPLeftImg->BMPHeaderDataPtr->bPixel = bPiexl_0_Recovery(BMPLeftImg->BMPHeaderDataPtr->biWidth,
                                                               BMPLeftImg->BMPHeaderDataPtr->biHeight,
                                                               BMPLeftImg->BMPHeaderDataPtr->bPixel,
                                                               BMPLeftImg->BMPHeaderDataPtr->biBitCount);
    //BMP��0�禡 
    
    sprintf(temp, "%s", Output_BMP_Name);
    //��XBMP���|+�ɦW 
    
    Write_BMPImgFile(temp, BMPLeftImg);
    //��X�t���I��u�qBMP���� 
    
    BMP_DS_free(BMPInput);
    BMP_DS_free(BMPGray);
    BMP_DS_free(BMPLeftImg);
    //����O����Ŷ� 
    
    system("PAUSE");	
    return 0;
}
