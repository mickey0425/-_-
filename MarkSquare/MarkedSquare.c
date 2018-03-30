#include "MarkedSquare.h"

void MarkedRectangle(int imgWidth, int imgHeight, unsigned char *GreyImgPtr, unsigned char *OutputImgPtr, PointSet *PS, int R1, int R2, char Blue, char Green, char Red)
{
    int i,j,m,n;    
    for(i=0;i<imgHeight;i++)
    {
        for(j=0;j<imgWidth;j++)
        {
            OutputImgPtr[j*3+i*imgWidth*3]=GreyImgPtr[j+i*imgWidth];
            OutputImgPtr[j*3+i*imgWidth*3+1]=GreyImgPtr[j+i*imgWidth];
            OutputImgPtr[j*3+i*imgWidth*3+2]=GreyImgPtr[j+i*imgWidth];  
        }
    }
    //將輸入複製到輸出 
    for(i=0;i< PS->SetSize;i++)
    {              
        for(m = -R2 ; m <= R2 ; m = m + 1)
            for(n = -R1 ; n <= R1 ; n = n + 1)
            {                                              
                if(((PS->PointSetPtr[i].y+m)>0 && (PS->PointSetPtr[i].y+m)<imgHeight && (PS->PointSetPtr[i].x+n)>0 && (PS->PointSetPtr[i].x+n)<imgWidth) && (m == R2 || m == -R2 || n == R1 || n == -R1))
                {    
                    OutputImgPtr[(PS->PointSetPtr[i].x+n)*3+(PS->PointSetPtr[i].y+m)*imgWidth*3]=Blue;
                    OutputImgPtr[(PS->PointSetPtr[i].x+n)*3+(PS->PointSetPtr[i].y+m)*imgWidth*3+1]=Green;
                    OutputImgPtr[(PS->PointSetPtr[i].x+n)*3+(PS->PointSetPtr[i].y+m)*imgWidth*3+2]=Red;
                }//當框線在距離角點5個像素時畫線，且此時不超出影像寬高範圍  
            }
    }        
}
/*
void MarkedCorner(int imgWidth ,int imgHeight,unsigned char *GreyImgPtr,
                  unsigned char *OutputImgPtr, int *CMapPtr,char Blue,char Green,char Red)
{
    int i,j,m,n,R=3;    
    for(i=0;i<imgHeight;i++)
    {
        for(j=0;j<imgWidth;j++)
        {
            OutputImgPtr[j*3+i*imgWidth*3]=GreyImgPtr[j+i*imgWidth];
            OutputImgPtr[j*3+i*imgWidth*3+1]=GreyImgPtr[j+i*imgWidth];
            OutputImgPtr[j*3+i*imgWidth*3+2]=GreyImgPtr[j+i*imgWidth];  
        }
    }
    //將輸入複製到輸出 
    for(i=0;i<imgHeight;i++)
        for(j=0;j<imgWidth;j++)
        {
            if(CMapPtr[j+i*imgWidth]>0)
            //當CMap中素質不等於0時標記角點 
            {                
                for(m=-R;m<=R;m=m+1)
                    for(n=-R;n<=R;n=n+1)
                    {                                              
                        if(((i+m)>0&&(i+m)<imgHeight&&(j+n)>0&&(j+n)<imgWidth*3)&&(m==R||m==-R||n==R||n==-R))
                        {    
                            OutputImgPtr[(j+n)*3+(i+m)*imgWidth*3]=Blue;
                            OutputImgPtr[(j+n)*3+(i+m)*imgWidth*3+1]=Green;
                            OutputImgPtr[(j+n)*3+(i+m)*imgWidth*3+2]=Red;
                        }//當框線在距離角點5個像素時畫線，且此時不超出影像寬高範圍  
                    }
            }        
        }    
}
void DrawLine(unsigned char *InputImgPtr,int imgWidth ,int imgHeight,
                  unsigned char *OutputImgPtr, int x, int d,char Blue,char Green,char Red)
{
    int i,j,m,n,R=5;    
    for(i=0;i<imgHeight;i++)
    {
        for(j=0;j<imgWidth;j++)
        {
            OutputImgPtr[j*3+i*imgWidth*3] = InputImgPtr[j*3+i*imgWidth*3];
            OutputImgPtr[j*3+i*imgWidth*3+1]=InputImgPtr[j*3+i*imgWidth*3+1];
            OutputImgPtr[j*3+i*imgWidth*3+2]=InputImgPtr[j*3+i*imgWidth*3+2];  
        }
    }
    //將輸入複製到輸出 
    for(i=0;i<imgHeight;i++)
    {
    if(x-d>0){
        OutputImgPtr[(x-d)*3+i*imgWidth*3] = Blue;;
        OutputImgPtr[(x-d)*3+i*imgWidth*3+1]=Green;
        OutputImgPtr[(x-d)*3+i*imgWidth*3+2]=Red;       
        }
    if(x+d<imgWidth){    
        OutputImgPtr[(x+d)*3+i*imgWidth*3] = Blue;;
        OutputImgPtr[(x+d)*3+i*imgWidth*3+1]=Green;
        OutputImgPtr[(x+d)*3+i*imgWidth*3+2]=Red;  
        }
    }    
}
*/
