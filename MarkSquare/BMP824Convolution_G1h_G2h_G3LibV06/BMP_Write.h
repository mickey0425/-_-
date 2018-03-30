#include "BMP_Structure.h"

void WriteBMPImgDSToFile(FILE				*OutputFilePtr1_4,
						char				*BMPFileName,
						BMPDataStructure	*BMPDataStructPtrW1_4);
void WriteBMPFileAndInfo(long			offset,
					 	int				ByteSize,
						unsigned long	buf,
						FILE			*OutputFilePtr1);

void WriteBMP8bits(RGBQUAD *ColorMap, BMPHeaderData *BMPDataStructurePtrW2, FILE *OutputFilePtr2);
void WriteBMP8bitsColorMap(RGBQUAD *ColorMap, FILE *OutputFilePtr3);
void WriteBMP8bitsDataBlock(BMPHeaderData *BMPDataStructurePtrW4, FILE *OutputFilePtr4);

void WriteBMP24bits(FILE *OutputFilePtr5, BMPHeaderData *BMPDataStructurePtrW5);
