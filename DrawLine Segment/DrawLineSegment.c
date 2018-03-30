#include "DrawLineSegment.h"

void DrawImgMatching2(BMPDataStructure* LeftBMPImg, BMPDataStructure* RightBMPImg,  
                     BMPDataStructure* BMPOutputImg, MPPSet* MPPS ,
                     Point2D* StartingPoint,unsigned char B,unsigned char G,unsigned char R)
{    
    CombinedImage(LeftBMPImg, RightBMPImg, StartingPoint, BMPOutputImg);
    //呼叫 CombinedImage函式將左右兩張圖組合成一張 
    DrawLine_MPPS(BMPOutputImg , MPPS, StartingPoint, B, G, R);
    //根據MPPS在組合圖上繪製對應線段 
}
void CombinedImage(BMPDataStructure* LeftBMPImg, BMPDataStructure* RightBMPImg, 
                   Point2D* StartingPoint, BMPDataStructure* BMPOutputImg)
{
    int i,j,outImgHeight,outImgWidth;    
    outImgWidth = StartingPoint->x + RightBMPImg->BMPHeaderDataPtr->biWidth;
    outImgHeight = StartingPoint->y + RightBMPImg->BMPHeaderDataPtr->biHeight;    
    //計算合併影像寬高 
    Create_BMP_DS_Set54Header(BMPOutputImg , outImgWidth, outImgHeight,24,1);
    //創建合併影像記憶體空間 
    unsigned char* outPixel = BMPOutputImg->BMPHeaderDataPtr->bPixel;
    //宣告變數 outPixel指向輸出影像像素位置 
    for(i=0;i<outImgHeight;i++)
        for(j=0;j<outImgWidth*3;j++)        
            outPixel[j + i * outImgWidth*3] = 255; 
    //初始化成白色 
    Paste_Img8to24(LeftBMPImg, 0, 0, BMPOutputImg);
    //貼上左圖 
    Paste_Img8to24(RightBMPImg, StartingPoint->x, StartingPoint->y, BMPOutputImg);
    //貼上右圖 
}

void Paste_Img8to24(BMPDataStructure* BMPInput,int BeginX, int BeginY, BMPDataStructure* BMPOutput)
{//8bit影像貼至24bits影像 
    int i, j;
    int InImgHeight = BMPInput->BMPHeaderDataPtr->biHeight;
    int InImgWidth = BMPInput->BMPHeaderDataPtr->biWidth;
    //輸入圖寬高 
    int OutImgHeight = BMPOutput->BMPHeaderDataPtr->biHeight;
    int OutImgWidth = BMPOutput->BMPHeaderDataPtr->biWidth;
    //輸出圖寬高  
    unsigned char* inPixel = BMPInput->BMPHeaderDataPtr->bPixel;
    unsigned char* outPixel = BMPOutput->BMPHeaderDataPtr->bPixel;
    for(i=0;i<InImgHeight;i++)
    { 
        for(j=0;j<InImgWidth;j++)
        {            
            if(((j + BeginX) >= 0 && (j + BeginX) < OutImgWidth) 
            && ((i + BeginY) >= 0 && (i + BeginY) < OutImgHeight))
            {//當影像在範圍內 
                outPixel[(j + BeginX) * 3 + (i + BeginY) * OutImgWidth * 3] = inPixel[j+i*InImgWidth]; 
                outPixel[(j + BeginX) * 3 + (i + BeginY) * OutImgWidth * 3 + 1] = inPixel[j+i*InImgWidth]; 
                outPixel[(j + BeginX) * 3 + (i + BeginY) * OutImgWidth * 3 + 2] = inPixel[j+i*InImgWidth]; 
            }//貼上輸入影像像素 
        }
    }
}
void DrawLine_MPPS(BMPDataStructure* BMPOutputImg, MPPSet* MPPS ,Point2D* StartingPoint,
                   unsigned char B,unsigned char G,unsigned char R)
{
    int k;
    Point2D* tempPoint = (Point2D*)malloc(sizeof(Point2D)); 
    for(k = 0;k < MPPS->SetSize;k++)
    {//每一組MPPS畫線         
        tempPoint->x = StartingPoint->x + MPPS->PointSetPtr2[k].x;
        tempPoint->y = StartingPoint->y + MPPS->PointSetPtr2[k].y;      
        //計算右圖在結合影像上的座標          
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
    {//將BeginPoint指向 PointA,B中y座標較小的， EndPoint指向y座標較大的 
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
    // 計算x,y座標差距 
    unit_x = del_x / sqrtf(del_x * del_x + del_y * del_y);
    unit_y = del_y / sqrtf(del_x * del_x + del_y * del_y);
    //計算x,y方向向量 
        
    m = BeginPoint->x;
    n = BeginPoint->y;
    //紀錄起始點 
    while(n <= EndPoint->y )
    {//2點畫線 
        i = (int)roundf(n);
        j = (int)roundf(m);
        //四捨五入到整數座標 
        outPixel[(j+i*outImgWidth)*3] = B; 
        outPixel[(j+i*outImgWidth)*3 + 1] = G; 
        outPixel[(j+i*outImgWidth)*3 + 2] = R; 
        //畫線 
        m = m + unit_x;
        n = n + unit_y;
        //累加單位向量 
    }    
}
