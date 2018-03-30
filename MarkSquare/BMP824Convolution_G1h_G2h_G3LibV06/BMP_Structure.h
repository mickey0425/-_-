
#define IMG_WIDTH	640
#define IMG_HEIGHT	480

#define BYTE		1
#define WORD		2
#define DWORD		4

#ifndef BMP_HEADER
#define BMP_HEADER
typedef struct
{
	unsigned long	bfType;
	unsigned long	bfSize;
	unsigned long	bfReserved1;
	unsigned long	bfReserved2;
	unsigned long	bfOffBits;

	unsigned long	biSize;
	long			biWidth;
	long			biHeight;
	unsigned long	biPlanes;
	unsigned long	biBitCount;

	unsigned long	biCompression;
	unsigned long	biSizeImage;
	unsigned long	biXPelsPerMeter;
	unsigned long	biYPelsPerMeter;
	unsigned long	biClrUsed;
	unsigned long	biClrImportant;

	unsigned char	*bPixel;
}BMPHeaderData;
#endif

#ifndef RGB
#define RGB
typedef struct
{
	int rgbBlue;
	int rgbGreen;
	int rgbRed;
	int reserved;
}RGBQUAD;
#endif

#ifndef BMP_DATA
#define BMP_DATA
typedef struct
{
	BMPHeaderData	*BMPHeaderDataPtr;
	RGBQUAD			*ColorMap;
	char			BMPFileName[50];
}BMPDataStructure;
#endif
