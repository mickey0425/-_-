#include"PointDataStructure.h"

void ReadFeaturePoint(char *SetName,PointSet *PS)
{
    int i,j;
    FILE *fin=fopen(SetName,"r");
    while(fin == NULL){
         printf("%s is no such file\n",SetName); 
         printf("Please input PointSet file name:\n"); 
         scanf("%s",&SetName);
         fin = fopen(SetName,"r");
    }
    //如果檔案不存在的判斷,讓使用者重新輸入檔案名稱 
    //以上為確認檔案存在,之後由以下讀取資料 
    char Buffer[256];
    fgets(Buffer, 256, fin);
    fgets(Buffer, 256, fin);
    fgets(Buffer, 256, fin);
    //跳過前三行 
    fscanf(fin,"%d\n1",&PS->SetSize);
    PS->PointSetPtr = (Point2D*)malloc(sizeof(Point2D)*PS->SetSize);
    fgets(Buffer, 256, fin);
    //跳過第3行 
    for(i=0 ; i< PS->SetSize; i++)
    {
        fscanf(fin,"p%d = (%d,%d)\n", &j, &PS->PointSetPtr[i].x, &PS->PointSetPtr[i].y);
        /*
        printf("p%d = (%d,%d)\n", j, PS->PointSetPtr[i].x, PS->PointSetPtr[i].y);
        */
	}
    fclose(fin);
     
}

void Copy_MPPSet(MPPSet *inMPPS,MPPSet *outMPPS)
{
    int i;
    outMPPS->PS1 = inMPPS->PS1;
    outMPPS->PS2 = inMPPS->PS2;
    outMPPS->SetSize = inMPPS->SetSize;
    /*if(outMPPS->PointNumber1 == NULL)
        outMPPS->PointNumber1 = (int*)malloc(sizeof(int) * outMPPS->SetSize );
    if(outMPPS->PointNumber2 == NULL)
        outMPPS->PointNumber2 = (int*)malloc(sizeof(int) * outMPPS->SetSize );
    if(outMPPS->PointSetPtr1 == NULL)
        outMPPS->PointSetPtr1 = (Point2D*)malloc(sizeof(Point2D) * outMPPS->SetSize );
    if(outMPPS->PointSetPtr2 == NULL)
        outMPPS->PointSetPtr2 = (Point2D*)malloc(sizeof(Point2D) * outMPPS->SetSize );
    if(outMPPS->Score == NULL)
        outMPPS->Score = (float*)malloc(sizeof(float) * outMPPS->SetSize );*/
    for(i = 0 ; i< outMPPS->SetSize; i++)
    {
        outMPPS->PointNumber1[i] = inMPPS->PointNumber1[i];
        outMPPS->PointNumber2[i] = inMPPS->PointNumber2[i];
        outMPPS->PointSetPtr1[i].x = inMPPS->PointSetPtr1[i].x;
        outMPPS->PointSetPtr1[i].y = inMPPS->PointSetPtr1[i].y;
        outMPPS->PointSetPtr2[i].x = inMPPS->PointSetPtr2[i].x;
        outMPPS->PointSetPtr2[i].y = inMPPS->PointSetPtr2[i].y;
        outMPPS->Score[i] = inMPPS->Score[i];
    }
        
}
void Create_MPPSet(MPPSet *MPPS,int SetSize) 
{ 
    MPPS->PointNumber1 = (int*)malloc(sizeof(int) * SetSize );
    MPPS->PointNumber2 = (int*)malloc(sizeof(int) * SetSize );
    MPPS->PointSetPtr1 = (Point2D*)malloc(sizeof(Point2D) * SetSize );
    MPPS->PointSetPtr2 = (Point2D*)malloc(sizeof(Point2D) * SetSize );
    MPPS->Score = (float*)malloc(sizeof(float) * SetSize );
    MPPS->SetSize =SetSize;
} 
void Free_MPPSet(MPPSet *MPPS)
{
    //free(MPPS->PS1->PointSetPtr);
    //free(MPPS->PS2->PointSetPtr);
    free(MPPS->PointSetPtr1);
    free(MPPS->PointSetPtr2);
    free(MPPS->PointNumber1);
    free(MPPS->PointNumber2);    
    free(MPPS->Score);  
}
