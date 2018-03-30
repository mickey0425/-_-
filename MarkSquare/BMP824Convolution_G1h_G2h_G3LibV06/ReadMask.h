//ReadMask.h

typedef struct
{
	char MaskType[50];      //Mask類型 
	int MaskWidth;          //Mask寬 
	int MaskHeight;         //Mask高 
	float *MaskCoefficient; //Mask資料,一維陣列 
}MaskStructure;

void ReadMask(char filename[],MaskStructure *Maskdata);
//28-18行
void ReadShowMask(char filename[],MaskStructure *Maskdata);
//30-19行 
void ReadMaskHead(FILE *MaskFilePtr,MaskStructure *Maskdata);
//29-16行
void ReadMaskCoeff(FILE *MaskFilePtr,MaskStructure *Maskdata);
//37-23行 
void ShowMaskData(MaskStructure *Maskdata);
//15-14行
