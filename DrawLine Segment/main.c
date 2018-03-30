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
    //�ŧiBMP��Ƶ��c     
    
    Read_Input_Coefficient("IOPathCoefficient.txt", Input_LeftBMP_Name, Input_RightBMP_Name, Input_MPPS_Name, Output_BMP_Name, StartingPoint, ColorDegreeSet_Ptr);
    //Ū����J�ѼƤ�r�� 
    
    sprintf(temp, "%s", Input_LeftBMP_Name);
    //����BMP���|+�ɦW 
    
    if(Read_BMPImgFile(temp, BMPInput))
    {
        BMPInput->BMPHeaderDataPtr->bPixel = bPiexl_0_Delete(BMPInput->BMPHeaderDataPtr->biWidth,
                                                            BMPInput->BMPHeaderDataPtr->biHeight,
                                                            BMPInput->BMPHeaderDataPtr->bPixel,
                                                            BMPInput->BMPHeaderDataPtr->biBitCount);
    }//��JBMP�e�׫D4������ ��0�ާ@ 
    
    sprintf(temp, "%s", Input_RightBMP_Name);
    //�k��BMP���|+�ɦW 
    
    if(Read_BMPImgFile(temp, BMPInput2))
    {
        BMPInput2->BMPHeaderDataPtr->bPixel = bPiexl_0_Delete(BMPInput2->BMPHeaderDataPtr->biWidth,
                                                              BMPInput2->BMPHeaderDataPtr->biHeight,
                                                              BMPInput2->BMPHeaderDataPtr->bPixel,
                                                              BMPInput2->BMPHeaderDataPtr->biBitCount);
    }//��JBMP�e�׫D4������ ��0�ާ@ 
    
    int ImgHeight = BMPInput->BMPHeaderDataPtr->biHeight;
    int ImgWidth = BMPInput->BMPHeaderDataPtr->biWidth;
    int ImgHeight2 = BMPInput2->BMPHeaderDataPtr->biHeight;
    int ImgWidth2 = BMPInput2->BMPHeaderDataPtr->biWidth;
    //�ŧi�Ѽƫ��V��J�Ϥ��e�� 
    
    Create_BMP_DS_Set54Header(BMPLeftImg,ImgWidth,ImgHeight,8,1);
    Create_BMP_DS_Set54Header(BMPRightImg,ImgWidth2,ImgHeight2,8,1);
    //�гy���k�Ƕ��ϰO����Ŷ� 
    
    if(BMPInput->BMPHeaderDataPtr->biBitCount==24)
    {
        Img24CGTo8G(BMPInput,BMPLeftImg);
        Img24CGTo8G(BMPInput2,BMPRightImg);
    }//24bits��8bits�Ƕ� 
    else if(BMPInput->BMPHeaderDataPtr->biBitCount==8)
    {
        Img8CGTo8G(BMPInput,BMPLeftImg);
        Img8CGTo8G(BMPInput2,BMPRightImg);
    }//8bits��8bits�Ƕ� 
    
    sprintf(temp, "%s", Input_MPPS_Name);
    //�t���I����|+�ɦW 
    
    ReadMPPSet(temp,MPPS);
    //Ū���t���I���T 
    
    DrawImgMatching2(BMPLeftImg, BMPRightImg, BMPOutputImg, MPPS, StartingPoint, ColorDegreeSet_Ptr->LineColor_B, ColorDegreeSet_Ptr->LineColor_G, ColorDegreeSet_Ptr->LineColor_R);
    //����ø�s�t���I��u�q�禡 
    
    BMPOutputImg->BMPHeaderDataPtr->bPixel = bPiexl_0_Recovery(BMPOutputImg->BMPHeaderDataPtr->biWidth,
                                                               BMPOutputImg->BMPHeaderDataPtr->biHeight,
                                                               BMPOutputImg->BMPHeaderDataPtr->bPixel,
                                                               BMPOutputImg->BMPHeaderDataPtr->biBitCount);
    //BMP��0�禡 
    
    sprintf(temp, "%s", Output_BMP_Name);
    //��XBMP���|+�ɦW 
    
    Write_BMPImgFile(temp, BMPOutputImg);
    //��X�t���I��u�qBMP���� 
    
    BMP_DS_free(BMPInput);
    BMP_DS_free(BMPInput2);
    BMP_DS_free(BMPLeftImg);
    BMP_DS_free(BMPRightImg);
    BMP_DS_free(BMPOutputImg);
    Free_MPPSet(MPPS);
    //����O����Ŷ� 
    
    system("PAUSE");	
    return 0;
}
