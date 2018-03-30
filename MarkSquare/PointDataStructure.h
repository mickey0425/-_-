#include <stdio.h>

#ifndef PointStructure
#define PointStructure
typedef struct{
    int x;
    int y;  
}Point2D;
#endif

#ifndef MarkRegionStructure
#define MarkRegionStructure
typedef struct{
    int Color_B;  
    int Color_G;  
	int Color_R;  
	int RegionWidth; //方框寬度 
	int RegionHeight; //方框高度 
}MarkRegion;
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
    Point2D *PointSetPtr1;
    Point2D *PointSetPtr2;
    
    MarkRegion *MarkRegion_Ptr; 
}MPPSet;
#endif

void MapToSet(int *map,int ImgWidth,int ImgHeight,PointSet *ps);
void printPointSet(char *filename,PointSet *PS);
void printMPPSet(char *filename,MPPSet *MPPS);
void ReadFeaturePoint(char *SetName,PointSet *PS);
void ReadMPPSet(char *filename,MPPSet *MPPS);
void Copy_MPPSet(MPPSet *inMPPS,MPPSet *outMPPS);
void Create_MPPSet(MPPSet *MPPS,int SetSize);
void Free_MPPSet(MPPSet *MPPS);
