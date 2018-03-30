#include "BMP_Structure.h"

void ReadBMPImgFileToDS(FILE				*BMPImgFilePtr1_4,
						char				*BMPFileName,
						BMPDataStructure	*BMPDataStructPtrR);
unsigned long ReadBMPFileAndInfo(FILE			*BMPImgFilePtr1,
								long			offset,
								int				ByteSize);
void ReadBMPHeaderDisplay(BMPHeaderData *BMPHeaderDataPtr);

void ReadBMPImg8bits(RGBQUAD *ColorMap, BMPHeaderData *BMPDataStructurePtrR2, FILE *BMPImgFilePtr2);
void ReadBMPImg8bitsColorMap(FILE *BMPImgFilePtr3, RGBQUAD *ColorMap);
void ReadBMPImg8bitsDataBlock(FILE *BMPImgFilePtr4, BMPHeaderData *BMPDataStructurePtr4);

void ReadBMPImg24bits(FILE *BMPImgFilePtr5, BMPHeaderData *BMPDataStructurePtr5);



