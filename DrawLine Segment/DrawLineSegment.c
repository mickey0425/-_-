#include "DrawLineSegment.h"

void DrawImgMatching2(BMPDataStructure* LeftBMPImg, BMPDataStructure* RightBMPImg,  
                     BMPDataStructure* BMPOutputImg, MPPSet* MPPS ,
                     Point2D* StartingPoint,unsigned char B,unsigned char G,unsigned char R)
{    
    CombinedImage(LeftBMPImg, RightBMPImg, StartingPoint, BMPOutputImg);
    //�I�s CombinedImage�禡�N���k��i�ϲզX���@�i 
    DrawLine_MPPS(BMPOutputImg , MPPS, StartingPoint, B, G, R);
    //�ھ�MPPS�b�զX�ϤWø�s�����u�q 
}
void CombinedImage(BMPDataStructure* LeftBMPImg, BMPDataStructure* RightBMPImg, 
                   Point2D* StartingPoint, BMPDataStructure* BMPOutputImg)
{
    int i,j,outImgHeight,outImgWidth;    
    outImgWidth = StartingPoint->x + RightBMPImg->BMPHeaderDataPtr->biWidth;
    outImgHeight = StartingPoint->y + RightBMPImg->BMPHeaderDataPtr->biHeight;    
    //�p��X�ּv���e�� 
    Create_BMP_DS_Set54Header(BMPOutputImg , outImgWidth, outImgHeight,24,1);
    //�ЫئX�ּv���O����Ŷ� 
    unsigned char* outPixel = BMPOutputImg->BMPHeaderDataPtr->bPixel;
    //�ŧi�ܼ� outPixel���V��X�v��������m 
    for(i=0;i<outImgHeight;i++)
        for(j=0;j<outImgWidth*3;j++)        
            outPixel[j + i * outImgWidth*3] = 255; 
    //��l�Ʀ��զ� 
    Paste_Img8to24(LeftBMPImg, 0, 0, BMPOutputImg);
    //�K�W���� 
    Paste_Img8to24(RightBMPImg, StartingPoint->x, StartingPoint->y, BMPOutputImg);
    //�K�W�k�� 
}

void Paste_Img8to24(BMPDataStructure* BMPInput,int BeginX, int BeginY, BMPDataStructure* BMPOutput)
{//8bit�v���K��24bits�v�� 
    int i, j;
    int InImgHeight = BMPInput->BMPHeaderDataPtr->biHeight;
    int InImgWidth = BMPInput->BMPHeaderDataPtr->biWidth;
    //��J�ϼe�� 
    int OutImgHeight = BMPOutput->BMPHeaderDataPtr->biHeight;
    int OutImgWidth = BMPOutput->BMPHeaderDataPtr->biWidth;
    //��X�ϼe��  
    unsigned char* inPixel = BMPInput->BMPHeaderDataPtr->bPixel;
    unsigned char* outPixel = BMPOutput->BMPHeaderDataPtr->bPixel;
    for(i=0;i<InImgHeight;i++)
    { 
        for(j=0;j<InImgWidth;j++)
        {            
            if(((j + BeginX) >= 0 && (j + BeginX) < OutImgWidth) 
            && ((i + BeginY) >= 0 && (i + BeginY) < OutImgHeight))
            {//��v���b�d�� 
                outPixel[(j + BeginX) * 3 + (i + BeginY) * OutImgWidth * 3] = inPixel[j+i*InImgWidth]; 
                outPixel[(j + BeginX) * 3 + (i + BeginY) * OutImgWidth * 3 + 1] = inPixel[j+i*InImgWidth]; 
                outPixel[(j + BeginX) * 3 + (i + BeginY) * OutImgWidth * 3 + 2] = inPixel[j+i*InImgWidth]; 
            }//�K�W��J�v������ 
        }
    }
}
void DrawLine_MPPS(BMPDataStructure* BMPOutputImg, MPPSet* MPPS ,Point2D* StartingPoint,
                   unsigned char B,unsigned char G,unsigned char R)
{
    int k;
    Point2D* tempPoint = (Point2D*)malloc(sizeof(Point2D)); 
    for(k = 0;k < MPPS->SetSize;k++)
    {//�C�@��MPPS�e�u         
        tempPoint->x = StartingPoint->x + MPPS->PointSetPtr2[k].x;
        tempPoint->y = StartingPoint->y + MPPS->PointSetPtr2[k].y;      
        //�p��k�Ϧb���X�v���W���y��          
        DrawLine_2Points(BMPOutputImg, &MPPS->PointSetPtr1[k], tempPoint,  B, G, R);
    }
    free(tempPoint);
}
void DrawLine_2Points(BMPDataStructure* BMPOutputImg, Point2D* PointA ,Point2D* PointB,
                      unsigned char B,unsigned char G,unsigned char R)
{
    int i, j;
    float m, n, unit_x, unit_y, del_x, del_y;    
    int outImgHeight = BMPOutputImg->BMPHeaderDataPtr->biHeight;
    int outImgWidth = BMPOutputImg->BMPHeaderDataPtr->biWidth;
    unsigned char* outPixel = BMPOutputImg->BMPHeaderDataPtr->bPixel;
    Point2D* BeginPoint ;
    Point2D* EndPoint ;
    if(PointA->y < PointB->y)
    {//�NBeginPoint���V PointA,B��y�y�и��p���A EndPoint���Vy�y�и��j�� 
        BeginPoint = PointA;
        EndPoint = PointB;
    }
    else
    {
        BeginPoint = PointB;
        EndPoint = PointA;          
    }
    del_x = (float)EndPoint->x - BeginPoint->x;
    del_y = (float)EndPoint->y - BeginPoint->y;
    // �p��x,y�y�Юt�Z 
    unit_x = del_x / sqrtf(del_x * del_x + del_y * del_y);
    unit_y = del_y / sqrtf(del_x * del_x + del_y * del_y);
    //�p��x,y��V�V�q 
        
    m = BeginPoint->x;
    n = BeginPoint->y;
    //�����_�l�I 
    while(n <= EndPoint->y )
    {//2�I�e�u 
        i = (int)roundf(n);
        j = (int)roundf(m);
        //�|�ˤ��J���Ʈy�� 
        outPixel[(j+i*outImgWidth)*3] = B; 
        outPixel[(j+i*outImgWidth)*3 + 1] = G; 
        outPixel[(j+i*outImgWidth)*3 + 2] = R; 
        //�e�u 
        m = m + unit_x;
        n = n + unit_y;
        //�֥[���V�q 
    }    
}
