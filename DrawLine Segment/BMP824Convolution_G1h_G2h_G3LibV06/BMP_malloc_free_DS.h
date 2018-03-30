#include "BMP_Structure.h"

void BMP_54Header_malloc(BMPDataStructure	*BMPDataStructPtrR);
void BMP_DS_free(BMPDataStructure	*BMPDataStructPtrR);
void Create_BMP_DS_Set54Header(BMPDataStructure	*BMPDataStructPtrC, int  imgWidth, int  imgHeight, int bitCount, int useflag);
void Set_BMP_54Header(BMPHeaderData	*BMPHeaderDataPtrC, int  imgWidth, int  imgHeight, int bitCount);
