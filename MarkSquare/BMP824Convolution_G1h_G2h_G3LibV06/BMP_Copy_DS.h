#include "BMP_Structure.h"

void Copy_BMP_DS(BMPDataStructure *BMPSource, BMPDataStructure *BMPCopies, int useLBflag);
void Copy_BMP_54Header(BMPDataStructure *BMPSource, BMPDataStructure *BMPCopies);
void Copy_BMP_ColorMap(BMPDataStructure *BMPSource, BMPDataStructure *BMPCopies);
void Copy_BMP_DataBlock(BMPDataStructure *BMPSource, BMPDataStructure *BMPCopies, int useLBflag);
