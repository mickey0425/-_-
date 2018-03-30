#include "BMP_Structure.h"
#include "BMP_Copy_DS.h"


void Img24CGTo24G(BMPDataStructure *BMPInput, BMPDataStructure *BMPOutput);
void Img24CGTo8G(BMPDataStructure *BMPInput, BMPDataStructure *BMPOutput);
void Img8CGTo8G(BMPDataStructure *BMPInput, BMPDataStructure *BMPOutput);
void GenerateColorMap_GrayScale8bits(RGBQUAD *ColorMap);

