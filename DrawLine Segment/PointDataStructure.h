#include <stdio.h>
#ifndef PointStructure
#define PointStructure
typedef struct{
    int x;
    int y;  
}Point2D;

typedef struct{
    float x;
    float y;
    float z;  
}Point2Df;
#endif

#ifndef ColorDegreeSetStructure
#define ColorDegreeSetStructure
typedef struct{
    int LineColor_B; //線段顏色 B 
    int LineColor_G; //線段顏色 G 
	int LineColor_R; //線段顏色 R 
}ColorDegreeSet; //顏色結構 
#endif

#ifndef PointSetStructure
#define PointSetStructure
typedef struct{
    unsigned char *ImgPtr;
    //圖檔像素位置指標 
    int ImgWidth;
    int ImgHeight;
    //影像寬高 
    int SetSize;
    //集合大小=Point個數 
    Point2D *PointSetPtr;
    // Point指標 
    char SetName[50];
    //圖檔名稱 
}PointSet;

typedef struct{
    int SetSize;
    //集合大小=Point個數 
    Point2D *PointSetPtr1;
    // Point1指標 
    Point2D *PointSetPtr2;
    // Point2指標 
    float *Score;
}Point2DfPair;

typedef struct{
    PointSet *PS1;
    //點集合1 
    PointSet *PS2;
    //點集合2 
    int SetSize;
    //集合大小=配對點對個數 
    int *PointNumber1;
    //配對點1對應 CS1的PointSetPtr的編號 
    int *PointNumber2;
    //配對點2對應 CS2的PointSetPtr的編號
    float *Score;
    //similarity  Score
    Point2D *PointSetPtr1;  //指向左圖特徵點文字檔中的座標點  的指標  
    Point2D *PointSetPtr2;  //指向右圖特徵點文字檔中的座標點  的指標 
    ColorDegreeSet *ColorDegreeSet_Ptr;  //指向顏色結構的指標 
}MPPSet;
#endif
void MapToSet(int *map,int ImgWidth,int ImgHeight,PointSet *ps);
void printPointSet(char *filename,PointSet *PS);
void printMPPSet(char *filename,MPPSet *MPPS);
void ReadPointSet(char *SetName,PointSet *PS);
void ReadMPPSet(char *filename,MPPSet *MPPS);
void Copy_MPPSet(MPPSet *inMPPS,MPPSet *outMPPS);
void Create_MPPSet(MPPSet *MPPS,int SetSize);
void Free_MPPSet(MPPSet *MPPS);
