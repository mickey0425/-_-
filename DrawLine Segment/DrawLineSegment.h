#include "PointDataStructure.h"
#include "BMP_Structure.h"

void DrawImgMatching2(BMPDataStructure* LeftBMPImg, BMPDataStructure* RightBMPImg,  
                     BMPDataStructure* BMPOutputImg, MPPSet* MPPS ,Point2D* StartingPoint,unsigned char B,unsigned char G,unsigned char R);
void CombinedImage(BMPDataStructure* LeftBMPImg, BMPDataStructure* RightBMPImg, Point2D* StartingPoint, BMPDataStructure* BMPOutputImg);
void Paste_Img8to24(BMPDataStructure* BMPInput,int BeginX, int BeginY, BMPDataStructure* BMPOutput);
void DrawLine_MPPS(BMPDataStructure* BMPOutputImg, MPPSet* MPPS ,Point2D* StartingPoint,unsigned char B,unsigned char G,unsigned char R);
void DrawLine_2Points(BMPDataStructure* BMPOutputImg, Point2D* PointA ,Point2D* PointB,
                      unsigned char B,unsigned char G,unsigned char R);
