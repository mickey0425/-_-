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
    int LineColor_B; //�u�q�C�� B 
    int LineColor_G; //�u�q�C�� G 
	int LineColor_R; //�u�q�C�� R 
}ColorDegreeSet; //�C�⵲�c 
#endif

#ifndef PointSetStructure
#define PointSetStructure
typedef struct{
    unsigned char *ImgPtr;
    //���ɹ�����m���� 
    int ImgWidth;
    int ImgHeight;
    //�v���e�� 
    int SetSize;
    //���X�j�p=Point�Ӽ� 
    Point2D *PointSetPtr;
    // Point���� 
    char SetName[50];
    //���ɦW�� 
}PointSet;

typedef struct{
    int SetSize;
    //���X�j�p=Point�Ӽ� 
    Point2D *PointSetPtr1;
    // Point1���� 
    Point2D *PointSetPtr2;
    // Point2���� 
    float *Score;
}Point2DfPair;

typedef struct{
    PointSet *PS1;
    //�I���X1 
    PointSet *PS2;
    //�I���X2 
    int SetSize;
    //���X�j�p=�t���I��Ӽ� 
    int *PointNumber1;
    //�t���I1���� CS1��PointSetPtr���s�� 
    int *PointNumber2;
    //�t���I2���� CS2��PointSetPtr���s��
    float *Score;
    //similarity  Score
    Point2D *PointSetPtr1;  //���V���ϯS�x�I��r�ɤ����y���I  ������  
    Point2D *PointSetPtr2;  //���V�k�ϯS�x�I��r�ɤ����y���I  ������ 
    ColorDegreeSet *ColorDegreeSet_Ptr;  //���V�C�⵲�c������ 
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
